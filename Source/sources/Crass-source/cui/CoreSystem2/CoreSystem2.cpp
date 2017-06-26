#include <windows.h>
#include <tchar.h>
#include <crass_types.h>
#include <acui.h>
#include <cui.h>
#include <package.h>
#include <resource.h>
#include <cui_error.h>
#include <stdio.h>
#include <zlib.h>

/* �ӿ����ݽṹ: ��ʾcui�����һ����Ϣ */
struct acui_information CoreSystem2_cui_information = {
	_T("Kyoya Yuro"),		/* copyright */
	_T("����"),			/* system */
	_T(".int"),				/* package */
	_T("1.0.0"),			/* revision */
	_T("�պ�����"),			/* author */
	_T("2007-3-24 10:12"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_STABLE | ACUI_ATTRIBUTE_PRELOAD
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	s8 magic[4];		// "KIF"
	u32 index_entries;
} int_header_t;

typedef struct {
	s8 name[32];
	u32 offset;
	u32 length;
} int_entry_t;

typedef struct {
	s8 magic[8];		// "CatScene"
	u32 comprlen;
	u32 uncomprlen;
} cst_header_t;

typedef struct {
	s8 magic[4];		// "HG-2"
	u32 data_offset or header_length;
	u32 ??;		// 0x10
	u32 width;
	u32 height;
	u32 clor_depth;
	u32 zero;
	u32 zero;
} hg2_header_t;
#pragma pack ()

/********************* int *********************/

/* ���ƥ��ص����� */
static int CoreSystem2_int_match(struct package *pkg)
{
	s8 magic[4];

	if (!pkg)
		return -CUI_EPARA;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->read(pkg, magic, sizeof(magic))) {
		pkg->pio->close(pkg);
		return -CUI_EREAD;
	}

	if (strncmp(magic, "KIF", 4)) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;	
	}

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int CoreSystem2_int_extract_directory(struct package *pkg,
											 struct package_directory *pkg_dir)
{
	int_entry_t *index_buffer;
	DWORD index_buffer_length;	

	if (!pkg || !pkg_dir)
		return -CUI_EPARA;

	if (pkg->pio->read(pkg, &pkg_dir->index_entries, 4))
		return -CUI_EREAD;

	index_buffer_length = pkg_dir->index_entries * sizeof(int_entry_t);
	index_buffer = (int_entry_t *)malloc(index_buffer_length);
	if (!index_buffer)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg, index_buffer, index_buffer_length)) {
		free(index_buffer);
		return -CUI_EREAD;
	}

	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_length;
	pkg_dir->index_entry_length = sizeof(int_entry_t);

	return 0;
}

/* ���������������� */
static int CoreSystem2_int_parse_resource_info(struct package *pkg,
											   struct package_resource *pkg_res)
{
	int_entry_t *int_entry;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	int_entry = (int_entry_t *)pkg_res->actual_index_entry;
	_snprintf(pkg_res->name, 16, int_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = int_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = int_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int CoreSystem2_int_extract_resource(struct package *pkg,
											struct package_resource *pkg_res)
{
	BYTE *compr, *uncompr;
	DWORD comprlen, uncomprlen;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	comprlen = pkg_res->raw_data_length;
	compr = (BYTE *)malloc(comprlen);
	if (!compr)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, compr, comprlen, pkg_res->offset, IO_SEEK_SET)) {
		free(compr);
		return -CUI_EREADVEC;
	}

	if (!strncmp((char *)compr, "CatScene", 8)) {
		cst_header_t *cst_header = (cst_header_t *)compr;

		uncomprlen = cst_header->uncomprlen;
		uncompr = (BYTE *)malloc(uncomprlen);
		if (!uncompr) {
			free(compr);
			return -CUI_EMEM;		
		}

		if (uncompress(uncompr, &uncomprlen, (BYTE *)(cst_header + 1), cst_header->comprlen) != Z_OK) {
			free(uncompr);
			free(compr);
			return -CUI_EUNCOMPR;
		}
		if (uncomprlen != cst_header->uncomprlen) {
			free(uncompr);
			free(compr);
			return -CUI_EUNCOMPR;
		}
	} if (!strncmp((char *)compr, "KCS", 4)) {
		if (*(u32 *)(compr + 0xc) == 0x34) {
			DWORD act_uncomprlen;

			uncomprlen = *(u32 *)(compr + 0x28);
			uncompr = (BYTE *)malloc(uncomprlen);
			if (!uncompr) {
				free(compr);
				return -CUI_EMEM;		
			}

			act_uncomprlen = uncomprlen - 0x34;
			if (uncompress(uncompr + 0x34, &act_uncomprlen, compr + 0x34, comprlen - 0x34) != Z_OK) {
				free(uncompr);
				free(compr);
				return -CUI_EUNCOMPR;
			}
			if (act_uncomprlen != uncomprlen - 0x34) {
				free(uncompr);
				free(compr);
				return -CUI_EUNCOMPR;
			}
			memcpy(uncompr, compr, 0x34);
		} else if (*(u32 *)(compr + 0xc) == 0x30) {
			uncompr = NULL;
			uncomprlen = 0;		
		} else {
			free(compr);
			return -CUI_EMATCH;
		}
	} if (!strncmp((char *)compr, "HG-2", 4)) {

	} else {
		uncompr = NULL;
		uncomprlen = 0;
	}

	pkg_res->raw_data = compr;
	pkg_res->actual_data = uncompr;
	pkg_res->actual_data_length = uncomprlen;

	return 0;
}

/* ��Դ���溯�� */
static int CoreSystem2_int_save_resource(struct resource *res, 
										 struct package_resource *pkg_res)
{
	if (!res || !pkg_res)
		return -CUI_EPARA;
	
	if (res->rio->create(res))
		return -CUI_ECREATE;

	if (pkg_res->actual_data && pkg_res->actual_data_length) {
		if (res->rio->write(res, pkg_res->actual_data, pkg_res->actual_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	} else if (pkg_res->raw_data && pkg_res->raw_data_length) {
		if (res->rio->write(res, pkg_res->raw_data, pkg_res->raw_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	}

	res->rio->close(res);
	
	return 0;
}

/* �����Դ�ͷź��� */
static void CoreSystem2_int_release_resource(struct package *pkg, 
											 struct package_resource *pkg_res)
{
	if (!pkg || !pkg_res)
		return;

	if (pkg_res->actual_data) {
		free(pkg_res->actual_data);
		pkg_res->actual_data = NULL;
	}
	if (pkg_res->raw_data) {
		free(pkg_res->raw_data);
		pkg_res->raw_data = NULL;
	}
}

/* ���ж�غ��� */
static void CoreSystem2_int_release(struct package *pkg, 
									struct package_directory *pkg_dir)
{
	if (!pkg || !pkg_dir)
		return;

	if (pkg_dir->directory) {
		free(pkg_dir->directory);
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg);
}

/* �������ص��������� */
static cui_ext_operation CoreSystem2_int_operation = {
	CoreSystem2_int_match,					/* match */
	CoreSystem2_int_extract_directory,		/* extract_directory */
	CoreSystem2_int_parse_resource_info,	/* parse_resource_info */
	CoreSystem2_int_extract_resource,		/* extract_resource */
	CoreSystem2_int_save_resource,			/* save_resource */
	CoreSystem2_int_release_resource,		/* release_resource */
	CoreSystem2_int_release					/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK CoreSystem2_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".int"), NULL, 
		NULL, &CoreSystem2_int_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
