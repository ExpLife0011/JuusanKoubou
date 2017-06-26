#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define MAXPRI 100
#define NIL -1
#define MAX_PROCESS_NUM 3

//进程控制块
struct _tagPCB {
	int id;    //进程号
	char status;  //进程状态，'e'-执行态 'r'-高就绪态  't'-低就绪态 'w'-等待态  'c'-完成态
	int nextwr;   //等待链指针，指示在同一信号量上等待的下一个等待进程的进程号。
	int priority;  //进程优先数，值越小，优先级越高。
}pcb[3];//共3个进程

//s1、s2为三个进程共享的变量；seed为随机值；registeri模拟寄存器值,存放计算的重复次数。
int registeri,s1,s2,seed,exe=NIL;//exe为当前运行（占有cpu）的进程号

//2个信号量sem[0]、sem[1],分别与共享变量s1、s2相联系。
//对应信号量sem[0]、sem[1]分别有两个阻塞队列，队列首由sem[].firstwr指定，队列链指针是pcb[].nextwr
struct{
	int value;//信号量值
	int firstwr;//等待该信号量的阻塞队列的首个进程号
}sem[2];

//三个进程的现场保留区，其中savearea[][0]为寄存器内容，savearea[][1]为下一条指令地址。
char savearea[3][4];

char addr;//当前执行程序的当前指针

int main();
void init();
float random();
int timeint(char ad);
int scheduler();
int find();
int p(int se,char ad);
void block(int se);
int v(int se,char ad);
void wakeup(int se);
void process1();
void process2();
void process3();
void eexit(int n);

//--------------------------------------------------------------------
//主程序
int main()
{
	int currentProcess, i, proc[MAX_PROCESS_NUM] = {0};
	struct _tagPCB *lppcb[MAX_PROCESS_NUM] = {0};

	srand(time(NULL));
	printf("进程管理器\n");
	init();
	printf("s1=%d,s2=%d\n",s1,s2);
	printf("进程1、进程2、进程3已经准备好！\n");
	printf("输入要启动的进程 [1,2,3] : ");

	i = scanf("%d, %d, %d", &proc[0], &proc[1], &proc[2]) - 1;

	for (; i >= 0; --i)
	{
		if (proc[i] > 0 && proc[i] < 4)
		{
			--proc[i];
			lppcb[proc[i]] = &pcb[proc[i]];
		}
	}

	for (;;)
	{
		currentProcess=scheduler(); //进程调度，选择优先级别最高的就绪进程运行。
		if (currentProcess==NIL)
			break;  //所有进程已经运行完毕，结束。
		switch (currentProcess)
		{
		case 0:
			lppcb[currentProcess] ? process1() : eexit(currentProcess);
			break;
		case 1:
			lppcb[currentProcess] ? process2() : eexit(currentProcess);
			break;
		case 2:
			lppcb[currentProcess] ? process3() : eexit(currentProcess);
			break;
		default:
			printf("进程号出错！\n");
			break;
		}
	}
	printf("最后结果：s1=%d,s2=%d\n",s1,s2);
	return getch();
}


//------------------------------------------------------------------------
//初始化
void init()
{
	int i,j;
	//生成进程控制块
	for (j=0;j<3;j++)
	{
		pcb[j].id=j;
		pcb[j].status='r';
		pcb[j].nextwr=NIL;
		i = rand() % (MAXPRI + 1);
		printf("\n进程 %d 的优先数 %d\n",j+1, i);
		pcb[j].priority=i;
	}
	//初始化两个信号量
	sem[0].value=1;//与s1相联系
	sem[0].firstwr=NIL;
	sem[1].value=1;//与s2相联系
	sem[1].firstwr=NIL;
	//初始化现场保留区
	for (i=1;i<3;i++)
		for (j=0;j<4;j++)
			savearea[i][j]='0';
}  //end of init()

//----------------------------------------------------------------------------------
//生成0~1之间随机值
float random()
{
	int m;
	if (seed<0) m=-seed;
	else m=seed;
	seed=(25173*seed+13849)%65536;//seed在每次调用时增大，到一定程度，从头开始。
	return (m/32767.0);
}

