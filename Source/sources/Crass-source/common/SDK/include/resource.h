#ifndef RESOURCE_H
#define RESOURCE_H

#include <crass_types.h>
#include <crass/io_request.h>
#include <package.h>
#include <resource.h>

/* io���� */
struct resource_io_operations {
	int (*create)(struct resource *res);
	void (*close)(struct resource *res);
	int (*seek)(struct resource *res, s32 offset, unsigned long method);
	int (*locate)(struct resource *res, u32 *offset);
	int (*read)(struct resource *res, void *buf, u32 buf_len);
	int (*write)(struct resource *res, void *buf, u32 buf_len);
	int (*readvec)(struct resource *res, void *buf, u32 buf_len, s32 offset, unsigned long method);
	int (*writevec)(struct resource *res, void *buf, u32 buf_len, s32 offset, unsigned long method);
	int (*length_of)(struct resource *res, u32 *len);
	int (*open)(struct resource *res);
	void *(*read_only)(struct resource *res, u32 buf_len);
	void *(*readvec_only)(struct resource *pkg, u32 buf_len, s32 offset, unsigned long method);
	int (*seek64)(struct resource *res, s32 offset_lo, s32 offset_hi, unsigned long method);
	int (*locate64)(struct resource *res, u32 *offset_lo, u32 *offset_ji);
	int (*read64)(struct resource *res, void *buf, u32 buf_len_lo, u32 buf_len_hi);
	int (*write64)(struct resource *res, void *buf, u32 buf_len_lo, u32 buf_len_hi);
	int (*readvec64)(struct resource *res, void *buf, u32 buf_len_lo, u32 buf_len_hi, s32 offset_lo, s32 offset_hi, unsigned long method);
	int (*writevec64)(struct resource *res, void *buf, u32 buf_len_lo, u32 buf_len_hi, s32 offset_lo, s32 offset_hi, unsigned long method);
	int (*length_of64)(struct resource *res, u32 *len_lo, u32 *len_hi);
	void *(*read_only64)(struct resource *res, u32 buf_len_lo, u32 buf_len_hi);
	void *(*readvec_only64)(struct resource *res, u32 buf_len_lo, u32 buf_len_hi, s32 offset_lo, s32 offset_hi, unsigned long method);
};

struct package_resource;
/* ��Դ������ */
struct resource {
	const TCHAR *name;						/* [in] ��Դ���� */
	struct resource_io_operations *rio;		/* [in] */
	void *context;							/* [out,in]��Դ˽����Ϣ */
	/* ���³�Ա��Ϣ��cui/aui���벻͸�� */
	struct fio_request *ior;				/* [int]io���������� */
	struct package_resource *pkg_res;		/* [int] */
	const TCHAR *full_path;					/* [int]���ȫ·�� */
	const TCHAR *path;						/* [int]���·�� */
	const TCHAR *extension;					/* [int]�����չ�� */
	int use_counts;
	void (*release)(struct resource *);	
	struct resource *prev;					/* [int]ǰһ�������Ϣ */
	struct resource *next;					/* [int]��һ�������Ϣ */
};

#endif	/* RESOURCE_H */
