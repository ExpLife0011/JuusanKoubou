#include "Process.h"
#include "Scheduler.h"

extern INT32 iRegister;
extern LONG  lVal1, lVal2;
extern PCB   pcb[MAX_PROCESS_NUM];
extern FILE *fOutput;

VOID Process1(HANDLE hProcess)
{
	DWORD dwProcessId = MyGetProcessId(hProcess);

	if (pcb[dwProcessId].bFirst == TRUE)
		pcb[dwProcessId].bFirst = FALSE;
	else
		longjmp(pcb[dwProcessId].JumpBuffer, 1);

	for (iRegister = 0; iRegister != PROCESS1_LOOP_COUNT; ++iRegister)
	{
		fprintf(fOutput, "����%d�����ź���1����lValue1����ϵ��\n", dwProcessId);
		if (Proberen(0) == FALSE)		// ������Դʧ��, �ѱ�����ȴ�����
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%d�õ�s1, �����ٽ���1\n", dwProcessId);
		if (GetTimeSlice() == FALSE)	// ʱ��Ƭ�þ�
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "Added by Process %d: lValue1 = %d\n", dwProcessId, ++lVal1);
		fprintf(fOutput, "����%d�ͷ��ź���1����s1����ϵ�����˳��ٽ���\n", dwProcessId);
		if (Verhogen(0) == FALSE)		// �н����ڵȴ�����Դ���ж�,�������ִ��
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%d�����ź���2����s2����ϵ��\n", dwProcessId);
		if (Proberen(1) == FALSE)
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%d�õ�s2, �����ٽ���2\n", dwProcessId);
		if (GetTimeSlice() == FALSE)
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "Added by Process %d: lValue2 = %d\n", dwProcessId, ++lVal2);
		fprintf(fOutput, "����%d�ͷ��ź���2����s2����ϵ�����˳��ٽ���\n", dwProcessId);
		if (Verhogen(1) == FALSE)
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%dѭ��������� = %d\n", dwProcessId, iRegister);
	}

	if (iRegister == PROCESS1_LOOP_COUNT)
		Exit_Process(0);
}

void Process2(HANDLE hProcess)
{
	DWORD dwProcessId = MyGetProcessId(hProcess);

	if (pcb[dwProcessId].bFirst == TRUE)
		pcb[dwProcessId].bFirst = FALSE;
	else
		longjmp(pcb[dwProcessId].JumpBuffer, 1);

	for (iRegister = 0; iRegister != PROCESS2_LOOP_COUNT; ++iRegister)
	{
		fprintf(fOutput, "����%d�����ź���1����lValue1����ϵ��\n", dwProcessId);
		if (Proberen(0) == FALSE)		// ������Դʧ��, �ѱ�����ȴ�����
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%d�õ�s1, �����ٽ���1\n", dwProcessId);
		if (GetTimeSlice() == FALSE)	// ʱ��Ƭ�þ�
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "Added by Process %d: lValue1 = %d\n", dwProcessId, ++lVal1);
		fprintf(fOutput, "����%d�ͷ��ź���1����s1����ϵ�����˳��ٽ���\n", dwProcessId);
		if (Verhogen(0) == FALSE)		// �н����ڵȴ�����Դ���ж�,�������ִ��
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%dѭ��������� = %d\n", dwProcessId, iRegister);
	}

	if (iRegister == PROCESS2_LOOP_COUNT)
		Exit_Process(0);
}

void Process3(HANDLE hProcess)
{
	DWORD dwProcessId = MyGetProcessId(hProcess);

	if (pcb[dwProcessId].bFirst == TRUE)
		pcb[dwProcessId].bFirst = FALSE;
	else
		longjmp(pcb[dwProcessId].JumpBuffer, 1);

	for (iRegister = 0; iRegister != PROCESS3_LOOP_COUNT; ++iRegister)
	{
		fprintf(fOutput, "����%d�����ź���2����lValue2����ϵ��\n", dwProcessId);
		if (Proberen(1) == FALSE)		// ������Դʧ��, �ѱ�����ȴ�����
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%d�õ�s2, �����ٽ���2\n", dwProcessId);
		if (GetTimeSlice() == FALSE)	// ʱ��Ƭ�þ�
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "Added by Process %d: lValue2 = %d\n", dwProcessId, ++lVal2);
		fprintf(fOutput, "����%d�ͷ��ź���2����s2����ϵ�����˳��ٽ���\n", dwProcessId);
		if (Verhogen(1) == FALSE)		// �н����ڵȴ�����Դ���ж�,�������ִ��
		{
			if (!setjmp(pcb[dwProcessId].JumpBuffer))
				break;
		}

		fprintf(fOutput, "����%dѭ��������� = %d\n", dwProcessId, iRegister);
	}

	if (iRegister == PROCESS3_LOOP_COUNT)
		Exit_Process(0);
}