//----------------------------------------------------------------------------------
//检测当前进程的时间片是否已到。未到，返回FALSE,否则返回TRUE.系统采用分时执行，
//规定每个进程的执行概率为33%，用产生数x模拟时间片。
//ad为程序的下一条语句地址。
int timeint(char ad)
{
	float x;
	x=random();
	if ((x<0.33)&&(exe==0)) return (FALSE);//当前进程为进程1，时间片未到。
	if ((x<0.66)&&(exe==1)) return (FALSE);//当前进程为进程2，时间片未到。
	if ((x<1)&&(exe==2)) return (FALSE);//当前进程为进程3，时间片未到。
	//时间片已到处理:置正在执行进程状态为低就绪，处理器空闲。
	savearea[exe][0]=registeri;//保存通用寄存器内容
	savearea[exe][1]=ad;//保存程序指针
	pcb[exe].status='t';//状态改为低就绪态
	printf("时间片中断 ，进程%d转入就绪态\n",exe+1);
	exe=NIL;
	return (TRUE);
}

//-----------------------------------------------------------------------------------
//进程调度：选择一个进程投入运行。返回当前进程的进程号。
int scheduler()
{
	int pd;
	//选择投入运行的进程pd
	if ((pd=find())==NIL && exe==NIL)
		return (NIL);//无进程可运行，将结束。
	if (pd!=NIL)
	{
		if (exe==NIL) //选中了进程且处理器空闲，则投入运行。
		{
			pcb[pd].status='e';
			exe=pd;
			printf("进程%d正在执行\n",exe+1);

		}
		else if (pcb[pd].priority<pcb[exe].priority)//选中进程的优选级别高于当前进程
		{
			//将当前进程转入高就绪状态
			pcb[exe].status='r';
			printf("进程%d进入就绪状态\n",exe+1);
			//选中进程pd投入执行
			pcb[pd].status='e';
			exe=pd;
			printf("进程%d正在执行\n",exe+1);
		}
	}
	//恢复进程现场
	registeri=savearea[exe][0];//恢复当前进程的寄存器。
	addr=savearea[exe][1];//恢复执行进程的程序指针
	return (exe);//返回当前进程的进程号
}

//---------------------------------------------------------------------------------
//在3个进程中按就绪状态及其优先数选出进程。返回选出的进程号。
int find()
{
	int j,pd=NIL,w=MAXPRI;
	for (j=0;j<3;j++) //选择高就绪状态优先级最高的进程
	{
		if ((pcb[j].status=='r') && (pcb[j].priority<w))
		{
			w=pcb[j].priority;
			pd=j;
		}
	}
	if (pd==NIL)  //没有高就绪状态的进程，寻找低就绪状态的进程。
	{
		for (j=0;j<3;j++)
		{
			if ((pcb[j].status=='t') && (pcb[j].priority<w))
			{
				w=pcb[j].priority;
				pd=j;
			}
		}
	}
	return (pd);
}

//--------------------------------------------------------------------------------------
//P操作，申请资源。若申请se号资源成功，返回FALSE,若失败，把当前进程挂入se号资源的阻塞队列，
//让出cpu,返回TRUE.
//se为资源号，ad为程序下次执行的地址。
int p(int se,char ad)
{
	if (--sem[se].value>=0)
		return (FALSE);//资源申请成功
	//资源申请失败处理：
	block(se);//把当前进程挂入se号资源的阻塞队列
	savearea[exe][0]=registeri;//保存当前进程的寄存器内容
	savearea[exe][1]=ad;//保存当前进程的下一条指令地址
	exe=NIL;//让出CPU
	return (TRUE);//资源申请失败
}


