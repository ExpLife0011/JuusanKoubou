#ifndef IO_REQUEST_H
#define IO_REQUEST_H

#ifdef IO_REQUEST_EXPORTS
#define IO_REQUEST_API __declspec(dllexport)
#else
#define IO_REQUEST_API __declspec(dllimport)
#endif 

/* initialize()��flagsλ�ζ��� */
#define IO_READWRITE	0x00000000UL
#define IO_READONLY		0x00000001UL
#define IO_CREATE		0x00000002UL

/* seek()��method�������� */
#define IO_SEEK_SET		0x00000000UL
#define IO_SEEK_CUR		0x00000001UL
#define IO_SEEK_END		0x00000002UL
#define IO_SEEK_METHOD	0x00000003UL

/* fio���������� */
struct fio_request {
	HANDLE file;			/* [int]�ļ��򿪾�� */
	HANDLE mapping;			/* [int]�ļ��ڴ�ӳ���� */
	void *ro_address;		/* [int]ֻ��ʱ��ӳ���ַ */
//	int use_counts;			/* [int]�ļ��򿪼��� */
	u64 base_offset;		/* [int]�ļ�����Դ��ַƫ�ƣ�����ֵ�� */
	u64 base_length;		/* [int]�ļ����ļ����� */
	u64 current_offset;	/* [int]��ǰ����ļ�����Դλ��ƫ�ƣ����ֵ�� */
	unsigned long flags;	/* [int]��־λ�� */
};
	
/* bio���������� */
struct bio_request {
	void *buffer;			/* ������ֵ�� */
	u64 base_offset;		/* [int]��Դ��ַƫ�ƣ�����ֵ�� */
	u64 base_length;		/* [int]�ļ����� */
	u64 current_offset;	/* [int]��ǰ�ļ�����Դλ��ƫ�ƣ����ֵ�� */
};

/* fio operations */
extern IO_REQUEST_API struct fio_request *fio_operation_initialize(const TCHAR *path, unsigned long flags);
extern IO_REQUEST_API struct fio_request *fio_operation_finish(struct fio_request *ior);
extern IO_REQUEST_API int fio_operation_seek(struct fio_request *ior, s32 offset_lo, s32 offset_hi, unsigned long flags);
extern IO_REQUEST_API int fio_operation_locate(struct fio_request *ior, u32 *location_lo, u32 *location_hi);
extern IO_REQUEST_API int fio_operation_read(struct fio_request *ior, void *buf, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API void *fio_operation_readonly(struct fio_request *ior, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API int fio_operation_write(struct fio_request *ior, void *buf, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API int fio_operation_length_of(struct fio_request *ior, u32 *len_lo, u32 *len_hi);
/* bio operations */
extern IO_REQUEST_API struct bio_request *bio_operation_initialize(void *buf, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API struct bio_request *bio_operation_finish(struct bio_request *ior);
extern IO_REQUEST_API int bio_operation_seek(struct bio_request *ior, s32 offset_lo, s32 offset_hi, unsigned long method);
extern IO_REQUEST_API int bio_operation_locate(struct bio_request *ior, u32 *location_lo, u32 *location_hi);
extern IO_REQUEST_API int bio_operation_read(struct bio_request *ior, void *buf, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API void *bio_operation_readonly(struct bio_request *ior, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API int bio_operation_write(struct bio_request *ior, void *buf, u32 buf_len_lo, u32 buf_len_hi);
extern IO_REQUEST_API int bio_operation_length_of(struct bio_request *ior, u32 *len_lo, u32 *len_hi);

#endif	/* IO_REQUEST_H */
