#pragma comment(linker, "/ENTRY:main")
//�û������ڸ��ԵĻ��������γ�����ַ���������spoolserver���������spoolserver����//���󣬴��û�//��������ȡ�������͵�������������������reqblock,�ύ��SPOOLing����ʹ�á�
//SPOOLing����ȡ��ĳreqblock����������Ϣ�����ݴ������ȡ������ӡ���ͷ������Դ��
#include <stdio.h>

#define WELLSIZE 500  //������Ĵ�С
#define FALSE 0
#define TRUE 1

//���̿��ƿ�
struct
{
    int id;//���̱�ʶ��
    char status;//����״̬,'e'Ϊִ��̬��'c'Ϊ���̬��
    int bufflag;//�û�������userbuf���б�־��FALSEΪ�����ݣ�TRUEΪ�����ݡ�
    int filec;//��������Ҫ������ļ������û�ָ����
}pcb[4];//pcb[0]ΪSPOOLing���̣�pcb[1]��pcb[2]��pcb[3]Ϊ3���û�����

//�������飬��10�顣
struct
{
    int reqid;//������̵ı�ʶ��
    int size;//����ļ�����
    int addr;//����ļ��������well��ָ��
}reqblock[10];
int ebp=0;//�����������еĵ�ǰ���п�š�
int ebc=10;//�����������еĵ�ǰ���п���
int cbp=0;//����������ĵ�ǰ������
//ÿ����ҵ��Ҫ���ʱ��Ҫ�����������еǼǡ�������˳���Ǵ�0��9�Ļ��η��䡣
//�������ʱ��Ҫ�����������л�ȡ�������Ϣ��������˳���Ǵ�0��9��������ѭ����

int well[WELLSIZE];//�����
int wellptr=0;//�������ǰָ��,����ָ�롣
int wellsize=WELLSIZE;//�����ʣ���С

int userbuf[3][50];//�û�������
int f[4];//4������������ļ���
int n;//����ļ�����

void main();
void scheduler();
float random() ;
void userpro(int idnum);
int spoolserver(int idnum,int charnum);
void spoolout();


//------------------------------------------------------------------------------
void main()
{
    int i,j;
    printf("SPOOLingϵͳ\n");
    //��ʼ��
    for (i=0;i<WELLSIZE;i++) //��ʼ�������
        well[i]=0;
    for (i=0;i<3;i++)//��ʼ���û�������
        for(j=0;j<50;j++)  userbuf[i][j]=0;
        for (i=0;i<4;i++) //��ʼ�����̿��ƿ�
        {
            pcb[i].id=i;
            pcb[i].status='e';//���н��̳�ʼΪ��ִ��̬
            if (i)  //�����û�����
            {
                pcb[i].bufflag=FALSE;
                printf("�û�%d������ļ�����\n",i);
                scanf("%d",&pcb[i].filec);
                n+=pcb[i].filec;
            }
        }
        for (i=0;i<4;i++)
            f[i]=0;
        //���Ƚ���ִ��
        scheduler();
        printf("�����ļ��Ѿ������������\n");
}

//------------------------------------------------------------------------------------
//���Ƚ���ִ�У�ֱ���������������ϡ�
//�����û����̵ĵ��ȸ���30%��SPOOLing����Ϊ10%��
void scheduler()
{
    float x;
    for (;;)
    {
        x=random();
        if (x<0.3 && pcb[1].status=='e')
            userpro(1);
        else if (x>=0.3 && x<0.6 && pcb[2].status=='e')
            userpro(2);
        else if (x>=0.6 && x<0.9 && pcb[3].status=='e')
            userpro(3);
        else if (x>=0.9 && pcb[0].status=='e')
            spoolout();//ִ��SPOOLing����
        if (n==0)  //�����ļ�������
            break;
    }
}



