#ifndef PACKAGE_H
#define PACKAGE_H
	
	
struct package_directory_entry_operation {
	
	
};

	
struct package_directory_operation {
	add_on_entry(struct __package_directory *, );
	
};


struct package_directory_entry {
	struct package_directory_entry_operation *op;
	struct list_head entry;							/* Ŀ¼������ڵ� */
	unsigned int ref_count;							/* ���ü��� */
	struct __package_directory *pd;					/* ������Ŀ¼�� */
	void *data;										/* Ŀ¼������ */
	unsigned int data_length;						/* Ŀ¼�����ݳ��� */
};

struct __package_directory {
	struct package_directory_operation *op;
	unsigned int entries;					/* �����ڵ��� */
	struct list_head link;					/* �����ڵ����� */
	unsigned int ref_count;					/* ���ü��� */
	struct package *pkg;					/* �����ķ�� */
	//lock_t lock;
};
	
#endif	/* PACKAGE_H */
