#ifndef PACKAGE_H
#define PACKAGE_H

#include <crass_types.h>
#include <crass/io_request.h>

/* io���� */
struct package_io_operations {
	int (*open)(struct package *pkg, unsigned long flags);
	void (*close)(struct package *pkg);
	int (*seek)(struct package *pkg, s32 offset, unsigned long method);
	int (*locate)(struct package *pkg, u32 *offset);
	int (*read)(struct package *pkg, void *buf, u32 buf_len);
	int (*write)(struct package *pkg, void *buf, u32 buf_len);
	int (*readvec)(struct package *pkg, void *buf, u32 buf_len, s32 offset, unsigned long method);
	int (*writevec)(struct package *pkg, void *buf, u32 buf_len, s32 offset, unsigned long method);
	int (*length_of)(struct package *pkg, u32 *len);
	int (*create)(struct package *pkg);
	void *(*read_only)(struct package *pkg, u32 buf_len);
	void *(*readvec_only)(struct package *pkg, u32 buf_len, s32 offset, unsigned long method);
	int (*seek64)(struct package *pkg, s32 offset_lo, s32 offset_hi, unsigned long method);
	int (*locate64)(struct package *pkg, u32 *offset_lo, u32 *offset_hi);
	int (*read64)(struct package *pkg, void *buf, u32 buf_len_lo, u32 buf_len_hi);
	int (*write64)(struct package *pkg, void *buf, u32 buf_len_lo, u32 buf_len_hi);
	int (*readvec64)(struct package *pkg, void *buf, u32 buf_len_lo, u32 buf_len_hi, s32 offset_lo, s32 offset_hi, unsigned long method);
	int (*writevec64)(struct package *pkg, void *buf, u32 buf_len_lo, u32 buf_len_hi, s32 offset_lo, s32 offset_hi, unsigned long method);
	int (*length_of64)(struct package *pkg, u32 *len_lo, u32 *len_hi);
	void *(*read_only64)(struct package *pkg, u32 buf_len_lo, u32 buf_len_hi);
	void *(*readvec_only64)(struct package *pkg, u32 buf_len_lo, u32 buf_len_hi, s32 offset_lo, s32 offset_hi, unsigned long method);
};

struct package_context {
	u64 base_offset;		/* [int]����ļ�����Դ��ַƫ�ƣ�����ֵ�� */
	u64 base_length;		/* [int]����ļ����ļ����� */
	u64 current_offset;		/* [int]��ǰ����ļ�����Դλ��ƫ�ƣ����ֵ�� */
	//struct package_context *parent;
};

/* ��������� */
struct package {
	struct package *lst;					/* [in] �ⲿ�����ļ� */
	const TCHAR *name;						/* [in] ������� */
	struct package_io_operations *pio;		/* [in]  */
	unsigned long context;					/* [out,in]���˽����Ϣ */
	union {
		struct fio_request *fior;			/* [int]fio���������� */
		struct bio_request *bior;			/* [int]bio���������� */	
	};
	/* ���³�Ա��Ϣ��cui/aui���벻͸�� */
	const TCHAR *full_path;					/* [int]���ȫ·�� */
	const TCHAR *path;						/* [int]���·�� */
	const TCHAR *extension;					/* [int]�����չ�� */
	int use_counts;
	void (*release)(struct package *);	
	struct package *prev;					/* [int]ǰһ�������Ϣ */
	struct package *next;					/* [int]��һ�������Ϣ */
	struct package_resource *pkg_res;
	struct package *parent;
	struct package_context *pkg_context;
};

#define package_get_private(pkg)	((pkg)->context)
#define package_set_private(pkg, v)	((pkg)->context = (unsigned long)v)

/* ���Ŀ¼��Ϣ */
struct package_directory {
	void *directory;						/* [out][out]���������� */
	unsigned long directory_length;			/* [out][out]���������ݳ��� */
	unsigned long index_entries;			/* [in] [out]��Դ�ļ��ĸ��� */
	unsigned long index_entry_length;		/* [out][out]������ĳ��� */
//	const TCHAR *lst_filename;				/* [in] �ⲿ�����ļ��� */
//	struct io_request *lst;					/* [in] �ⲿ�����ļ���io������ */
/* ��־λ�ζ��� */
#define PKG_DIR_FLAG_VARLEN				0x00000001	/* ��������Ϣ�䳤 */
#define PKG_DIR_FLAG_SKIP0				0x00000002	/* ���Գ���Ϊ0������ */
#define PKG_DIR_FLAG_PRIVATE			0xff000000	/* cui˽��λ�� */
	unsigned long flags;					/* [out][out]��־λ�� */
};

struct package_resource {
	unsigned int index_number;
	void *actual_index_entry;				/* [out][in] ָ��ǰ������ */
	unsigned long actual_index_entry_length;/* [out][out]��ǰ������ĳ��ȣ����䳤�����ε������ */
	char name[256];							/* [in] [out]��Դ�ļ����� */
	long name_length;						/* [in] [out]��Դ�ļ����Ƴ��ȣ�-1��ʾ��NULL��β */
	void *raw_data;							/* [out][out]ԭʼ��Դ�ļ����� */
	unsigned long raw_data_length;			/* [out][out]ԭʼ��Դ�ļ����ݳ��� */
	unsigned long offset;					/* [in] [out]ƫ��λ�� */
	void *actual_data;						/* [out][out]ʵ�ʵ����� */
	unsigned long actual_data_length;		/* [in] [out]ʵ�ʵ����ݳ��� */
	const TCHAR *replace_extension;
/* ��־λ�ζ��� */
#define PKG_RES_FLAG_RAW		0x00000001	/* ֻ��ȡԭʼ���� */
#define PKG_RES_FLAG_LAST		0x00000002	/* ���һ����Դ */
#define PKG_RES_FLAG_REEXT		0x00010000	/* ���¶�����Դ�ļ���չ�� */
#define PKG_RES_FLAG_UNICODE	0x00020000	/* ��Դ�ļ�������UNICODE���� */
#define PKG_RES_FLAG_FIO		0x00040000	/* ��FIO��Դ������ȡ(����RES��Ŀ¼�ͷ��) */
#define PKG_RES_FLAG_APEXT		0x00080000	/* ������Դ�ļ���չ�� */
#define PKG_RES_FLAG_PRIVATE	0xff000000	/* cui˽��λ������ */
	unsigned long flags;					/* [in][out]��־λ�� */
};

#if 0
struct package_index_header {
	char cui_name[32];
	unsigned int entries;
	unsigned int index_length;
};

struct package_index_entry {
	char name[128];	
	LONG offset;
	DWORD length;
	DWORD actual_length;
};
#endif

#endif	/* PACKAGE_H */
