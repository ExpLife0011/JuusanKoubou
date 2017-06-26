#include "CtrlText.h"
#include "ID.h"

SCtrlInfo g_ciCheckBox[] = 
{
    { _T("������Ƶ���Ź���(&9)"),           IDB_AUDIO_PLAY }, 
    { _T("��׼ͼƬ��ʽҲͨ�����ת�����"), IDB_IMAGE_CONVERT },
};

const DWORD g_dwCheckBox = countof(g_ciCheckBox);

SCtrlInfo g_ciRButton[] = 
{
    { _T("��һ֡(&1)"),   IDB_PREV_FRAME  }, 
    { _T("��һ֡(&2)"),   IDB_NEXT_FRAME  }, 
    { _T("RGB(&3)"),      IDB_VIEW_RGB    }, 
    { _T("Alpha(&4)"),    IDB_VIEW_ALPHA  }, 
    { _T("�����ļ�(&E)"), IDB_EXPORT      }, 
    { _T("ȫ������(&A)"), IDB_EXPORT_ALL  }, 
    { _T("����б�"),     IDB_PLUGIN_LIST }, 
};

const DWORD g_dwRButton = countof(g_ciRButton);

SCtrlInfo g_ciLButton[] = 
{
    { _T("����(&6)"), IDB_PLAY  }, 
    { _T("ֹͣ(&7)"), IDB_STOP  }, 
    { _T("��ͣ(&8)"), IDB_PAUSE }, 
};

const DWORD g_dwLButton = countof(g_ciLButton);