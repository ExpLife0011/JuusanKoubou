#include <stdio.h>
void main()
{
	char i;
	int h;
	do
	{
		float a,d,e;
		float b,c;
		printf("������Ҫ�༭��OGG�ļ��Ĳ�����(��λ:KHz):");
Check1:{scanf("%d",&a);
	   if(a<0)
	   {printf("�����ʲ���С����!����������(��λ:KHz):");
	   goto Check1;}
	   }

Check2:{printf("\n������ѭ���Ŀ�ʼʱ��(��λ:��):");
		scanf("%d",&b);
		if(b<0.0)
	   {printf("��ʼʱ�䲻��С����!����������(��λ:��):");
	   goto Check2;}
	   }
		printf("\n������ѭ���Ľ���ʱ��(��λ:��):");
Check3:{scanf("%d",&c);
	 if(c<=b)
	 {printf("\n����ʱ�䲻���ڿ�ʼʱ��,����������(��λ:��):");
	 goto Check3;}
	 }
	 
	 if(c>b)
	 {d=a*b;e=c*a-d;                          
	 printf("loopstart=%f\nlooplength=%f\n\n\n",d,e);
	 }
	 printf("\n�Ƿ�Ҫ����?(Y or N)");
	 scanf("%d",&i);
	 printf("\n");
	 if(i==121 || i==121) h=1;
	 else h=0;
	}
	while(h==1);
}
