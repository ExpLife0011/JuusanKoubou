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
struct acui_information GMMSystem_cui_information = {
	_T("FrontWing"),		/* copyright */
	_T(""),					/* system */
	_T(".dat"),				/* package */
	_T("1.0.0"),			/* revision */
	_T("�պ�����"),			/* author */
	_T("2007-12-29 22:44"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_UNSTABLE
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	s8 magic[4];
	u32 index_entries;
} dat_header_t;

typedef struct {
	s8 name[64];
	u32 offset_lo;
	u32 offset_hi;
	u32 length_lo;
	u32 length_hi;
} dat_entry_t;
#pragma pack ()

#define SWAP8(v)	((((v) & 0xf0) >> 4) | (((v) & 0x0f) << 4))

static void decode(void *data, DWORD data_length, DWORD flag0, DWORD offset)
{
	BYTE *dat = (BYTE *)data;
	BYTE dec_tbl[10] = { 0xff, 0xff, 0xff, 0x01, 0x9c, 0xaa,
		0xa5, 0x00, 0x30, 0xff };
	int flag = 0;
	DWORD i;

	if (offset) {
		flag = 1;
	} else if (!(*dat & 0x80)) {
		if (!flag0)
			flag = 2;
	} else {
		flag = 1;
	}

	data_length += offset;
	if (flag == 1) {
		i = (offset & ~3) + 1;
		while (i < data_length) {
			if (i >= offset)
				dat[i - offset] = -dat[i - offset];
			i += 4;
		}
		i = (3 * offset) / 3;
		while (i < data_length) {
			if (i >= offset)
				dat[i - offset] ^= dec_tbl[((i / 5) % 5) + (i % 6)];
			i += 3;
		}
		i = ((6 * offset) / 6) + 2;
		while (i < data_length) {
			if (i >= offset)
				dat[i - offset] = SWAP8(dat[i - offset]);
			i += 6;
		}
	} else if (flag == 2) {
		i = ((6 * offset) / 6) + 2;
		while (i < data_length) {
			if (i >= offset)
				dat[i - offset] = SWAP8(dat[i - offset]);
			i += 6;
		}
		i = 3 * offset / 3;
		while (i < data_length) {
			if (i >= offset)
				dat[i - offset] ^= dec_tbl[((i / 5) % 5) + (i % 6)];
			i += 3;
		}
		i = 4 * (offset >> 2) + 1;
		while (i < data_length) {
			if (i >= offset)
				dat[i - offset] = -dat[i - offset];
			i += 4;
		}
	}
}

/********************* dat *********************/

/* ���ƥ��ص����� */
static int GMMSystem_dat_match(struct package *pkg)
{
	if (!pkg)
		return -CUI_EPARA;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int GMMSystem_dat_extract_directory(struct package *pkg,
										struct package_directory *pkg_dir)
{
	dat_entry_t *index_buffer;
	u32 index_entries;
	DWORD index_buffer_length;	
	BYTE *p;

	if (!pkg || !pkg_dir)
		return -CUI_EPARA;

	if (pkg->pio->readvec(pkg, &index_entries, 4, -4, IO_SEEK_END))
		return -CUI_EREADVEC;

	index_buffer_length = index_entries * sizeof(dat_entry_t);
	index_buffer = (dat_entry_t *)malloc(index_buffer_length);
	if (!index_buffer)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, index_buffer, index_buffer_length, 
			0 - (index_buffer_length + 4), IO_SEEK_END)) {
		free(index_buffer);
		return -CUI_EREADVEC;
	}

	p = (BYTE *)index_buffer;
	for (DWORD i = 0; i < index_buffer_length; i++)
		p[i] = SWAP8(p[i]);

	pkg_dir->index_entries = index_entries;
	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_length;
	pkg_dir->index_entry_length = sizeof(dat_entry_t);

	return 0;
}

/* ���������������� */
static int GMMSystem_dat_parse_resource_info(struct package *pkg,
											 struct package_resource *pkg_res)
{
	dat_entry_t *dat_entry;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	dat_entry = (dat_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, dat_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = dat_entry->length_lo;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = dat_entry->offset_lo;

	return 0;
}

/* �����Դ��ȡ���� */
static int GMMSystem_dat_extract_resource(struct package *pkg,
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

	decode(pkg_res->raw_data, pkg_res->raw_data_length, 0, 0);

	return 0;
}

/* ��Դ���溯�� */
static int GMMSystem_dat_save_resource(struct resource *res, 
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
static void GMMSystem_dat_release_resource(struct package *pkg, 
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
static void GMMSystem_dat_release(struct package *pkg, 
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
static cui_ext_operation GMMSystem_dat_operation = {
	GMMSystem_dat_match,				/* match */
	GMMSystem_dat_extract_directory,	/* extract_directory */
	GMMSystem_dat_parse_resource_info,	/* parse_resource_info */
	GMMSystem_dat_extract_resource,		/* extract_resource */
	GMMSystem_dat_save_resource,		/* save_resource */
	GMMSystem_dat_release_resource,		/* release_resource */
	GMMSystem_dat_release				/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK GMMSystem_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".dat"), NULL, 
		NULL, &GMMSystem_dat_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR| CUI_EXT_FLAG_NO_MAGIC))
			return -1;

	return 0;
}
