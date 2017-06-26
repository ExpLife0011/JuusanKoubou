diff --git a/main.c b/_main.c
index aef14ff..b8b3993 100644
--- a/main.c
+++ b/_main.c
@@ -1,11 +1,15 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <time.h>
+#include <conio.h>
 #define TRUE 1
 #define FALSE 0
 #define MAXPRI 100
 #define NIL -1
+#define MAX_PROCESS_NUM 3
 
 //���̿��ƿ�
-struct {     
+struct _tagPCB {
 	int id;    //���̺�
 	char status;  //����״̬��'e'-ִ��̬ 'r'-�߾���̬  't'-�;���̬ 'w'-�ȴ�̬  'c'-���̬
 	int nextwr;   //�ȴ���ָ�룬ָʾ��ͬһ�ź����ϵȴ�����һ���ȴ����̵Ľ��̺š�
@@ -27,7 +31,7 @@ char savearea[3][4];
 
 char addr;//��ǰִ�г���ĵ�ǰָ��
 
-void main();
+int main();
 void init();
 float random();
 int timeint(char ad);
@@ -44,28 +48,44 @@ void eexit(int n);
 
 //--------------------------------------------------------------------
 //������
-void main()
+int main()
 {
-	int currentProcess;
+	int currentProcess, i, proc[MAX_PROCESS_NUM] = {0};
+	struct _tagPCB *lppcb[MAX_PROCESS_NUM] = {0};
+
+	srand(time(NULL));
 	printf("���̹�����\n");
 	init();
 	printf("s1=%d,s2=%d\n",s1,s2);
 	printf("����1������2������3�Ѿ�׼���ã�\n");
+	printf("����Ҫ�����Ľ��� [1,2,3] : ");
+
+	i = scanf("%d, %d, %d", &proc[0], &proc[1], &proc[2]) - 1;
+
+	for (; i >= 0; --i)
+	{
+		if (proc[i] > 0 && proc[i] < 4)
+		{
+			--proc[i];
+			lppcb[proc[i]] = &pcb[proc[i]];
+		}
+	}
+
 	for (;;)
 	{
 		currentProcess=scheduler(); //���̵��ȣ�ѡ�����ȼ�����ߵľ����������С�
-		if (currentProcess==NIL) 
+		if (currentProcess==NIL)
 			break;  //���н����Ѿ�������ϣ�������
 		switch (currentProcess)
 		{
 		case 0:
-			process1();
+			lppcb[currentProcess] ? process1() : eexit(currentProcess);
 			break;
 		case 1:
-			process2();
+			lppcb[currentProcess] ? process2() : eexit(currentProcess);
 			break;
 		case 2:
-			process3();
+			lppcb[currentProcess] ? process3() : eexit(currentProcess);
 			break;
 		default:
 			printf("���̺ų���\n");
@@ -73,6 +93,7 @@ void main()
 		}
 	}
 	printf("�������s1=%d,s2=%d\n",s1,s2);
+	return getch();
 }
 
 
@@ -87,8 +108,8 @@ void init()
 		pcb[j].id=j;
 		pcb[j].status='r';
 		pcb[j].nextwr=NIL;
-		printf("\n���� %d ����������",j+1);
-		scanf("%d",&i);
+		i = rand() % (MAXPRI + 1);
+		printf("\n���� %d �������� %d\n",j+1, i);
 		pcb[j].priority=i;
 	}
 	//��ʼ�������ź���
@@ -148,7 +169,7 @@ int scheduler()
 			pcb[pd].status='e';
 			exe=pd;
 			printf("����%d����ִ��\n",exe+1);
-			
+
 		}
 		else if (pcb[pd].priority<pcb[exe].priority)//ѡ�н��̵���ѡ������ڵ�ǰ����
 		{
@@ -288,11 +309,11 @@ a1: printf("
 	if (timeint('b')) //������1��ʱ��Ƭ�Ƿ񵽡��������������̣����������С�����'b'��ʾ��һ��ִ�е�ַ��
 		break;//����1��ʱ��Ƭ�����˳�
 	//������ʱ��Ƭδ���������µõ�ʱ��Ƭʱִ��
-b1: printf("s1=%d\n",++s1); //s1=s1+1  
+b1: printf("s1=%d\n",++s1); //s1=s1+1
     printf("����1�ͷ��ź���1����s1����ϵ�����˳��ٽ���\n");
 	if (v(0,'c')) //��û�еȴ��ź���1�Ľ��̣���"c1"�����ִ�У������˳���
 		break; //���洦�������µ���
-	
+
 	//����ִ��s2=s2+1���㡣
 c1: printf("����1�����ź���2����s2����ϵ��\n");
     if (p(1,'d'))  //������ʧ�� ����ǰ���̣�����1�������������������С�
@@ -301,13 +322,13 @@ c1: printf("
 d1: printf("����1�õ�s2,�����ٽ���2\n");
 	if (timeint('e')) //������1��ʱ��Ƭ�Ƿ񵽡���������������1�����������С�
 		break;
-e1: printf("s2=%d\n",++s2);  //s2=s2+1 
+e1: printf("s2=%d\n",++s2);  //s2=s2+1
     printf("����1�ͷ��ź���2����s2����ϵ�����˳��ٽ���\n");
 	if (v(1,'f'))
 		break;
 f1: printf("����1ѭ���������=%d\n",registeri);
 	}
-	
+
 	if (registeri<6) return;
 	eexit(0);//��������1
 }
@@ -337,11 +358,11 @@ void process2()
 a2: printf("����2�õ�s2,�����ٽ���2\n");
 	if (timeint('b')) //������2��ʱ��Ƭ�Ƿ񵽡���������������2�����������С�
 		break;//�˳�
-b2: printf("s2=%d\n",++s2); //s2=s2+1  
+b2: printf("s2=%d\n",++s2); //s2=s2+1
     printf("����2�ͷ��ź���2����s2����ϵ�����˳��ٽ���\n");
 	if (v(1,'c')) //��û�еȴ��ź���2�Ľ��̣���"c2"�����ִ�У������˳���
-		break; 
-	
+		break;
+
 	//����ִ��s1=s1+1���㡣
 c2: printf("����2�����ź���1����s1����ϵ��\n");
     if (p(0,'d'))  //������ʧ�� ����ǰ���̣�����2�������������������С�
@@ -350,13 +371,13 @@ c2: printf("
 d2: printf("����2�õ�s1,�����ٽ���1\n");
 	if (timeint('e')) //������2��ʱ��Ƭ�Ƿ񵽡���������������2�����������С�
 		break;
-e2: printf("s1=%d\n",++s1);  //s1=s1+1 
+e2: printf("s1=%d\n",++s1);  //s1=s1+1
     printf("����2�ͷ��ź���1����s1����ϵ�����˳��ٽ���\n");
 	if (v(0,'f'))
 		break;
 f2: printf("����2ѭ���������=%d\n",registeri);
 	}
-	
+
 	if (registeri<6) return;
 	eexit(1);//��������2
 }
@@ -382,14 +403,14 @@ void process3()
 a3: printf("����3�õ�s2,�����ٽ���2\n");
 	if (timeint('b')) //������3��ʱ��Ƭ�Ƿ񵽡���������������3�����������С�
 		break;//�˳�
-b3: printf("s2=%d\n",++s2); //s2=s2+1  
+b3: printf("s2=%d\n",++s2); //s2=s2+1
     printf("����3�ͷ��ź���2����s2����ϵ�����˳��ٽ���\n");
 	if (v(1,'c')) //��û�еȴ��ź���2�Ľ��̣���"c3"�����ִ�У������˳���
-		break; 
-	
+		break;
+
 c3: printf("����3ѭ���������=%d\n",registeri);
 	}
-	
+
 	if (registeri<6) return;
 	eexit(2);//��������3
 }
