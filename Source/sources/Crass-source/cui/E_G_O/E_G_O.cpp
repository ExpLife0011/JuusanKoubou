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
struct acui_information E_G_O_cui_information = {
	_T("Kyoya Yuro"),		/* copyright */
	_T("����"),			/* system */
	_T(".lax"),				/* package */
	_T("1.0.0"),			/* revision */
	_T("�պ�����"),			/* author */
	_T("2007-3-24 10:12"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_STABLE
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	s8 magic[8];	// "$LapH__"

} lax_header_t;

// 0x28 bytes
typedef struct {
	s8 magic[8];	// "$LapI__"
	u32 ?;
	u32 ?;
	u32 index_offset;
	u32 uncomprlen;
	u32 comprlen;
} lax_tailer_t;

// ���Ƚ������ѹ���ж��ڽ�ѹ�����Ƿ�Ϊ0�����ǵĻ��ٽ����ڽ�ѹ
typedef struct {
	s8 magic[4];	// "_AF1"��lzss�� or "_AF2" or "_AF����"
	u16 comprlen;	// ��ѹ������
	u16 uncomprlen1;// �ڽ�ѹ����
	u16 uncomprlen0;// ���ѹ����
} _af_tailer_t;
#pragma pack ()

/* .dat�����������ṹ */
typedef struct {
	s8 name[256];
	u32 name_length;
	u32 offset;
	u32 length;
} dat_entry_t;

static void lzss_decompress(BYTE *uncompr, DWORD uncomprlen, 
							 BYTE *compr, DWORD comprlen)
{
	unsigned int act_uncomprlen = 0;
	/* compr�еĵ�ǰ�ֽ��е���һ��ɨ��λ��λ�� */
	unsigned int curbit = 0;
	/* compr�еĵ�ǰɨ���ֽ� */
	unsigned int curbyte = 0;
	unsigned int nCurWindowByte = 0xfee;
	unsigned int win_size = 4096;
	BYTE win[4096];
	WORD flag = 0;

	memset(win, 0, nCurWindowByte);
	while (1) {
		flag >>= 1;
		if (!(flag & 0x0100))
			flag = compr[curbyte++] | 0xff00;
		if (flag & 1) {
			unsigned char data;

			data = compr[curbyte++];
			uncompr[act_uncomprlen++] = data;
			/* �����1�ֽڷ��뻬������ */
			win[nCurWindowByte++] = data;
			nCurWindowByte &= win_size - 1;
			if (act_uncomprlen >= uncomprlen)
				return;
		} else {
			unsigned int copy_bytes, win_offset;
			unsigned int i;

			win_offset = compr[curbyte++];
			copy_bytes = compr[curbyte++];
			win_offset |= (copy_bytes & 0xf0) << 4;
			copy_bytes = copy_bytes & 0x0f;
			copy_bytes += 3;

			for (i = 0; i < copy_bytes; i++) {	
				unsigned char data;

				data = win[(win_offset + i) & (win_size - 1)];
				uncompr[act_uncomprlen++] = data;
				if (act_uncomprlen == uncomprlen)
					return;
				/* �����1�ֽڷ��뻬������ */
				win[nCurWindowByte++] = data;
				nCurWindowByte &= win_size - 1;	
				if (act_uncomprlen >= uncomprlen)
					return;
			}
		}
	}
}

/********************* lax *********************/

/* ���ƥ��ص����� */
static int E_G_O_lax_match(struct package *pkg)
{
	s8 magic[8];

	if (!pkg)
		return -CUI_EPARA;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->read(pkg, magic, sizeof(magic))) {
		pkg->pio->close(pkg);
		return -CUI_EREAD;
	}

	if (strncmp(magic, "$LapH__", 8)) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;	
	}

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int E_G_O_lax_extract_directory(struct package *pkg,
										struct package_directory *pkg_dir)
{
	lax_tailer_t lax_tailer;
	dat_entry_t *index_buffer;
	unsigned int index_buffer_length;	
	unsigned int i;

	if (!pkg || !pkg_dir)
		return -CUI_EPARA;

	if (pkg->pio->readvec(pkg, &lax_tailer, sizeof(lax_tailer), 0 - sizeof(lax_tailer), IO_SEEK_END))
		return -CUI_EREADVEC;


	index_buffer_length = pkg_dir->index_entries * sizeof(dat_entry_t);
	index_buffer = (dat_entry_t *)malloc(index_buffer_length);
	if (!index_buffer)
		return -CUI_EMEM;

	dat_entry_t *index = index_buffer;
	for (i = 0; i < pkg_dir->index_entries; i++) {
		if (pkg->pio->read(pkg, &index->name_length, 4))
			break;

		if (pkg->pio->read(pkg, index->name, index->name_length))
			break;
		index->name[index->name_length] = 0;

		if (pkg->pio->read(pkg, &index->offset, 4))
			break;

		if (pkg->pio->read(pkg, &index->length, 4))
			break;

		index++;
	}
	if (i != pkg_dir->index_entries) {
		free(index_buffer);
		return -CUI_EREAD;
	}

	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_length;
	pkg_dir->index_entry_length = sizeof(dat_entry_t);
	pkg_dir->flags = PKG_DIR_FLAG_SKIP0;

	return 0;
}

/* ���������������� */
static int E_G_O_lax_parse_resource_info(struct package *pkg,
									struct package_resource *pkg_res)
{
	dat_entry_t *dat_entry;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	dat_entry = (dat_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, dat_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = dat_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = dat_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int E_G_O_lax_extract_resource(struct package *pkg,
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

	return 0;
}

/* ��Դ���溯�� */
static int E_G_O_lax_save_resource(struct resource *res, 
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
static void E_G_O_lax_release_resource(struct package *pkg, 
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
static void E_G_O_lax_release(struct package *pkg, 
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
static cui_ext_operation E_G_O_lax_operation = {
	E_G_O_lax_match,					/* match */
	E_G_O_lax_extract_directory,		/* extract_directory */
	E_G_O_lax_parse_resource_info,		/* parse_resource_info */
	E_G_O_lax_extract_resource,		/* extract_resource */
	E_G_O_lax_save_resource,			/* save_resource */
	E_G_O_lax_release_resource,		/* release_resource */
	E_G_O_lax_release					/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK E_G_O_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".lax"), NULL, 
		NULL, &E_G_O_lax_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
