#ifndef _BINARYSPLITTERMSG_H_
#define _BINARYSPLITTERMSG_H_

#include "pragma_once.h"
#include <Windows.h>

#define MAX_PASSWORD_LENGTH 1024

enum
{
    WM_APP_MSG_FIRST = WM_APP,

    WM_APP_SPLIT,
    WM_APP_VERIFY,
    WM_APP_MERGE,

    WM_APP_FORCE_STOP,

    WM_APP_MSG_LAST,
};

#define DLG_SPLIT_STRING_BTN_SPLIT                  _T("�ָ�(&S)")
#define DLG_SPLIT_STRING_BTN_STOP                   _T("ֹͣ(&S)")

#define DLG_MERGE_STRING_BTN_OPEN                   _T("��(&M)")
#define DLG_MERGE_STRING_BTN_MERGE                  _T("�ϲ�(&M)")
#define DLG_MERGE_STRING_BTN_STOP                   DLG_SPLIT_STRING_BTN_STOP

#define CTRL_ERR_STRING_NO_ERROR                    _T("�����ɹ����")

#define CTRL_ERR_STRING_UNKNOWN_ERROR               _T("δ֪����")
#define CTRL_ERR_STRING_INVALID_SLICE_SIZE          _T("��Ч�ķ־��С")
#define CTRL_ERR_STRING_INVALID_INPUT_NAME          _T("��Ч��Դ�ļ�")
#define CTRL_ERR_STRING_INVALID_OUPUT_NAME          _T("��Ч��Ŀ���ļ�")
#define CTRL_ERR_STRING_OUTPUT_ALREADY_EXIST_ASK    _T("Ŀ���ļ��Ѵ���, ȷ��Ҫ������?")

#define CTRL_ERR_STRING_FAILED_FILE_NOT_FOUND       _T("�Ҳ����ļ�")
#define CTRL_ERR_STRING_FAILED_OPEN_FILE            _T("���ļ�ʧ��")
#define CTRL_ERR_STRING_FAILED_CREATE_FILE          _T("�����ļ�ʧ��")
#define CTRL_ERR_STRING_FAILED_GET_SIZE             _T("��ȡ�ļ���Сʧ��")
#define CTRL_ERR_STRING_FAILED_READ_FILE            _T("��ȡ�ļ�ʧ��")
#define CTRL_ERR_STRING_FAILED_WRITE_FILE           _T("д���ļ�ʧ��")
#define CTRL_ERR_STRING_FAILED_CLOSE_FILE           _T("�ر��ļ�ʧ��")
#define CTRL_ERR_STRING_FAILED_IOCP_CREATE          _T("����IO��ɶ˿�ʧ��")
#define CTRL_ERR_STRING_FAILED_IOCP_BIND_DEVICE     _T("�����豸��IO��ɶ˿�ʧ��")
#define CTRL_ERR_STRING_FAILED_IOCP_GET_STATUS      _T("GetQueuedCompletionStatus() ʧ��")
#define CTRL_ERR_STRING_FAILED_QUEUE_ITEM           _T("QueueUserWorkItem() ʧ��")
#define CTRL_ERR_STRING_FAILED_OUT_OF_MEMORY        _T("û���㹻���ڴ���д˲���")
#define CTRL_ERR_STRING_FAILED_INVALID_PARAM        _T("��Ч�Ĳ���")
#define CTRL_ERR_STRING_FAILED_FILE_SIZE_ZERO       _T("ָ���ļ���СΪ0")
#define CTRL_ERR_STRING_FAILED_INVALID_SLICE_SIZE   _T("��Ч�ķ־��С")
#define CTRL_ERR_STRING_FAILED_INVALID_FILE_SIZE    _T("��Ч���ļ���С")
#define CTRL_ERR_STRING_FAILED_INVALID_FORMAT       _T("��Ч�ķָ��ļ�")
#define CTRL_ERR_STRING_FAILED_NOT_FIRST            _T("���ǵ�һ���־�")
#define CTRL_ERR_STRING_FAILED_INVALID_PASSWORD     _T("�������")
#define CTRL_ERR_STRING_FAILED_PART_FILE_CORRUPT    _T("�ļ�����")

#define BS_ERR_STRING_FAILED_OPEN_FILE              CTRL_ERR_STRING_FAILED_OPEN_FILE
#define BS_ERR_STRING_FAILED_READ_FILE              CTRL_ERR_STRING_FAILED_READ_FILE
#define BS_ERR_STRING_FAILED_INVALID_FORMAT         CTRL_ERR_STRING_FAILED_INVALID_FORMAT
#define BS_ERR_STRING_FAILED_NOT_FIRST              CTRL_ERR_STRING_FAILED_NOT_FIRST
#define BS_ERR_STRING_FAILED_INVALID_PASSWORD       CTRL_ERR_STRING_FAILED_INVALID_PASSWORD
#define BS_ERR_STRING_CONFIRM_TO_OVERWRITE          CTRL_ERR_STRING_OUTPUT_ALREADY_EXIST_ASK

#endif // _BINARYSPLITTERMSG_H_