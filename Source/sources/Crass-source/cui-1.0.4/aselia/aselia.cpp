#include <windows.h>
#include <tchar.h>
#include <crass_types.h>
#include <acui.h>
#include <cui.h>
#include <package.h>
#include <resource.h>
#include <cui_error.h>
#include <stdio.h>

/* �ӿ����ݽṹ: ��ʾcui�����һ����Ϣ */
struct acui_information aselia_cui_information = {
	_T("�����������|�졿(Xuse)"),	/* copyright */
	NULL,					/* system */
	_T(".gd"),				/* package */
	_T("1.0.0"),			/* revision */
	_T("籲�΢��"),			/* author */
	_T("2008-2-7 18:37"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_STABLE
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	u32 index_entries;		/* ���ɿ� */
} gd_header_t;

typedef struct {
	u32 unknown;			/* �ƺ�������index_entries���������Ӷ����� */
} dll_header_t;

typedef struct {
	u32 offset;
	u32 length;
} dll_entry_t;
#pragma pack ()

typedef struct {
	s8 name[MAX_PATH];
	u32 offset;
	u32 length;
} my_dll_entry_t;

/********************* gd *********************/

/* ���ƥ��ص����� */
static int aselia_gd_match(struct package *pkg)
{
	if (!pkg)
		return -CUI_EPARA;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->open(pkg->lst, IO_READONLY)) {
		pkg->pio->close(pkg);
		return -CUI_EOPEN;
	}

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int aselia_gd_extract_directory(struct package *pkg,
									   struct package_directory *pkg_dir)
{
	gd_header_t gd_header;
	dll_header_t dll_header;
	SIZE_T dll_size;

	if (!pkg || !pkg->lst || !pkg_dir)
		return -CUI_EPARA;

	if (pkg->pio->length_of(pkg->lst, &dll_size))
		return -CUI_ELEN;

	dll_size -= 4;
	DWORD index_entries = dll_size / sizeof(dll_entry_t);

	if (pkg->pio->read(pkg, &gd_header, sizeof(gd_header)))
		return -CUI_EREAD;

	if (pkg->pio->read(pkg->lst, &dll_header, sizeof(dll_header)))
		return -CUI_EREAD;
	
	DWORD index_buffer_length = index_entries * sizeof(dll_entry_t);
	dll_entry_t *index_buffer = (dll_entry_t *)malloc(index_buffer_length);
	if (!index_buffer)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg->lst, index_buffer, index_buffer_length))
		return -CUI_EREAD;

	DWORD my_index_buffer_length = index_entries * sizeof(my_dll_entry_t);
	my_dll_entry_t *my_index_buffer = (my_dll_entry_t *)malloc(my_index_buffer_length);
	if (!my_index_buffer) {
		free(index_buffer);
		return -CUI_EMEM;
	}

	for (DWORD i = 0; i < index_entries; i++) {
		my_dll_entry_t *entry = &my_index_buffer[i];

		sprintf(entry->name, "%08d", i);
		entry->offset = index_buffer[i].offset;
		entry->length = index_buffer[i].length;		
	}
	free(index_buffer);

	pkg_dir->index_entries = index_entries;
	pkg_dir->directory = my_index_buffer;
	pkg_dir->directory_length = my_index_buffer_length;
	pkg_dir->index_entry_length = sizeof(my_dll_entry_t);
	//pkg_dir->flags = PKG_DIR_FLAG_SKIP0;

	return 0;
}

/* ���������������� */
static int aselia_gd_parse_resource_info(struct package *pkg,
										 struct package_resource *pkg_res)
{
	my_dll_entry_t *my_dll_entry;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	my_dll_entry = (my_dll_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, my_dll_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = my_dll_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = my_dll_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int aselia_gd_extract_resource(struct package *pkg,
									  struct package_resource *pkg_res)
{
	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	pkg_res->raw_data = malloc(pkg_res->raw_data_length);
	if (!pkg_res->raw_data)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, pkg_res->raw_data, pkg_res->raw_data_length,
		pkg_res->offset, IO_SEEK_SET)) {
			free(pkg_res->raw_data);
			pkg_res->raw_data = NULL;
			return -CUI_EREADVEC;
	}

	if (!strncmp((char *)pkg_res->raw_data, "\x89PNG", 4)) {
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
		pkg_res->replace_extension = _T(".png");
	} else if (!strncmp((char *)pkg_res->raw_data, "OggS", 4)) {
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
		pkg_res->replace_extension = _T(".ogg");
	} else if (!strncmp((char *)pkg_res->raw_data, "BM", 2)) {
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
		pkg_res->replace_extension = _T(".bmp");
	} else if (!lstrcmp(pkg->name, _T("data05.gd")) || !lstrcmp(pkg->name, _T("data07.gd"))) {
		DWORD count = pkg_res->raw_data_length / 4;
		u32 *dec = (u32 *)pkg_res->raw_data;

		for (DWORD i = 0; i < count; i++)
			dec[i] ^= 0x515151;

		dec += count;
		count = pkg_res->raw_data_length - count * 4;
		for (i = 0; i < count; i++)
			((BYTE *)dec)[i] ^= 0x51;
	}

	return 0;
}

/* ��Դ���溯�� */
static int aselia_gd_save_resource(struct resource *res, 
								   struct package_resource *pkg_res)
{
	if (!res || !pkg_res)
		return -CUI_EPARA;
	
	if (res->rio->create(res))
		return -CUI_ECREATE;

	if (pkg_res->raw_data && pkg_res->raw_data_length) {
		if (res->rio->write(res, pkg_res->raw_data, pkg_res->raw_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	}

	res->rio->close(res);
	
	return 0;
}

/* �����Դ�ͷź��� */
static void aselia_gd_release_resource(struct package *pkg, 
									   struct package_resource *pkg_res)
{
	if (!pkg || !pkg_res)
		return;

	if (pkg_res->raw_data) {
		free(pkg_res->raw_data);
		pkg_res->raw_data = NULL;
	}
}

/* ���ж�غ��� */
static void aselia_gd_release(struct package *pkg, 
							  struct package_directory *pkg_dir)
{
	if (!pkg || !pkg_dir)
		return;

	if (pkg_dir->directory) {
		free(pkg_dir->directory);
		pkg_dir->directory = NULL;
	}
	pkg->pio->close(pkg->lst);
	pkg->pio->close(pkg);
}

/* �������ص��������� */
static cui_ext_operation aselia_gd_operation = {
	aselia_gd_match,				/* match */
	aselia_gd_extract_directory,	/* extract_directory */
	aselia_gd_parse_resource_info,	/* parse_resource_info */
	aselia_gd_extract_resource,		/* extract_resource */
	aselia_gd_save_resource,		/* save_resource */
	aselia_gd_release_resource,		/* release_resource */
	aselia_gd_release				/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK aselia_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".gd"), NULL, 
		NULL, &aselia_gd_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR | CUI_EXT_FLAG_LST | CUI_EXT_FLAG_WEAK_MAGIC))
			return -1;

	return 0;
}
