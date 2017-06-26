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
struct acui_information CLS_cui_information = {
	_T("Kyoya Yuro"),		/* copyright */
	_T("����"),			/* system */
	_T(".dat .dmf .la"),	/* package */
	_T("1.0.2"),			/* revision */
	_T("�՝h���\"),			/* author */
	_T("2008-11-2 22:08"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_STABLE
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	s8 magic[16];	// "CLS_FILELINK"
	u32 index_entries;
	u32 reserved1;
	u32 index_offset;
	u32 data_offset;
	u32 reserved[8];
} dat_header_t;

/* .dat�����������ṹ */
typedef struct {
	s8 name[40];
	u8 unknown0;
	u8 unknown1;
	u16 flags;
	u32 offset;
	u32 length;
	u32 reserved[3];
} dat_entry_t;

typedef struct {
	s8 magic[16];	// "CLS_TEXFILE"
	u32 frames;
	u32 frame_info_offset;
	u32 frame_data_offset;
	u32 file_size;
} tex_header_t;

typedef struct {
	u32 frame_data_offset;
	u32 frame_data_length;	
	u32 reserved[2];
} tex_info_t;

typedef struct {
	u32 unknown0;
	u16 must_be_1;	

} tex_data_header_t;
#pragma pack ()


/********************* dat *********************/

/* ���ƥ��ص����� */
static int CLS_dat_match(struct package *pkg)
{
	s8 magic[12];

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->read(pkg, magic, sizeof(magic))) {
		pkg->pio->close(pkg);
		return -CUI_EREAD;
	}

	if (strncmp(magic, "CLS_FILELINK", 12)) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;	
	}

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int CLS_dat_extract_directory(struct package *pkg,
									 struct package_directory *pkg_dir)
{
	dat_header_t header;

	if (pkg->pio->readvec(pkg, &header, sizeof(header), 0, IO_SEEK_SET))
		return -CUI_EREADVEC;

	DWORD index_buffer_length = header.index_entries * sizeof(dat_entry_t);
	dat_entry_t *index_buffer = new dat_entry_t[header.index_entries];
	if (!index_buffer)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg, index_buffer, index_buffer_length)) {
		delete [] index_buffer;
		return -CUI_EREAD;
	}

	pkg_dir->index_entries = header.index_entries;
	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_length;
	pkg_dir->index_entry_length = sizeof(dat_entry_t);
	//pkg_dir->flags = PKG_DIR_FLAG_SKIP0;

	return 0;
}

/* ���������������� */
static int CLS_dat_parse_resource_info(struct package *pkg,
									   struct package_resource *pkg_res)
{
	dat_entry_t *dat_entry;

	dat_entry = (dat_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, dat_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = dat_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = dat_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int CLS_dat_extract_resource(struct package *pkg,
									struct package_resource *pkg_res)
{
	BYTE *raw = new BYTE[pkg_res->raw_data_length];
	if (!raw)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, raw, pkg_res->raw_data_length,
		pkg_res->offset, IO_SEEK_SET)) {
			delete [] raw;
			return -CUI_EREADVEC;
	}

	if (!strncmp((char *)raw, "OggS", 4)) {
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
		pkg_res->replace_extension = _T(".ogg");
	}

	pkg_res->raw_data = raw;

	return 0;
}

/* ��Դ���溯�� */
static int CLS_dat_save_resource(struct resource *res, 
								 struct package_resource *pkg_res)
{
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
static void CLS_dat_release_resource(struct package *pkg, 
									 struct package_resource *pkg_res)
{
	if (pkg_res->actual_data) {
		delete [] pkg_res->actual_data;
		pkg_res->actual_data = NULL;
	}
	if (pkg_res->raw_data) {
		delete [] pkg_res->raw_data;
		pkg_res->raw_data = NULL;
	}
}

/* ���ж�غ��� */
static void CLS_dat_release(struct package *pkg, 
							struct package_directory *pkg_dir)
{
	if (pkg_dir->directory) {
		delete [] pkg_dir->directory;
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg);
}

/* �������ص��������� */
static cui_ext_operation CLS_dat_operation = {
	CLS_dat_match,					/* match */
	CLS_dat_extract_directory,		/* extract_directory */
	CLS_dat_parse_resource_info,	/* parse_resource_info */
	CLS_dat_extract_resource,		/* extract_resource */
	CLS_dat_save_resource,			/* save_resource */
	CLS_dat_release_resource,		/* release_resource */
	CLS_dat_release					/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK CLS_register_cui(struct cui_register_callback *callback)
{
	if (callback->add_extension(callback->cui, _T(".DAT"), NULL, 
		NULL, &CLS_dat_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