//----------------------------------------------------------------------------
//把当前进程阻塞，并挂到资源se的阻塞队列。
void block(int se)
{
	int w;
	int i;
	i=(se==0)?1:2;
	printf("进程%d申请s%i时被阻塞\n",exe+1,i);
	pcb[exe].status='w';//当前进程被阻塞
	pcb[exe].nextwr=NIL;
	if ((w=sem[se].firstwr)==NIL)//se资源的阻塞队列空,w为队列的首个进程号。
		sem[se].firstwr=exe;//当前进程为阻塞队列第一个进程
	else
	{
		while(pcb[w].nextwr!=NIL)//寻找队列的最后一个进程w
			w=pcb[w].nextwr;
		pcb[w].nextwr=exe;//将阻塞进程挂到队列尾部
	}
}

//---------------------------------------------------------------------------------------------
//V操作，释放资源se。若无进程等待se资源，返回FALSE;若有进程等待se资源，将该等待进程置为高就绪状态，
//保存当前进程现场，返回TRUE（将引起重新调度）.
//se为资源号，ad为下条指令的地址。
int v(int se,char ad)
{
	if (++sem[se].value>0)
		return (FALSE);//释放资源后，无等待该资源的进程，返回。
	//有进程在等待该资源，则唤醒它。
	wakeup(se);//唤醒等待资源se的进程。
	//保存当前进程（执行态）的现场,因为后面将引起处理器重新调度。
	savearea[exe][0]=registeri;//保存寄存器
	savearea[exe][1]=ad;//保存指令指针
	return (TRUE);
}

//---------------------------------------------------------------------------------------------
//将等待se资源的首个进程置为高就绪状态（唤醒）
void wakeup(int se)
{
	int w;
	int i;
	i=(se==0)?1:2;
	w=sem[se].firstwr;//取资源se阻塞队列的首个进程w
	if (w!=NIL)
	{
		sem[se].firstwr=pcb[w].nextwr;//调整阻塞队列首指针
		pcb[w].status='r';//将w进程置为高就绪态
		printf("进程%d被唤醒,得到资源s%d\n",w+1,i);
	}
}


//-------------------------------------------------------------------------------------------
//进程1的程序代码，完成5次的重复计算：s1=s1+1;s2=s2+1;
//上述的s1、s2与进程2、进程3共享.s1与信号量1相联系，s2与信号量2相联系。
//该程序退出后将进行重新调度。
void process1()
{
	if (addr=='a') goto a1;
	if (addr=='b') goto b1;
	if (addr=='c') goto c1;
	if (addr=='d') goto d1;
	if (addr=='e') goto e1;
	if (addr=='f') goto f1;
	for (registeri=1;registeri<6;registeri++)
	{
		//程序执行s1=s1+1计算。
		//先申请s1变量的使用权，再确保当前时间片尚未结束，就开始计算。计算完毕后释放s1的使用权。
		printf("进程1申请信号量1（与s1相联系）\n");
		if (p(0,'a'))  //若申请失败 ，模拟：当前进程被阻塞，处理器空闲。参数'a'表示下一次执行地址。
			break;//退出for循环，然后退出程序(后面将进行处理器调度)。
		//申请到信号量1
a1: printf("进程1得到s1,正在临界区1\n");
	if (timeint('b')) //检查进程1的时间片是否到。若到，阻塞进程，处理器空闲。参数'b'表示下一次执行地址。
		break;//进程1的时间片到而退出
	//下面是时间片未到或者重新得到时间片时执行
b1: printf("s1=%d\n",++s1); //s1=s1+1
    printf("进程1释放信号量1（与s1相联系）并退出临界区\n");
	if (v(0,'c')) //若没有等待信号量1的进程，到"c1"点继续执行，否则退出。
		break; //后面处理器重新调度

	//程序执行s2=s2+1计算。
c1: printf("进程1申请信号量2（与s2相联系）\n");
    if (p(1,'d'))  //若申请失败 ，当前进程（进程1）被阻塞，处理器空闲。
		break;//退出程序
	//申请到信号量2
d1: printf("进程1得到s2,正在临界区2\n");
	if (timeint('e')) //检查进程1的时间片是否到。若到，阻塞进程1，处理器空闲。
		break;
e1: printf("s2=%d\n",++s2);  //s2=s2+1
    printf("进程1释放信号量2（与s2相联系）并退出临界区\n");
	if (v(1,'f'))
		break;
f1: printf("进程1循环计算次数=%d\n",registeri);
	}

	if (registeri<6) return;
	eexit(0);//结束进程1
}



