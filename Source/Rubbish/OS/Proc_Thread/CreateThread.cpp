#include <stdio.h>
#include "pthread.h"
#include <unistd.h>

static int shdata=4;

void *create(void *arg)
{
    printf("new thread ��.\n");
    printf("shared data=%d\n",shdata);
    return 0;
}

int main(int argc, char **argv)
{
    pthread_t threaded;
    int error;
    shdata=5;
    //��Ӵ��봴���̣߳��̵߳�ִ�д���Ϊcreate(),�������ʧ����ʾ����
    error = pthread_create(&threaded, NULL, create, NULL);
    if (error)
    {
        printf("pthread_create() failed.\n");
        return -1;
    }
    _sleep(1);
    printf("new thread is created��.\n");
    return 0;
}