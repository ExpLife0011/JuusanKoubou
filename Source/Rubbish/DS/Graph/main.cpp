#pragma comment(lib,"msvcrt6.lib")
#pragma comment(linker,"/ALIGN:0x1000 /NODEFAULTLIB:LIBC")
#pragma comment(linker,"/MERGE:.data=.text /SECTION:.text,EWR")

#include "Graph.h"

void main()
{
	ALGraph G;
	printf("��������ͼ�Ķ���,��������,ͼ������:\n"
		   "(0.����ͼ 1.����ͼ 2.������ 3.������)\n");
	scanf("%u,%u,%u",&G.vexnum,&G.arcnum,&G.type);
	CreateALGraph(G);
	Chart(G);
	DFST(G);
}