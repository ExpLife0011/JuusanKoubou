#pragma comment(linker,"/ENTRY:main")
#pragma comment(linker,"/MERGE:.text=.Hiromi /SECTION:.Hiromi,ERW")
#pragma comment(linker,"/MERGE:.rdata=.Hiromi")
#pragma comment(linker,"/MERGE:.data=.Hiromi")
#pragma comment(lib, "ntdll.lib")

#include "my_headers.h"
#include <tlhelp32.h>
#include <stdio.h>
#include <conio.h>

EXTC char *_acmdln;

void __cdecl main(int argc, char **argv)
{
    CHAR                       *szCmdLine;
    DWORD                       dwRead, dwMaxBuffer;
    HANDLE                      hSnapshot, hHeap, hProcess;
    BOOL                        Old;
    ANSI_STRING                *lpCmdLine, ansiCmdLine;
    PROCESSENTRY32	            pe;
    PROCESS_BASIC_INFORMATION   ProcessInformation;
    PEB_BASE                   *Peb;
    PWSTR                       

    RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &Old);
    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    pe.dwSize = sizeof(pe);
    if (Process32First(hSnapshot, &pe) == FALSE)
        return;

    szCmdLine = (CHAR *)GetCommandLineA;
    while (1)
    {
        switch ((UCHAR)*szCmdLine++)
        {
        case 0xEB:
            szCmdLine = szCmdLine + *szCmdLine++;
            break;

        case 0xE9:
            szCmdLine = szCmdLine + *(LPDWORD)szCmdLine + 1;
            break;

        case 0xFF:
            szCmdLine = (CHAR *)*(LPDWORD)(szCmdLine + 1);
            szCmdLine = (CHAR *)*(LPDWORD)szCmdLine;
            break;

        default:
            lpCmdLine = (PANSI_STRING)(*(LPDWORD)szCmdLine - 4);
            goto OUT_LOOP;
            break;
        }
    }
OUT_LOOP:

    hHeap = GetProcessHeap();
    dwMaxBuffer = 0;
    szCmdLine = (CHAR *)HeapAlloc(hHeap, 0, 0);

    do
    {
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
        if(hProcess == NULL)
        {
            continue;
        }

        printf("������: %s\n",pe.szExeFile);
        if (ReadProcessMemory(hProcess, (LPCVOID)lpCmdLine, &ansiCmdLine, sizeof(ansiCmdLine), &dwRead))
        {
            if ((DWORD)ansiCmdLine.Length + 1 > dwMaxBuffer)
            {
                dwMaxBuffer = ansiCmdLine.Length + 1;
                szCmdLine = (CHAR *)HeapReAlloc(hHeap, 0, szCmdLine, dwMaxBuffer);
            }
            ReadProcessMemory(hProcess, ansiCmdLine.Buffer, szCmdLine, ansiCmdLine.Length + 1, &dwRead);
            printf("������: %s\n", szCmdLine);
        }
        printf("\n");

    } while (Process32Next(hSnapshot, &pe));

    HeapFree(hHeap, 0, szCmdLine);
    _getch();
}


#if 0

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <conio.h>
#include <my_mem.h>

#pragma comment(linker,"/ENTRY:main")
#pragma comment(linker,"/MERGE:.text=.Hiromi /SECTION:.Hiromi,ERW")
#pragma comment(linker,"/MERGE:.data=.Hiromi")
#pragma comment(linker,"/MERGE:.rdata=.Hiromi")
#pragma comment(lib,"msvcrt6.lib")

//������������Ϣ�ṹ��
typedef struct tagCOMMANDLINEINFO {
    DWORD dwDestCommand_addr;  //Ŀ����������е���ʼ��ַ
    DWORD iDestCommandLength;  //Ŀ����������еĳ���
} COMMANDLINEINFO;
//��������
BOOL UpgradeProcessPrivilege(HANDLE, LPCTSTR);
BOOL GetProcessCommandLineInfo(HANDLE, COMMANDLINEINFO *);

