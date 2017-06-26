#include <windows.h>
#include <tchar.h>
#include <crass_types.h>
#include <acui.h>
#include <cui.h>
#include <package.h>
#include <resource.h>
#include <cui_error.h>
#include <stdio.h>
#include <utility.h>

/* �ӿ����ݽṹ: ��ʾcui�����һ����Ϣ */
struct acui_information GLib_cui_information = {
	_T("Kyoya Yuro"),		/* copyright */
	_T("����"),			/* system */
	_T(".dat"),				/* package */
	_T("1.0.0"),			/* revision */
	_T("�պ�����"),			/* author */
	_T("2007-3-24 10:12"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_STABLE
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	s8 magic[8];		// "GML_ARC"
	u32 data_offset;
	u32 uncomprlen;
	u32 comprlen;
} g_header_t;
#pragma pack ()

typedef struct {
	s8 name[256];
	u32 offset;
	u32 length;
} my_g_entry_t;

static BYTE g_code_table[256];

/* ����׼��copy_bytes��4λ����ȡ�� */
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
			if (act_uncomprlen == uncomprlen)
				return;
			/* �����1�ֽڷ��뻬������ */
			win[nCurWindowByte++] = data;
			nCurWindowByte &= win_size - 1;
		} else {
			unsigned int copy_bytes, win_offset;
			unsigned int i;

			win_offset = compr[curbyte++];
			copy_bytes = compr[curbyte++];
			win_offset |= (copy_bytes >> 4) << 8;
			copy_bytes = ~copy_bytes & 0x0f;
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
			}
		}
	}
}

/********************* g *********************/

/* ���ƥ��ص����� */
static int GLib_g_match(struct package *pkg)
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

	if (strncmp(magic, "GML_ARC", 8)) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;	
	}

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int GLib_g_extract_directory(struct package *pkg,
									struct package_directory *pkg_dir)
{
	unsigned int index_buffer_length;	
	u32 data_offset, uncomprlen, comprlen;
	BYTE *compr, *uncompr, *p;
	my_g_entry_t *index_buffer;

	if (!pkg || !pkg_dir)
		return -CUI_EPARA;

	if (pkg->pio->read(pkg, &data_offset, 4))
		return -CUI_EREAD;

	if (pkg->pio->read(pkg, &uncomprlen, 4))
		return -CUI_EREAD;

	if (pkg->pio->read(pkg, &comprlen, 4))
		return -CUI_EREAD;

	compr = (BYTE *)malloc(comprlen);
	if (!compr)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg, compr, comprlen)) {
		free(compr);
		return -CUI_EREAD;
	}

	for (DWORD i = 0; i < comprlen; i++)
		compr[i] = ~compr[i];

	uncompr = (BYTE *)malloc(uncomprlen);
	if (!uncompr) {
		free(compr);
		return -CUI_EMEM;
	}

	lzss_decompress(uncompr, uncomprlen, compr, comprlen);
	free(compr);

	memcpy(g_code_table, uncompr, 256);
	p = uncompr + 256;
	pkg_dir->index_entries = *(u32 *)p;
	index_buffer_length = sizeof(my_g_entry_t) * pkg_dir->index_entries;
	index_buffer = (my_g_entry_t *)malloc(index_buffer_length);
	if (!uncompr) {
		free(uncompr);
		return -CUI_EMEM;
	}

	p += 4;
	for (i = 0; i < pkg_dir->index_entries; i++) {
		u32 name_length;

		name_length = *(u32 *)p;
		p += 4;
		strncpy(index_buffer[i].name, (char *)p, name_length);
		index_buffer[i].name[name_length] = 0;
		p += name_length;
		index_buffer[i].offset = *(u32 *)p + data_offset;
		p += 4;
		index_buffer[i].length = *(u32 *)p;
		p += 4;
		p += 4;	// skip suffix string
	}
	free(uncompr);

	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_length;
	pkg_dir->index_entry_length = sizeof(my_g_entry_t);

	return 0;
}

/* ���������������� */
static int GLib_g_parse_resource_info(struct package *pkg,
									  struct package_resource *pkg_res)
{
	my_g_entry_t *my_g_entry;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	my_g_entry = (my_g_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, my_g_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = my_g_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = my_g_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int GLib_g_extract_resource(struct package *pkg,
								   struct package_resource *pkg_res)
{
	BYTE *compr, *uncompr = NULL;
	DWORD uncomprlen = 0;
	
	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	compr = (BYTE *)malloc(pkg_res->raw_data_length);
	if (!compr)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, compr, pkg_res->raw_data_length,
		pkg_res->offset, IO_SEEK_SET)) {
			free(compr);
			return -CUI_EREADVEC;
	}

	for (DWORD i = 0; i < 32; i++)
		compr[i] = g_code_table[compr[i]];

	pkg_res->raw_data = compr;

	return 0;
}

/* ��Դ���溯�� */
static int GLib_g_save_resource(struct resource *res, 
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
static void GLib_g_release_resource(struct package *pkg, 
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
static void GLib_g_release(struct package *pkg, 
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
static cui_ext_operation GLib_g_operation = {
	GLib_g_match,					/* match */
	GLib_g_extract_directory,		/* extract_directory */
	GLib_g_parse_resource_info,		/* parse_resource_info */
	GLib_g_extract_resource,		/* extract_resource */
	GLib_g_save_resource,			/* save_resource */
	GLib_g_release_resource,		/* release_resource */
	GLib_g_release					/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK GLib_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".g"), NULL, 
		NULL, &GLib_g_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
