#ifndef CUI_H
#define CUI_H

struct cui_register_callback;

/* cui���뱩¶��APIԭ�� */
typedef int (CALLBACK *register_cui_t)(struct cui_register_callback *callback);
//typedef void (CALLBACK *unregister_cui_t)(struct cui_unregister_callback *callback);
typedef void (CALLBACK *show_cui_info_t)(struct acui_information *info);

struct cui_extension;
/* cui��Ϣ��cui�����в�Ҫֱ�Ӳ��������κγ�Ա�� */
struct cui {
	struct cui *prev;		/* cui�����ǰָ�� */
	struct cui *next;		/* cui����ĺ�ָ�� */
	HMODULE module;			/* cuiģ���� */
	TCHAR *name;			/* cuiģ���� */
	struct cui_extension *first_ext;
	struct cui_extension *last_ext;		
	unsigned int ext_count;	/* ֧�ֵ���չ������ */
};

/* cui��չ����Ϣ��cui�����в�Ҫֱ�Ӳ��������κγ�Ա�� */
struct cui_extension {
	struct cui_ext_operation *op;
	const TCHAR *extension;
	const TCHAR *replace_extension;
	const TCHAR *description;
	struct cui_extension *next_ext;
	struct cui *cui;
	unsigned long flags;
};

/* ÿ�������չ�����ض�������ƵĲ������� */
struct cui_ext_operation {
	int (*match)(struct package *);				/* �Ƿ�֧�ָ÷�� */
	int (*extract_directory)(struct package *,	/* ��ȡdirectory���� */
		struct package_directory *);
	int (*parse_resource_info)(struct package *,/* ����resource��Ϣ */
		struct package_resource *);	
	int (*extract_resource)(struct package *,	/* ��ȡ��Դ�ļ����� */
		struct package_resource *);	
	int (*save_resource)(struct resource *,		/* ������Դ���� */
		struct package_resource *);	
	void (*release_resource)(struct package *,	/* �ͷ������Դ */
		struct package_resource *);
	void (*release)(struct package *,			/* �ͷ������Դ */
		struct package_directory *);
};

/* cuiע��ʱcrage�ṩ�Ļص����� */
struct cui_register_callback {
	struct cui *cui;
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
	int (*add_extension)(struct cui *cui, const TCHAR *extension, 
		const TCHAR *replace_extension, const TCHAR *description,
		struct cui_ext_operation *operation, unsigned long flags);
/* flagsλ�ζ��� */
#define CUI_EXT_FLAG_PKG		0x00000001	/* ����� */
#define CUI_EXT_FLAG_RES		0x00000002	/* ��Դ�� */
#define CUI_EXT_FLAG_NOEXT		0x00010000	/* ����չ�� */
#define CUI_EXT_FLAG_DIR		0x00020000	/* ��Ŀ¼ */
#define CUI_EXT_FLAG_LST		0x00040000	/* ��Ҫ����������ļ� */
#define CUI_EXT_FLAG_OPTION		0x00080000	/* ��Ҫ��ö�������ò��� */
#define CUI_EXT_FLAG_NO_MAGIC	0x00100000	/* û��magicƥ�� */
#define CUI_EXT_FLAG_WEAK_MAGIC	0x00200000	/* ����û��magicƥ�䣬������չ����Զ��� */
//#define CUI_EXT_FLAG_IMPACT		0x00400000	/* ����magic��ͬ��cui����extract_dir��extract_resource�׶ζ�������� */
#define CUI_EXT_FLAG_SUFFIX_SENSE	0x00400000	/* ��׺����Сд���� */
#define CUI_EXT_FLAG_RECURSION		0x00800000	/* ��Դ�ݹ鴦�� */
};

#endif /* CUI_H */
