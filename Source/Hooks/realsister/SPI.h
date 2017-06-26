/*
   SPI import module base class
   Copyright (C) 1997 H.Mutsuki
   http://www2f.biglobe.ne.jp/~kana/spi_api/index.html
*/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_SPI
#define _INC_SPI	/* #defined if spi.h has been included */

#include <Windows.h>

/*****************************************************************
	SUSIE���ڲ����昋����
*****************************************************************/
#pragma pack(push,1)
typedef struct
{
	LONG left,top;		// �����չ�_����λ��
	LONG width;			// ����η�(pixel)
	LONG height;		// ����θߤ�(pixel)
	WORD x_density;		// ���ؤ�ˮƽ�����ܶ�
	WORD y_density;		// ���ؤδ�ֱ�����ܶ�
	SHORT colorDepth;	// �����ص������bit��
	HLOCAL hInfo;		// �����ڤΥƥ��������
} TSpiPictureInfo;

typedef struct
{
	BYTE method[8];		// �R�s���ηN�
	DWORD position;		// �ե������ϤǤ�λ��
	DWORD compsize;		// �R�s���줿������
	DWORD filesize;		// Ԫ�Υե����륵����
	time_t timestamp;	// �ե�����θ����Օr
	char path[200];		// �����ѥ�
	char filename[200];	// �ե�����ͩ`��
	DWORD crc;			// CRC
}  TSpiArchiveInfo;
#pragma pack(pop)

// ���`��Хå��v��
typedef int (CALLBACK* PROGRESSCALLBACK)(int nNum, int nDenom, long lData);

// �ꥶ��ȥ��`��
// Struct Code
#define	SPI_OK					0		// �����K��
#define	SPIERR_UNSUPPORTED		-1		// ���ΙC�ܤϥ���ץ���Ȥ���Ƥ��ʤ�
#define	SPIERR_CANCELED			1		// ���`��Хå��v������0�򷵤����Τ�չ�_����ֹ����
#define	SPIERR_UNKNOWNFORMAT	2		// δ֪�Υե��`�ޥå�
#define	SPIERR_INVALIDDATA		3		// �ǩ`��������Ƥ���
#define	SPIERR_OUTOFMEMORY		4		// ����`���_�������ʤ�
#define	SPIERR_INVALIDMEMORY	5		// ����`����`��Lock�����ʤ����ȣ�
#define	SPIERR_FILEREAD			6		// �ե������`�ɥ���`
#define	SPIERR_RESERVED			7		// ��s
#define	SPIERR_INTERNAL			8		// �ڲ�����`

// flag
// ׷����� ��xxxx xxxx xxxx xSSS��(��λ3bit����ζ��֤�) SSS�������ηN���ζ����  
// ׷����� ��xxxx xDDD xxxx xSSS��(�ӥåȥե饰�Ȥ���Ҋ��) 
//      SSS        0  Disk File
// (��������ʽ)    1  Memroy Image  
//
//      DDD        0  Disk File
// (�����Ȥ���ʽ)  1  Memroy Image  

#define SPI_IN_MEM_FLAG         0x7
#define SPI_IN_DISK_FLAG        0x0
#define SPI_OUT_MEM_FLAG        0x700
#define SPI_OUT_DISK_FLAG       0x000
#define SPI_INPUT_DISK(x)      (BOOL)!((x) & SPI_IN_MEM_FLAG)
#define SPI_OUTPUT_DISK(x)     (BOOL)!((x) & SPI_OUT_MEM_FLAG)
#define SPI_INPUT_MEM(x)       (BOOL)((x) & SPI_IN_MEM_FLAG)
#define SPI_OUTPUT_MEM(x)      (BOOL)((x) & SPI_OUT_MEM_FLAG)

/*****************************************************************
	���`��Хå�API
*****************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
// Plug-in���v��������ä�
int WINAPI GetPluginInfo(int infono, LPSTR buf,int buflen);

// չ�_���ܤ�(���ꤷ�Ƥ���)�ե�������ʽ���{�٤롣
int WINAPI IsSupported(LPSTR filename,DWORD dw);

// ����ե�������v��������ä�
int WINAPI GetPictureInfo(LPSTR buf, LONG len, UINT flag, TSpiPictureInfo *lpInfo);

// �����չ�_����
int WINAPI GetPicture(LPSTR buf, LONG len, UINT flag,
			   HANDLE *pHBInfo, HANDLE *pHBm,
			   PROGRESSCALLBACK lpProgressCallback, LONG lData);

// �ץ�ӥ�`����������ʾ�û���sСչ�_��`�ƥ���
int WINAPI GetPreview(LPSTR buf, LONG len, UINT flag,
			   HANDLE *pHBInfo, HANDLE *pHBm,
			   PROGRESSCALLBACK lpProgressCallback, LONG lData);

// ���`�������ڤΤ��٤ƤΥե����������ȡ�ä���
int WINAPI GetArchiveInfo(LPSTR buf, LONG len, UINT flag, HLOCAL *lphInf);

// ���`�������ڤ�ָ�������ե����������ȡ�ä���
int WINAPI GetFileInfo(LPSTR buf, LONG len, LPSTR filename,
				UINT flag, TSpiArchiveInfo *lpInfo);

// ���`�������ڤΥե������ȡ�ä���
int WINAPI GetFile(LPSTR src, LONG len, LPSTR dest, UINT flag,
			PROGRESSCALLBACK progressCallback, LONG lData);

// �O������������g��
int WINAPI ConfigurationDlg(HWND parent, int fnc);

#ifdef __cplusplus
}
#endif

/*****************************************************************
	SPI ���ץ��饹(�g�˥����֤��ṩ����)
*****************************************************************/
class CSpi
{
public:
	CSpi();
	virtual ~CSpi();

protected:
	void InitObject();
	void DeleteObject();
public:
	void RecycleObject();

public:
	virtual int GetPluginInfo(int infono, LPSTR buf, int buflen) = 0;
	virtual int IsSupported(LPSTR filename,DWORD dw) = 0;
	virtual int GetPictureInfo(LPSTR buf, LONG len, UINT flag, TSpiPictureInfo *lpInfo);
	virtual int GetPicture(LPSTR buf, LONG len, UINT flag, HANDLE *pHBInfo, HANDLE *pHBm, PROGRESSCALLBACK lpProgressCallback, LONG lData);
	virtual int GetPreview(LPSTR buf, LONG len, UINT flag, HANDLE *pHBInfo, HANDLE *pHBm, PROGRESSCALLBACK lpProgressCallback, LONG lData);
	virtual int GetArchiveInfo(LPSTR buf, LONG len, UINT flag, HLOCAL *lphInf);
	virtual int GetFileInfo(LPSTR buf, LONG len, LPSTR filename, UINT flag, TSpiArchiveInfo *lpInfo);
	virtual int GetFile(LPSTR src, LONG len, LPSTR dest, UINT flag, PROGRESSCALLBACK lpProgressCallback, LONG lData);
	virtual int ConfigurationDlg(HWND parent, int fnc);
};

/*****************************************************************
*****************************************************************/

#endif  /* _INC_SPI */

/* Local Variables:					*/
/* tab-width:4						*/
/* c-indent-level:4					*/
/* c-label-offset:-4				*/
/* c-continued-statement-offset:4	*/
/* file-coding-system:*sjis*dos		*/
/* End:								*/
