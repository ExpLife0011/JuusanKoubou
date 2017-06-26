#include "Babylon.h"
#include "ID.h"

#define ____________________MENU_SEPARATOR____________________ { { 0 }, NULL, MF_SEPARATOR },

/************************************************************************/
/* ������˵�                                                           */
/************************************************************************/
SMenuItem Menu_File[] = 
{
    { { FCONTROL|FVIRTKEY, 'I', IDM_FILE_SCRLIST }, _T("�ű��б�(&I)...") },
    { { FCONTROL|FVIRTKEY, 'O', IDM_FILE_OPENSCR }, _T("�򿪽ű�(&O)...") },
    { { FALT|FVIRTKEY,     'C', IDM_FILE_CLOSE   }, _T("�ر��ļ�(&C)...") },

    ____________________MENU_SEPARATOR____________________

    { { FVIRTKEY, VK_ESCAPE, ID_EXIT }, _T("�˳�(&X)") },
};

SMenuItem Menu_Main[] =
{
    { { FROOTMENU,          0,     ID_POPUP }, _T("�ļ�(&F)"), MF_POPUP, Menu_File, countof(Menu_File) },
    { { FROOTMENU|FVIRTKEY, VK_F1, ID_ABOUT }, _T("����(&H)") },
};

DWORD dwMenuCount = countof(Menu_Main);

#undef ____________________MENU_SEPARATOR____________________