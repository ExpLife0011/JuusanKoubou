/*******************************************************************
	����	:	��Windows����Windows
	����	:	http://bbs.pediy.com/showthread.php?t=84639
	�ļ���	: 	NoWindows.cpp
	����ʱ��:	2009-4-7   17:21
	����޸�:	2009-4-8   13:43

	������ʷ:	2009-4-7	�����ļ�
				2009-4-8	WaitForMultipleObjectsEx�ĵ�2��������CWinThread�ĳ�HANDLE
*********************************************************************/

#pragma comment(linker, "/ENTRY:WinMain")
#pragma comment(linker, "/MERGE:.text=.Rimi /SECTION:.Rimi,ERW")
#pragma comment(linker, "/MERGE:.rdata=.Rimi")
#pragma comment(linker, "/MERGE:.data=.Rimi")
#define _AFXDLL

#include <afxwin.h>
#include <afxmt.h>
#include <vector>
using std::vector;

bool bRepeat = true;
HANDLE hEvent[2];

enum
{
	HIDE,
	TIMER,
};

UINT Thread(LPVOID lpParam)
{
	if ( (DWORD)lpParam == HIDE )
	{
		size_t i;
		HWND hWnd;
		vector<HWND> hWndVec;

		while (bRepeat)
		{
			if (hWnd = GetForegroundWindow())		// ��ȡ����ǰ�Ĵ��ھ��
			{
				if (IsWindowVisible(hWnd) && ShowWindow(hWnd, SW_HIDE))			// ����ô��ڿɼ�
				{
					hWndVec.push_back(hWnd);		// ����ô��ڵľ��
//					ShowWindow(hWnd, SW_HIDE);		// ����֮
				}
			}
			Sleep(200);
		}
/*		i = hWndVec.size();

		while (i--)
		{
			ShowWindow(hWndVec[i], SW_SHOW);		// �����ع��Ĵ���ȫ���ָ�
		}
*/
		for (vector<HWND>::iterator it = hWndVec.begin(); it != hWndVec.end(); ++it)
		{
			ShowWindow(*it, SW_SHOW);
		}
	}
	else
	{
		DWORD dwTimeElapsed = GetTickCount();
		do {}
		while (GetTickCount() - dwTimeElapsed < 30000);		// 30������
		bRepeat = false;
	}
	SetEvent(hEvent[(DWORD)lpParam]);						// ����Ӧ���¼���Ϊ���ź�
	return 0;
}

int WINAPI WinMain ( HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine,
					 int nShowCmd )
{
	if (IDOK == MessageBoxA(NULL,
			"Please keep calm, it's just a joke.\n"
			"All will be back after about 30 seconds.",
			"Tip",
			MB_OKCANCEL|MB_ICONASTERISK))
	{
		CWinThread *hThread[2];
		for (BYTE index = 0; index != 1; ++index)
		{
			hEvent[index] = CreateEvent(NULL, TRUE, FALSE, NULL);
			hThread[index] = AfxBeginThread(Thread, LPVOID(index + HIDE));
		}
		WaitForMultipleObjectsEx(sizeof(hEvent) / sizeof(HANDLE), hEvent, TRUE, INFINITE, FALSE);
		MessageBoxA(NULL,
			"I come back, Just a joke, Don't be serious.",
			"Tip",
			MB_ICONASTERISK);
	}
	return 0;
}