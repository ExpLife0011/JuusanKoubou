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
#include <utility.h>

// http://school.cfan.com.cn/pro/pother/2006-09-12/1158030322d16493.shtml
// http://topic.csdn.net/t/20050707/20/4130073.html
// http://www.warpfield.cn/blog/?p=146

/* �ӿ����ݽṹ: ��ʾcui�����һ����Ϣ */
struct acui_information MacromediaFlash_cui_information = {
	_T("Macromedia"),		/* copyright */
	_T("MacromediaFlash"),	/* system */
	_T(".swf"),				/* package */
	_T("0.0.1"),			/* revision */
	_T("�՝h���\"),			/* author */
	_T(""),					/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_DEVELOP
};

/* ���еķ���ض������ݽṹ��Ҫ�������#pragma���� */
#pragma pack (1)
typedef struct {
	s8 magic[3];	// "FWS"
	u8 version;
	u32 length;		// flash�ļ��Ĵ�С
} swf_header_t;

typedef struct {	// Flash 6��ʼ֧��
	s8 magic[3];	// "CWS"
	u8 version;		// 7, 8
	u32 uncomprlen;	// flash�ļ���ԭʼ��С
} cswf_header_t;

typedef struct {
	RECT frame_size;	// ��twipΪ��λ(1/20����)��¼֡�ĳߴ� (��8�ֽ�)
	u16 frame_rate;
	u16 frame_count;
} swf_info_t;

#pragma pack ()

typedef struct {
	char name[MAX_PATH];
	DWORD name_length;
	DWORD offset;
	DWORD length;
} my_cswf_entry_t;

/********************* cswf *********************/

/* ���ƥ��ص����� */
static int MacromediaFlash_cswf_match(struct package *pkg)
{
	cswf_header_t cswf_header;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->read(pkg, &cswf_header, sizeof(cswf_header))) {
		pkg->pio->close(pkg);
		return -CUI_EREAD;
	}

	if (strncmp(cswf_header.magic, "CWS", 3) || cswf_header.version < 7
				|| cswf_header.uncomprlen < 8) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;
	}
	package_set_private(pkg, cswf_header.version);

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int MacromediaFlash_cswf_extract_directory(struct package *pkg,
												  struct package_directory *pkg_dir)
{
	cswf_header_t cswf_header;

	if (pkg->pio->readvec(pkg, &cswf_header, sizeof(cswf_header), 0, IO_SEEK_SET))
		return -CUI_EREADVEC;

	u32 comprlen;
	pkg->pio->length_of(pkg, &comprlen);
	comprlen -= sizeof(cswf_header);

	BYTE *compr = new BYTE[comprlen];
	if (!compr)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg, compr, comprlen)) {
		delete [] compr;
		return -CUI_EREAD;
	}

	BYTE *uncompr = new BYTE[cswf_header.uncomprlen - 8];
	if (!uncompr) {
		delete [] compr;
		return -CUI_EMEM;
	}

	DWORD act_uncomprlen = cswf_header.uncomprlen - 8;
	if (uncompress(uncompr, &act_uncomprlen, compr, comprlen) != Z_OK) {
		delete [] uncompr;
		delete [] compr;
		return -CUI_EUNCOMPR;		
	}
printf("%x %x\n", act_uncomprlen, cswf_header.uncomprlen);
	MySaveFile(_T("swf"), uncompr, act_uncomprlen);
#if 0

	pkg_dir->index_entries = k;
	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = k * sizeof(my_cswf_entry_t);
	pkg_dir->index_entry_length = sizeof(my_cswf_entry_t);
#endif
	return 0;
}

/* ���������������� */
static int MacromediaFlash_cswf_parse_resource_info(struct package *pkg,
													struct package_resource *pkg_res)
{
#if 0
	my_cswf_entry_t *my_cswf_entry;

	my_cswf_entry = (my_cswf_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, my_cswf_entry->name);
	pkg_res->name_length = my_cswf_entry->name_length;
	pkg_res->raw_data_length = my_cswf_entry->length;
	pkg_res->actual_data_length = 0;	/* ���ݶ������� */
	pkg_res->offset = my_cswf_entry->offset;
#endif
	return 0;
}

/* �����Դ��ȡ���� */
static int MacromediaFlash_cswf_extract_resource(struct package *pkg,
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
static int MacromediaFlash_cswf_save_resource(struct resource *res, 
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
static void MacromediaFlash_cswf_release_resource(struct package *pkg, 
										struct package_resource *pkg_res)
{
	if (pkg_res->raw_data) {
		free(pkg_res->raw_data);
		pkg_res->raw_data = NULL;
	}
}

/* ���ж�غ��� */
static void MacromediaFlash_cswf_release(struct package *pkg, 
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
static cui_ext_operation MacromediaFlash_cswf_operation = {
	MacromediaFlash_cswf_match,					/* match */
	MacromediaFlash_cswf_extract_directory,		/* extract_directory */
	MacromediaFlash_cswf_parse_resource_info,	/* parse_resource_info */
	MacromediaFlash_cswf_extract_resource,		/* extract_resource */
	MacromediaFlash_cswf_save_resource,			/* save_resource */
	MacromediaFlash_cswf_release_resource,		/* release_resource */
	MacromediaFlash_cswf_release					/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK MacromediaFlash_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".swf"), NULL, 
		NULL, &MacromediaFlash_cswf_operation, CUI_EXT_FLAG_PKG 
		| CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