//-----------------------------------------------------------------------------------
float random() //���������
{
    int m;
    static int seed;
    if ((m=seed)<0)
        m=-m;
    seed=(25173*seed+13849)%65536;
    return (float)(m/32767.0);
}



//-------------------------------------------------------------------------------------
//�ý���ÿ�����в���һ�����Ŵ�����������̶�Ӧ�����������ݣ��������ݡ������͵��������
//idnum�ǽ��̺�
void userpro(int idnum)
{
    int c,j;

    //������idnum�Ļ�����û�����ݣ�Ϊ֮�������ݡ�
    if (pcb[idnum].bufflag==FALSE)
    {
        pcb[idnum].bufflag=TRUE;

        printf("�û�%d���ɵ����ݣ�",idnum);
        for (j=0;j<49;++j)
        {
            c=65+(int)(random()*10.0);//����ַ�
            userbuf[idnum-1][j]=c;
            if (c==65)  //�������ֵΪ0
            {
                userbuf[idnum-1][j]=0;
                break;//���һ���ַ��������ַ����������
            }
            else
                printf("%c",c);
        }
        if (c!=65)//��49���ַ����������һ��Ӧ��Ϊ�ַ����������
            userbuf[idnum-1][j]=0;

        printf("\n");

    }//if (pcb[idnum].bufflag==FALSE)

    //������������ݵ������
    if (spoolserver(idnum,j+1))
        if (--pcb[idnum].filec==0)//�ý��̵�ȫ���ļ��������
        {
            pcb[idnum].status='c';//����Ϊ��ֹ̬
            printf("�û�%d�ĳ��������\n",idnum);
        }
}


//--------------------------------------------------------------------------------
//�Ǽ��������飬���û�������userbuf���������������well���ɹ����룬����TRUE�����򷵻�FALSE.
//idnumΪ���̺�,charnumΪ������ַ�����.
int spoolserver(int idnum,int charnum)
{
    int k;
    if (charnum>wellsize || ebc==0)//�ַ������������ʣ��ռ�Ĵ�С����������Ŀ��п���Ϊ0
        return (FALSE);//�޷����

    //�Ǽ���������
    reqblock[ebp].reqid=idnum;
    reqblock[ebp].size=charnum;
    reqblock[ebp].addr=wellptr;//�ַ���������е���ʼλ��
    ebc--;//����������������һ
    ebp=(++ebp)%10;//���п�ָ��ָ����һ��
    //�������û����������������,��ʼλ�����������ǰָ�����
    for (k=0;k<charnum;++k)
    {
        well[wellptr++]=userbuf[idnum-1][k];
        wellptr=wellptr%WELLSIZE;
    }
    wellsize=wellsize-charnum;
    pcb[idnum].bufflag=FALSE;//���̻�������������
    return (TRUE);
}

//---------------------------------------------------------------------
//SPOOLing���̵ĳ��򣬸���������ȡ�����ݴ�ӡ��
void spoolout()
{
    int id,address,size,c;
    if (ebc<10)  //����������
    { //ȡ����ǰ��������cbp���������
        FILE *fp;
        wchar_t szFileName[256];
        id=reqblock[cbp].reqid;
        swprintf(szFileName, L"�û�%d_%d.txt", id, f[id]);
        fp = _wfopen(szFileName, L"ab");
        size=reqblock[cbp].size;
        address=reqblock[cbp].addr;//���������������ʼλ��
        cbp=(++cbp)%10;//ָ����һ�������(��һ��������Ŀ�)
        printf("����û�%d��%d���ļ�,��С=%d���ַ�:",id,++f[id],size-1);
        address=address%WELLSIZE;
        //�����������
        while((c=well[address++])!=0)
        {
            fputc(c, fp);
            address=address%WELLSIZE;
        }
        printf("\n");
        fclose(fp);
        n--;//����ļ�����һ
        wellsize+=size;//���������ʣ��ռ�
        ebc++;//����������Ŀ��п���һ
    }
}