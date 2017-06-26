#include <windows.h>
#include <tchar.h>
#include <shlwapi.h>
#include <crass_types.h>
#include <acui.h>
#include <cui.h>
#include <resource.h>
#include <package.h>
#include <cui_error.h>
#include <stdio.h>

//crc��֤��2�ֽ���ֵ֤ �����ȷ�����صĵ�crc_buf�е�ֵӦΪ0�������ʾ�����д���֤ʧ��
//�����Ķ�һ��������Ԫ����crc �����������crc�Ƿ�Ϊ0
//[0](4)XARC
//[4](4)??
//[8](2)
//[10](2)
//[12](4)
//[16](4)NDIX entries ��Դ����(8 bytes per entry)
//[20](2)
//[22](4)DFNM
//[26](8)CADR segment offset lo & hi
//[34](2)
//[36](4)NDIX
//entry [0](2)0x1001 [2](4)offset [6](2)
//[??](4)EDIX
//����ͬNDIX
//[??](4)CTIF
//[0](2) ͨ�������crc��2����2��ǰ�������crc�ٴ����ֵ����µ�crc��4��(2)���idx����0��ʼ����6](2)name_len[8](2)
//������Щ�����Ժ󣬶����յ�crc��飨����crc�ֶκͼ���õ���crcӦ����ͬ��
//[10](name_len) xor 0x56����[][2]crc

//CADR
//ÿ��12�ֽڣ������idx�����ã�CADR segment offset lo + idx * 12) + 4
//[0](2) [2](8)


struct acui_information Xuse_cui_information = {
	_T("�����������|�졿(Xuse)"),		/* copyright */
	NULL,	/* system */
	_T(".gd .dll*"),		/* package */
	_T("1.0.0"),			/* revision */
	_T("�պ�����"),			/* author */
	_T(""),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_DEVELOP
};

#pragma pack (1)
typedef struct {
	u32 entries;	/* need plus 1 */
} gd_header_t;

typedef struct {
	u32 unknown;
} dll_header_t;

typedef struct {
	u32 offset;
	u32 length;	
} dll_entry_t;
#pragma pack ()

/********************* gd *********************/

static int Xuse_gd_match(struct package *pkg)
{
	if (!pkg || !pkg->lst)
		return -CUI_EPARA;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->open(pkg->lst, IO_READONLY)) {
		pkg->pio->close(pkg);
		return -CUI_EOPEN;
	}

	return 0;	
}

static int Xuse_gd_extract_directory(struct package *pkg,
									 struct package_directory *pkg_dir)
{		
	dll_header_t dll_header;
	gd_header_t gd_header;
	dll_entry_t *index_buffer;
	unsigned int index_entries, index_buffer_len;
	unsigned long dll_size;

	if (!pkg || !pkg_dir || !pkg->lst)
		return -CUI_EPARA;

	if (pkg->pio->length_of(pkg->lst, &dll_size))
		return -CUI_ELEN;

	index_buffer_len = dll_size - 4;
	index_entries = index_buffer_len / sizeof(dll_entry_t);

	if (pkg->pio->read(pkg, &gd_header, sizeof(gd_header)))
		return -CUI_EREAD;

	/* �е��ļ���gd_header.entriesΪ0����ʱ��ʵ�ʵ���Դ����gd_header�м�¼�Ļ��� */
	//if (!gd_header.entries)
	//	gd_header.entries = entries;
	//gd_header.entries = entries >= gd_header.entries ? entries : gd_header.entries;

	if (pkg->pio->read(pkg->lst, &dll_header, sizeof(dll_header)))
		return -CUI_EREAD;

	index_buffer = (dll_entry_t *)malloc(index_buffer_len);
	if (!index_buffer)
		return -CUI_EMEM;

	if (pkg->pio->read(pkg->lst, index_buffer, index_buffer_len)) {
		free(index_buffer);
		return -CUI_EREAD;
	}
	pkg_dir->index_entries = index_entries;
	pkg_dir->index_entry_length = sizeof(dll_entry_t);
	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_len;

	return 0;
}

static int Xuse_gd_parse_resource_info(struct package *pkg,
									   struct package_resource *pkg_res)
{
	dll_entry_t *dll_entry;

	if (!pkg || !pkg_res)
		return -CUI_EPARA;

	dll_entry = (dll_entry_t *)pkg_res->actual_index_entry;
	sprintf(pkg_res->name, "%05d", pkg_res->index_number);
	pkg_res->name_length = -1;
	pkg_res->raw_data_length = dll_entry->length;
	pkg_res->actual_data_length = 0;
	pkg_res->offset = dll_entry->offset;
//	printf("%s: %d @ %x\n", pkg_res->name, pkg_res->raw_data_length, pkg_res->offset);

	return 0;
}

static int Xuse_gd_extract_resource(struct package *pkg,
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

	if (!memcmp(pkg_res->raw_data, "\x89PNG", 4)) {
		pkg_res->replace_extension = _T(".png");
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
	} else if (!memcmp(pkg_res->raw_data, "OggS", 4)) {
		pkg_res->replace_extension = _T(".ogg");
		pkg_res->flags |= PKG_RES_FLAG_REEXT;
	} 

	return 0;
}

static int Xuse_gd_save_resource(struct resource *res, 
								 struct package_resource *pkg_res)
{
	if (!res || !pkg_res)
		return -CUI_EPARA;
	
	if (res->rio->create(res))
		return -CUI_ECREATE;

	if (res->rio->write(res, pkg_res->raw_data, pkg_res->raw_data_length)) {
		res->rio->close(res);
		return -CUI_EWRITE;
	}
	res->rio->close(res);
	
	return 0;
}

static void Xuse_gd_release_resource(struct package *pkg, 
									 struct package_resource *pkg_res)
{
	if (!pkg || !pkg_res)
		return;

	if (pkg_res->raw_data) {
		free(pkg_res->raw_data);
		pkg_res->raw_data = NULL;
	}
}

static void Xuse_gd_release(struct package *pkg, 
							struct package_directory *pkg_dir)
{
	if (!pkg || !pkg->lst || !pkg_dir)
		return;

	if (pkg_dir->directory) {
		free(pkg_dir->directory);
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg->lst);
	pkg->pio->close(pkg);
}

static cui_ext_operation Xuse_gd_operation = {
	Xuse_gd_match,					/* match */
	Xuse_gd_extract_directory,		/* extract_directory */
	Xuse_gd_parse_resource_info,	/* parse_resource_info */
	Xuse_gd_extract_resource,		/* extract_resource */
	Xuse_gd_save_resource,			/* save_resource */
	Xuse_gd_release_resource,		/* release_resource */
	Xuse_gd_release					/* release */
};

int CALLBACK Xuse_register_cui(struct cui_register_callback *callback)
{
	if (callback->add_extension(callback->cui, _T(".gd"), NULL, 
		NULL, &Xuse_gd_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR | CUI_EXT_FLAG_LST))
			return -1;

	return 0;
}