//----------------------------------------------------------------------------------------
//进程2的程序代码，完成5次的重复计算：s2=s2+1;s1=s1+1;
//上述的s1、s2与进程1、进程3共享.s1与信号量1相联系，s2与信号量2相联系。
//该进程退出后将进行重新调度。
void process2()
{
	if (addr=='a') goto a2;
	if (addr=='b') goto b2;
	if (addr=='c') goto c2;
	if (addr=='d') goto d2;
	if (addr=='e') goto e2;
	if (addr=='f') goto f2;
	for (registeri=1;registeri<6;registeri++)
	{
		//进程执行s2=s2+1计算。
		//先申请s2变量的使用权，再确保当前时间片尚未结束，就开始计算。计算完毕后释放s2的使用权。
		printf("进程2申请信号量2（与s2相联系）\n");
		if (p(1,'a'))  //若申请失败 ，模拟：当前进程（进程2）被阻塞，处理器空闲。
			break;//退出for循环，然后退出程序。
		//申请到信号量2
a2: printf("进程2得到s2,正在临界区2\n");
	if (timeint('b')) //检查进程2的时间片是否到。若到，阻塞进程2，处理器空闲。
		break;//退出
b2: printf("s2=%d\n",++s2); //s2=s2+1
    printf("进程2释放信号量2（与s2相联系）并退出临界区\n");
	if (v(1,'c')) //若没有等待信号量2的进程，到"c2"点继续执行，否则退出。
		break;

	//进程执行s1=s1+1计算。
c2: printf("进程2申请信号量1（与s1相联系）\n");
    if (p(0,'d'))  //若申请失败 ，当前进程（进程2）被阻塞，处理器空闲。
		break;//退出for循环，然后退出程序
	//申请到信号量1
d2: printf("进程2得到s1,正在临界区1\n");
	if (timeint('e')) //检查进程2的时间片是否到。若到，阻塞进程2，处理器空闲。
		break;
e2: printf("s1=%d\n",++s1);  //s1=s1+1
    printf("进程2释放信号量1（与s1相联系）并退出临界区\n");
	if (v(0,'f'))
		break;
f2: printf("进程2循环计算次数=%d\n",registeri);
	}

	if (registeri<6) return;
	eexit(1);//结束进程2
}


//-----------------------------------------------------------------------------------------
//进程3的程序代码，完成5次的重复计算：s2=s2+1;
//上述的s2与进程1、进程2共享.s2与信号量2相联系。
//该进程退出后将进行重新调度。
void process3()
{
	if (addr=='a') goto a3;
	if (addr=='b') goto b3;
	if (addr=='c') goto c3;
	for (registeri=1;registeri<6;registeri++)
	{
		//进程执行s2=s2+1计算。
		//先申请s2变量的使用权，再确保当前时间片尚未结束，就开始计算。计算完毕后释放s2的使用权。
		printf("进程3申请信号量2（与s2相联系）\n");
		if (p(1,'a'))  //若申请失败 ，模拟：当前进程（进程3）被阻塞，处理器空闲。
			break;//退出for循环，然后退出程序。
		//申请到信号量2
a3: printf("进程3得到s2,正在临界区2\n");
	if (timeint('b')) //检查进程3的时间片是否到。若到，阻塞进程3，处理器空闲。
		break;//退出
b3: printf("s2=%d\n",++s2); //s2=s2+1
    printf("进程3释放信号量2（与s2相联系）并退出临界区\n");
	if (v(1,'c')) //若没有等待信号量2的进程，到"c3"点继续执行，否则退出。
		break;

c3: printf("进程3循环计算次数=%d\n",registeri);
	}

	if (registeri<6) return;
	eexit(2);//结束进程3
}

//-------------------------------------------------------------------------------------------
//进程结束。 n为进程号。
void eexit(int n)
{
	pcb[n].status='c';//置进程状态为完成态
	printf("进程%d已经完成\n",n+1);
	exe=NIL;//让出处理器
}
