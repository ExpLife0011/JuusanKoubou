#ifndef CRASS_H
#define CRASS_H

#ifdef CRASS_EXPORTS
#define CRASS_API __declspec(dllexport)
#else
#define CRASS_API __declspec(dllimport)
#endif 

/* TCHAR�������ĳ��� */
#define SOT(x)	(sizeof(x) / sizeof(TCHAR))

/*********** ����̨��Ϣ��ʾ **************/

#if 0
/* ��ʾ��Ϣ���� */
#define CRASS_VERBOSE_LEVEL_SLIENT		0
#define CRASS_VERBOSE_LEVEL_DEBUG		1
#define CRASS_VERBOSE_LEVEL_WARNING		2
#define CRASS_VERBOSE_LEVEL_ERROR		3
#define CRASS_VERBOSE_LEVEL_FAULT		4
#define CRASS_VERBOSE_LEVEL_NORMAL		255

CRASS_API extern unsigned int crass_verbose_level;
CRASS_API void crass_printf(unsigned int level, const TCHAR *fmt, ...);

/* ��ͨ��Ϣ */
#define crass_message(fmt, arg...)	\
	crass_printf(CRASS_VERBOSE_LEVEL_NORMAL, fmt, ##arg)
/* ������Ϣ */
#define crass_debug(fmt, arg...)	\
	crass_printf(CRASS_VERBOSE_LEVEL_DEBUG, fmt, ##arg)
/* ����������Ϣ */
#define crass_warning(fmt, arg...)	\
	crass_printf(CRASS_VERBOSE_LEVEL_WARNING, fmt, ##arg)
/* �����˴��� */
#define crass_error(fmt, arg...)	\
	crass_printf(CRASS_VERBOSE_LEVEL_ERROR, fmt, ##arg)	
/* ������ͨ�������ܷ��������ش��� */
#define crass_fault(fmt, arg...)	\
	crass_printf(CRASS_VERBOSE_LEVEL_FAULT, fmt, ##arg)
#endif
/* ͨ��������Ա�������ָ�롣
 * @pointer - ��Աָ�롣
 * @type - �������������͡�
 * @member - ��Ա���������ơ�
 */
#define container_of(pointer, type, member)	\
	((type *)((char *)(pointer) - (char *)&(((type *)0)->member)))

#define SOT(x)	(sizeof(x) / sizeof(TCHAR))
	
/*********** ͨ��˫������ **************/

/* ����ڵ� */
struct list_head {
	struct list_head *prev;	/* ǰ��ָ�� */
	struct list_head *next;	/* ����ָ�� */
};

/* �������ڵ���ڲ�ʵ�֡�*/
static inline void __list_add(struct list_head *prev, struct list_head *_new, struct list_head *next)
{
	_new->prev = prev;
	_new->next = next;	
	prev->next = _new;
	next->prev = _new;
}

/* ɾ������ڵ���ڲ�ʵ�֡�*/
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	prev->next = next;
	next->prev = prev;
}

/* ��ʼ������ڵ㡣
 * @head - ����ʼ���Ľڵ㡣
 */
static inline void list_init(struct list_head *head)
{
	head->prev = head->next = head;
}

/* �������ڵ㡣
 * @_new - ������Ľڵ㡣
 * @head - �������ͷ�ڵ㡣
 */
static inline void list_add(struct list_head *_new, struct list_head *head)
{
	__list_add(head, _new, head->next);
}

/* �������β��ӽڵ㡣
 * @_new - ������Ľڵ㡣
 * @head - �������ͷ�ڵ㡣
 */
static inline void list_add_tail(struct list_head *_new, struct list_head *head)
{
	__list_add(head->prev, _new, head);
}

/* ɾ���ڵ㡣
 * @head - ��ɾ���Ľڵ㡣
 */
static inline void list_del(struct list_head *head)
{
	__list_del(head->prev, head->next);
}

/* ɾ�������³�ʼ���ڵ㡣
 * @head - ��ɾ���Ľڵ㡣
 */
static inline void list_del_init(struct list_head *head)
{
	__list_del(head->prev, head->next);
	list_init(head);
}

/* �ж������Ƿ�Ϊ�ա�
 * @head - �����Եĵ�����ͷ�ڵ㡣
 */
static inline int list_empty(struct list_head *head)
{
	return head->next == head->prev ? (head->next == head ? 1 : 0) : 0;
}

/* ��������ڵ㡣
 * @pos - ��ǰ�ڵ㡣
 * @head - ����ͷ�ڵ㡣
 */
#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); \
        	pos = pos->next)
  
/* �����������ڵ㡣
 * @pos - ��ǰ�ڵ㡣
 * @head - ����ͷ�ڵ㡣
 */
#define list_for_each_reverse(pos, head) \
	for (pos = (head)->prev; pos != (head); \
        	pos = pos->prev)   
        	
/* ��ȫ��������ڵ㡣
 * @pos - ��ǰ�ڵ㡣
 * @safe - Ԥ������һ���ڵ㡣
 * @head - ����ͷ�ڵ㡣
 */        	
#define list_for_each_safe(pos, safe, head) \
	for (pos = (head)->next, safe = pos->next; pos != (head); \
        	pos = safe, safe = safe->next)   
    
/* ��ȫ�����������ڵ㡣
 * @pos - ��ǰ�ڵ㡣
 * @safe - Ԥ������һ���ڵ㡣
 * @head - ����ͷ�ڵ㡣
 */         	       	
#define list_for_each_safe_reverse(pos, safe, head) \
	for (pos = (head)->prev, safe = pos->prev; pos != (head); \
        	pos = safe, safe = safe->prev)  
   
/* ���������ָ�롣
 */ 
#define list_entry(p, type, member)	container_of(p, type, member)

/*********** ͬ������ **************/


/*********** �ļ�������� **************/

struct file_object;
struct io_request_operation {
	struct io_request *(*create)(const TCHAR *path, unsigned long flags);
	struct io_request *(*open)(const TCHAR *path, unsigned long flags);
	int (*close)(struct io_request *fobj);
	long (*read)(struct io_request *fobj, void *buf, unsigned long buf_len);
	void *(*read_only)(struct io_request *fobj, unsigned long buf_len);
	long (*readvec)(struct io_request *fobj, void *buf, unsigned long buf_len, long offset, unsigned long method);
	void *(*readvec_only)(struct io_request *fobj, unsigned long buf_len, long offset, unsigned long method);
	long (*write)(struct io_request *fobj, void *buf, unsigned long buf_len);
	long (*writevec)(struct io_request *fobj, void *buf, unsigned long buf_len, long offset, unsigned long method);
	int (*length_of)(struct io_request *fobj, unsigned long *len);	
};

struct io_request {
	struct io_request_operation *op;
	

	

};

struct file_object {
	struct file_operation *fio;
	

	

};


#endif	/* CRASS_H */
