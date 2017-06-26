#ifndef _BL_COMMON_H_
#define _BL_COMMON_H_

#include <Windows.h>
#include "my_headers.h"

#ifdef _DLL
    #define BL_API EXTC __declspec(dllexport)
#else
    #define BL_API EXTC __declspec(dllimport)
#endif

#define BL_STRING_ABOUT_MESSAGE    _T("Amano")
#define BL_STRING_CONFIG_FILE_NAME _T("Babylon.xml")
#define BL_STRING_SCRIPT_PATH      _T("script\\")
#define BL_STRING_PLUGIN_PATH      _T("plugin\\")

#define BL_FAILED(Result) (((Long)(Result)) < 0)
#define BL_SUCCEEDED(Result) (!BL_FAILED(Result))

enum // BLErrorCode
{
    BL_ERROR_SUCCEES = 0,

    BL_ERROR_BASE    = 0x80000000,

    BL_ERROR_UNKNOWN = BL_ERROR_BASE,
    BL_ERROR_INVALID_PARAMETER,
    BL_ERROR_INVALID_FORMAT,
    BL_ERROR_NOT_ENOUGH_BUFFER,
    BL_ERROR_IO_FAILED,
    BL_ERROR_OUT_OF_MEMORY,
};

inline PTChar BLNewString(PTChar pszString, ULong Length = -1)
{
    if (Length == -1)
        Length = StrLength(pszString);
    else
        ++Length;

    PTChar pStringBuffer = (PTChar)HeapAlloc(GetProcessHeap(), 0, (Length + 1) * sizeof(TChar));
    if (pStringBuffer != NULL)
    {
        memcpy(pStringBuffer, pszString, Length * sizeof(TChar));
        pStringBuffer[Length] = 0;
    }
    
    return pStringBuffer;
}

inline Void BLFreeString(PTChar &pszString)
{
    if (pszString != NULL)
    {
        HeapFree(GetProcessHeap(), 0, pszString);
        pszString = NULL;
    }
}

/*****************************************************************************
 *  ��������
 *****************************************************************************/
enum EExportType
{
    BL_EXPORT_TYPE_UNKNOWN, // δ֪�ļ�
    BL_EXPORT_TYPE_IMAGE,   // ͼƬ�ļ�
    BL_EXPORT_TYPE_AUDIO,   // ��Ƶ�ļ�
    BL_EXPORT_TYPE_PACK,    // ����ļ�
    BL_EXPORT_TYPE_MODULE,  // ģ���ļ�
    BL_EXPORT_TYPE_TEXT,    // �ı��ļ�
    BL_EXPORT_TYPE_BINARY,  // ��ͨ�ļ�
};

/************************************************************************/
/* �ļ���Ϣ�ṹ, �����д                                               */
/************************************************************************/
typedef struct
{
    // ͼƬ
    UInt32   Width;       // ͼƬ��
    UInt32   Height;      // ͼƬ��

    // ����
    UInt32   Count;       // ���ļ�����
                          // ͼƬ�ļ�: ֡��
                          // ����ļ�: ���ļ�����
                          // ģ���ļ�: ��������

    UInt32   Size;        // �ļ���С
    UInt32   Type;        // �����ļ�����
    PWChar*  ppInfo;      // �ļ���Ϣ
                          // ����ļ�: ���ļ����б�
                          // ��ͨ�ļ�: ��һ��Ϊ˵����
                          //           �ڶ���Ϊ��չ��
} SBLFileInfo;

/************************************************************************/
/* �ļ���ȡ�����ṹ, ��������д                                         */
/************************************************************************/
typedef struct
{
    LPCVoid data;       // �ļ�����
    UInt32  size;       // =0 ��ʾ data Ϊ�ļ���(WChar)
                        // ����ʱ�����ǵ����ļ��Ĵ�С
    PVoid   pExtra;     // ��������
    UInt32  pakIndex;   // ���ļ�������(��TreeView���˳��, ��ѡ)
    UInt32  fileIndex;  // ���ļ�������
    UInt32  head;       // �ļ���ʼƫ��
    UInt32  tail;       // �ļ�����ƫ��
    PWChar  path;       // �����ļ���ȫ·���ļ���
                        // ��/�����ļ�Ϊ NULL
    PWChar  node;       // TreeView �Ľڵ���
                        // ���ļ�ʱΪѡ���ļ��Ľڵ���
                        // ���������ڶ��ļ�ʱ�޸���ʾ���ļ���
    HWND    hWnd;       // �����ڵľ��
} SBLFileParam;

#endif /* _BL_COMMON_H_ */
