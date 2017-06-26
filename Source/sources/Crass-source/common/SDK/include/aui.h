#ifndef AUI_H
#define AUI_H

#include "acui.h"

struct aui_register_callback;

/* aui���뱩¶��APIԭ�� */
typedef int (CALLBACK *register_aui_t)(struct aui_register_callback *callback);
///typedef void (CALLBACK *unregister_aui_t)(struct aui_unregister_callback *callback);
typedef void (CALLBACK *show_aui_info_t)(struct acui_information *info);

struct aui_extension;
/* aui��Ϣ��aui�����в�Ҫֱ�Ӳ��������κγ�Ա�� */
struct aui {
	struct aui *prev;		/* aui�����ǰָ�� */
	struct aui *next;		/* aui����ĺ�ָ�� */
	HMODULE module;			/* auiģ���� */
	TCHAR *name;			/* auiģ���� */
	struct aui_extension *first_ext;
	struct aui_extension *last_ext;		
	unsigned int ext_count;	/* ֧�ֵ���չ������ */
};

/* aui��չ����Ϣ��aui�����в�Ҫֱ�Ӳ��������κγ�Ա�� */
struct aui_ext_operation;
struct aui_extension {
	struct aui_ext_operation *op;
	const TCHAR *extension;
	const TCHAR *lst_extension;
	const TCHAR *replace_extension;
	const TCHAR *description;
	struct aui_extension *next_ext;
	struct aui *aui;
	unsigned long flags;
};

/* ÿ�������չ�����ض�������ƵĲ������� */
struct aui_ext_operation {	
	int (*match)(struct resource *);				/* ��Դ�Ƿ���Ϸ������ */
	int (*collect_resource_info)(struct resource *,					/* ��ȡ��Դ�ļ���Ϣ */
		struct package_resource *);
	int (*repacking_resource)(struct resource *,					/* ��װ��Դ�ļ� */
		struct package *, struct package_resource *, struct package_directory *);
	int (*repacking)(struct package *, struct package_directory *);	/* ������ */
};

/* auiע��ʱassage�ṩ�Ļص����� */
struct aui_register_callback {
	struct aui *aui;
	/* �����չ����֧����Ӧ�ķ���ļ���
	 * @handle: ���������
	 * @extension: ֧�ֵķ����չ������"."��ͷ����Сд�����У���
	 * @replace_extension: ����ѡ���滻�õ���չ������"."��ͷ��
	 * @description: ����ѡ�������Ϣ��
	 * @operation: ���������ʹ�õĸ��ֻص�������
	 * @flags: ����λ�ζ��塣
	 *
	 * �������ķ����һ������directory�ķ����
	 * ��ôrep_extΪ�ա�
	 * �������ķ����һ��������directory�ķ����
	 * Ҳ��˵��һ��������Դ�ļ����Һ���չ������ô
	 * extΪ�ļ�������ƥ����match()������
	 */
	int (*add_extension)(struct aui *aui, const TCHAR *extension, 
		const TCHAR *replace_extension, const TCHAR *lst_extension, 
		const TCHAR *description, struct aui_ext_operation *operation, unsigned long flags);
/* flagsλ�ζ��� */
#define AUI_EXT_FLAG_PKG		0x00000001	/* ����� */
#define AUI_EXT_FLAG_RES		0x00000002	/* ��Դ�� */
#define AUI_EXT_FLAG_NOEXT		0x00010000	/* ����չ�� */
#define AUI_EXT_FLAG_DIR		0x00020000	/* ��Ŀ¼ */
#define AUI_EXT_FLAG_LST		0x00040000	/* ��Ҫ����������ļ� */
};
	
#endif /* AUI_H */
