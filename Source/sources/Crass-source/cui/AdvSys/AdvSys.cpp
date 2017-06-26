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
struct acui_information AdvSys_cui_information = {
	NULL,					/* copyright */
	NULL,					/* system */
	_T(".dat"),				/* package */
	_T("0.4.1"),			/* revision */
	_T("�՝h���\"),			/* author */
	_T(""),					/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_DEVELOP
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	u32 index_entries;
} dat_head_header_t;

typedef struct {
	u32 seq;
	u32 data_offset;		// �����ڷ���ڵ�ƫ��
	u32 data_length;		// ���������ײ���Ϣ
	u16 arc_id;				// exp: arc.dat: 0, arca.dat: 1, arcb.dat: 2, arcc.dat: 3, arcd.dat: 4,
} dat_head_entry_t;

typedef struct {
	u32 data_length;		// ���������ײ���Ϣ
	u32 seq;
	u16 name_length;
//	u8 *name;
} dat_header_t;

typedef struct {
	u32 length;		// ���������ײ���Ϣ
	s8 magic[3];	// "GWD"
	u16 width;
	u16 height;
	u8 bpp;

} GWD_header_t;
#pragma pack ()

typedef struct {
	char name[MAX_PATH];
	DWORD name_length;
	DWORD offset;
	DWORD length;
} my_dat_entry_t;

/********************* dat *********************/

/* ���ƥ��ص����� */
static int AdvSys_dat_match(struct package *pkg)
{
	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->open(pkg->lst, IO_READONLY)) {
		pkg->pio->close(pkg);
		return -CUI_EOPEN;
	}

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int AdvSys_dat_extract_directory(struct package *pkg,
										struct package_directory *pkg_dir)
{
	dat_head_header_t dat_head;

	if (pkg->pio->read(pkg->lst, &dat_head, sizeof(dat_head)))
		return -CUI_EREAD;

	dat_head_entry_t *dat_head_entry = (dat_head_entry_t *)malloc(dat_head.index_entries * sizeof(dat_head_entry_t));
	if (!dat_head_entry)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg->lst, dat_head_entry, dat_head.index_entries * sizeof(dat_head_entry_t))) {
		free(dat_head_entry);
		return -CUI_EREAD;
	}

	DWORD index_buffer_len = dat_head.index_entries * sizeof(my_dat_entry_t);
	my_dat_entry_t *index_buffer = (my_dat_entry_t *)malloc(index_buffer_len);
	if (!index_buffer) {
		free(dat_head_entry);
		return -CUI_EMEM;
	}

	int over = 0;
	for (DWORD k = 0; ; k++) {
		my_dat_entry_t *my_dat_entry = &index_buffer[k];
		u32 seq;
		u16 name_length;

		if (pkg->pio->read(pkg, &my_dat_entry->length, 4))
			break;

		if (!my_dat_entry->length) {
			over = 1;
			break;
		}

		if (pkg->pio->read(pkg, &seq, 4))
			break;

		if (pkg->pio->read(pkg, &name_length, 2))
			break;

		if (pkg->pio->read(pkg, &my_dat_entry->name, name_length))
			break;

		if (pkg->pio->seek(pkg, my_dat_entry->length, IO_SEEK_CUR))
			break;

		my_dat_entry->name_length = name_length;
		my_dat_entry->name[name_length] = 0;
	
		for (DWORD i = 0; i < dat_head.index_entries; i++) {
			if (dat_head_entry[i].seq == seq)
				break;
		}
		if (i == dat_head.index_entries) {
			free(index_buffer);
			free(dat_head_entry);
			return -CUI_EMATCH;
		}

		my_dat_entry->offset = dat_head_entry[i].data_offset;
	}
	free(dat_head_entry);
	if (!over) {
		free(index_buffer);
		return -CUI_EREAD;
	}

	pkg_dir->index_entries = k;
	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = k * sizeof(my_dat_entry_t);
	pkg_dir->index_entry_length = sizeof(my_dat_entry_t);

	return 0;
}

/* ���������������� */
static int AdvSys_dat_parse_resource_info(struct package *pkg,
										  struct package_resource *pkg_res)
{
	my_dat_entry_t *my_dat_entry;

	my_dat_entry = (my_dat_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, my_dat_entry->name);
	pkg_res->name_length = my_dat_entry->name_length;
	pkg_res->raw_data_length = my_dat_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = my_dat_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int AdvSys_dat_extract_resource(struct package *pkg,
									   struct package_resource *pkg_res)
{
	char *p;

	pkg_res->raw_data = malloc(pkg_res->raw_data_length);
	if (!pkg_res->raw_data)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, pkg_res->raw_data, pkg_res->raw_data_length,
		pkg_res->offset, IO_SEEK_SET)) {
			free(pkg_res->raw_data);
			pkg_res->raw_data = NULL;
			return -CUI_EREADVEC;
	}

	p = (char *)pkg_res->raw_data;
	if (!memcmp(p, "RIFF", 4)) {
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
		pkg_res->replace_extension = _T(".wav");
	}

	return 0;
}

/* ��Դ���溯�� */
static int AdvSys_dat_save_resource(struct resource *res, 
									struct package_resource *pkg_res)
{
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
static void AdvSys_dat_release_resource(struct package *pkg, 
										struct package_resource *pkg_res)
{
	if (pkg_res->raw_data) {
		free(pkg_res->raw_data);
		pkg_res->raw_data = NULL;
	}
}

/* ���ж�غ��� */
static void AdvSys_dat_release(struct package *pkg, 
							   struct package_directory *pkg_dir)
{
	if (pkg_dir->directory) {
		free(pkg_dir->directory);
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg->lst);
	pkg->pio->close(pkg);
}

/* �������ص��������� */
static cui_ext_operation AdvSys_dat_operation = {
	AdvSys_dat_match,					/* match */
	AdvSys_dat_extract_directory,		/* extract_directory */
	AdvSys_dat_parse_resource_info,		/* parse_resource_info */
	AdvSys_dat_extract_resource,		/* extract_resource */
	AdvSys_dat_save_resource,			/* save_resource */
	AdvSys_dat_release_resource,		/* release_resource */
	AdvSys_dat_release					/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK AdvSys_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".dat"), NULL, 
		NULL, &AdvSys_dat_operation, CUI_EXT_FLAG_PKG 
		| CUI_EXT_FLAG_DIR | CUI_EXT_FLAG_LST | CUI_EXT_FLAG_NO_MAGIC))
			return -1;

	return 0;
}
