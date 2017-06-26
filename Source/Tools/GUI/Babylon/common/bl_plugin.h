#ifndef _BL_PLUGIN_H_
#define _BL_PLUGIN_H_

#include "bl_common.h"

enum EPluginRet
{
    BL_RET_PLG_NOERROR, 
    BL_RET_PLG_UNSUPPORT, 
};

enum EBLPluginCaps
{
    BL_PLUGIN_CAPS_UNKNOWN = 0, 
};

/************************************************************************/
/* �������                                                             */
/************************************************************************/
enum EBLPuginType
{
    BL_PLUGIN_TYPE_INVALID = 0x00000000,   // ��Ч���
    BL_PLUGIN_TYPE_IMAGE   = 0x00000001,   // ͼƬ���
    BL_PLUGIN_TYPE_AUDIO   = 0x00000002,   // ��Ƶ���
    BL_PLUGIN_TYPE_UNPACK  = 0x00000004,   // ������
    BL_PLUGIN_TYPE_PACK    = 0x00000008,   // ������
    BL_PLUGIN_TYPE_MODULE  = 0x00000010,   // ģ�Ͳ��
    BL_PLUGIN_TYPE_DECODE  = 0x00000020,   // ������
    BL_PLUGIN_TYPE_ENGINE  = 0x00000040,   // ������
};

typedef struct
{
    PCTChar pCopyright;
    PCTChar pPluginDescription;
    PCTChar pRevision;
    PCTChar pAuthor;
    PCTChar pExtraInfo;
    UInt32  PluginType;
    UInt32  Capability;
} SBLPluginInfo;

interface IBLPlugin
{
    virtual Bool   STDCALL GetFileInfo(IN const SBLFileParam *pFileParam, OUT SBLFileInfo *pFileInfo);
    virtual UInt32 STDCALL GetFileData(IN const SBLFileParam *pFileParam, LPVoid lpBuffer, UInt32 BufferSize);
    virtual Void   STDCALL ReleaseAll();
    virtual Bool   STDCALL GetPluginInfo(OUT SBLPluginInfo *pPluginInfo);
};

class CBLPluginBase : public IBLPlugin
{
    ;
};

#endif /* _BL_PLUGIN_H_ */