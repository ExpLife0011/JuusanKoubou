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
struct acui_information bakuretsu_cui_information = {
	_T("WHITE SNOW PROJECT"),	/* copyright */
	_T("(C75)(ͬ��)������ͽ�� ���Y�� ver. 1.02"),	/* system */
	_T(".snr"),				/* package */
	_T("1.0.0"),			/* revision */
	_T("�՝h���\"),			/* author */
	_T("2009-1-11 20:03"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_STABLE
};

/********************* snr *********************/

/* ���ƥ��ص����� */
static int bakuretsu_snr_match(struct package *pkg)
{
	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	return 0;	
}

/* �����Դ��ȡ���� */
static int bakuretsu_snr_extract_resource(struct package *pkg,
										  struct package_resource *pkg_res)
{
	u32 snr_size;
	pkg->pio->length_of(pkg, &snr_size);

	BYTE *snr = new BYTE[snr_size];
	if (!snr)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, snr, snr_size, 0, IO_SEEK_SET)) {
		delete [] snr;
		return -CUI_EREADVEC;
	}

	for (DWORD i = 0; i < snr_size; ++i)
		if (snr[i] != '\n')
			snr[i] ^= 8;

	pkg_res->raw_data = snr;
	pkg_res->raw_data_length = snr_size;

	return 0;
}

/* ��Դ���溯�� */
static int bakuretsu_snr_save_resource(struct resource *res, 
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
static void bakuretsu_snr_release_resource(struct package *pkg, 
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
static void bakuretsu_snr_release(struct package *pkg, 
							   struct package_directory *pkg_dir)
{
	if (pkg_dir->directory) {
		delete [] pkg_dir->directory;
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg);
}

/* �������ص��������� */
static cui_ext_operation bakuretsu_snr_operation = {
	bakuretsu_snr_match,			/* match */
	NULL,							/* extract_directory */
	NULL,							/* parse_resource_info */
	bakuretsu_snr_extract_resource,	/* extract_resource */
	bakuretsu_snr_save_resource,	/* save_resource */
	bakuretsu_snr_release_resource,	/* release_resource */
	bakuretsu_snr_release			/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK bakuretsu_register_cui(struct cui_register_callback *callback)
{
	if (callback->add_extension(callback->cui, _T(".snr"), NULL, 
		NULL, &bakuretsu_snr_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_NO_MAGIC))
			return -1;

	return 0;
}
