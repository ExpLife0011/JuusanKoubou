#ifndef ACUI_H
#define ACUI_H

/* aui/cui������Ϣ */
struct acui_information {
	const TCHAR *copyright;	/* ���ϵͳ�İ�Ȩ������Ϣ */
	const TCHAR *system;	/* ���ϵͳ��������Ϣ */
	const TCHAR *package;	/* �����չ�� */
	const TCHAR *revision;	/* �汾 */
	const TCHAR *author;	/* ���� */
	const TCHAR *date;		/* ������� */
	const TCHAR *notion;	/* ������Ϣ */
/* �����ֶζ��� */
#define ACUI_ATTRIBUTE_LEVEL_UNKNOWN	0x00000000	/* δ���� */
#define ACUI_ATTRIBUTE_LEVEL_DEVELOP	0x00000001	/* ���ܲ����ƣ����ڿ����� */
#define ACUI_ATTRIBUTE_LEVEL_UNSTABLE	0x00000002	/* ������Ȼ���ƣ����ǲ��ȶ� */
#define ACUI_ATTRIBUTE_LEVEL_STABLE		0x00000003	/* �����������ȶ� */
#define ACUI_ATTRIBUTE_SUPPORT64		0x40000000	/* ֧��64λ���� */
#define ACUI_ATTRIBUTE_MT_SAFE			0x80000000	/* ���̰߳�ȫ */
#define ACUI_ATTRIBUTE_PRELOAD			0x01000000	/* ֧����ԴԤ�� */
	unsigned long attribute;/* �����ֶ� */	
};

#endif	/* ACUI_H */