int main()
{
    PROCESSENTRY32	pe;
    BOOL			bFirstProcess = TRUE, bSucceed = FALSE;
    DWORD			dwMaxCmdLen = 0;
    HANDLE			hSnapshot, hProcess, hHeap;
    char			*szDestCommand;
    COMMANDLINEINFO	cli;

    UpgradeProcessPrivilege((HANDLE)-1,SE_DEBUG_NAME); //���������̵�Ȩ��
    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL); //�������̿���
    mem_set(&pe, 0, sizeof(PROCESSENTRY32));
    pe.dwSize = sizeof(PROCESSENTRY32);
    hHeap = GetProcessHeap();
    szDestCommand = (char *)HeapAlloc(hHeap, 0, 0);

    do
    {
        if(bFirstProcess)
        {
            bFirstProcess = !(bSucceed = Process32First(hSnapshot, &pe)); //��ȡ��һ�����̵���Ϣ
        }
        else
        {
            bSucceed = Process32Next(hSnapshot, &pe); //��ȡ��һ�����̵���Ϣ
        }

        if(bSucceed == FALSE)
        {
            continue;
        }

        hProcess = OpenProcess (PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID); //�򿪽���
        if(hProcess == NULL)
        {
            continue;
        }

        printf("������: %s\n",pe.szExeFile);

        mem_set(&cli, 0, sizeof(COMMANDLINEINFO));
        if(GetProcessCommandLineInfo(hProcess,&cli)) //��ȡ���̵���������Ϣ
        {
            {
                if (cli.iDestCommandLength > dwMaxCmdLen)
                {
                    szDestCommand = (char *)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, szDestCommand, cli.iDestCommandLength + 1);
                }
                //��ȡĿ����̵��������ı�
                ReadProcessMemory(hProcess,
                    (const void *)cli.dwDestCommand_addr,
                    szDestCommand,
                    cli.iDestCommandLength,
                    NULL);
                szDestCommand[cli.iDestCommandLength] = 0;
                printf("������: %s\n", szDestCommand);
            }
        }
        printf("\n");

        CloseHandle(hProcess); //�رս��̾��
    } while(bSucceed);

    HeapFree(hHeap, 0, szDestCommand);
    CloseHandle(hSnapshot);  //�رտ��վ��
    getch();
    return 0;
}

BOOL UpgradeProcessPrivilege(HANDLE hProcess,
                             LPCTSTR lpPrivilegeName = SE_DEBUG_NAME)
{
    HANDLE hToken = NULL;
    if(OpenProcessToken(hProcess, TOKEN_ALL_ACCESS, &hToken))
    {
        LUID Luid;
        if(LookupPrivilegeValue(NULL, lpPrivilegeName, &Luid))
        {
            TOKEN_PRIVILEGES tp;
            tp.PrivilegeCount = 1;
            tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            tp.Privileges[0].Luid = Luid;
            return( AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL) );
        }
    }
    return FALSE;
}

BOOL GetProcessCommandLineInfo(HANDLE hProcess, COMMANDLINEINFO *CommandLineInfo)
{
    if(IsBadReadPtr(CommandLineInfo,sizeof(COMMANDLINEINFO))) //�ж�ָ���Ƿ���Ч
        return FALSE;

    HANDLE hThread;

    //����Զ���̣߳�ʹԶ�̽���ִ�� GetCommandLineA ����
    hThread = CreateRemoteThread(hProcess, NULL, 0,
        (LPTHREAD_START_ROUTINE)GetCommandLineA,NULL, 0, NULL);
    if(hThread == 0)
        return FALSE;
    WaitForSingleObject (hThread, INFINITE); //�ȴ�Զ���߳̽���
    //��ȡԶ�� GetCommandLineA �ķ���ֵ�����������أ����ֵΪԶ�̽��������е��׵�ַ
    GetExitCodeThread (hThread, &(CommandLineInfo->dwDestCommand_addr));
    CloseHandle (hThread);
    if(CommandLineInfo->dwDestCommand_addr == 0)
        return FALSE;

    //����Զ���̣߳�ʹԶ�̽���ִ�� lstrlenA ����
    hThread = CreateRemoteThread(hProcess, NULL, 0,(LPTHREAD_START_ROUTINE)lstrlenA,
        (void *)CommandLineInfo->dwDestCommand_addr, 0, NULL);
    if(hThread == 0)
        return FALSE;
    WaitForSingleObject (hThread, INFINITE);
    //��ȡԶ�� lstrlenA �ķ���ֵ�����������أ����ֵΪԶ�̽����������ı��ĳ���
    GetExitCodeThread (hThread, &(CommandLineInfo->iDestCommandLength));
    CloseHandle (hThread);
    return TRUE;
}

#endif /* 0 */