#include <windows.h>
#include <stdio.h>

typedef unsigned VertexType;
typedef enum GraphType{UDG,DG,UDN,DN};

typedef struct ArcNode
{
	unsigned adjvex;		//ָ��Ķ����λ��
	struct ArcNode *next;	//ָ����һ������ָ��
	int weight;
}ArcNode;

typedef struct
{
	ArcNode *firstarc;		//��һ�������ý��Ļ�
	unsigned adjvex;
//	VertexType data;
}VNode;

typedef struct 
{
	VNode *vertices;
	unsigned vexnum;		//��ǰ������
	unsigned arcnum;		//��ǰ����
	unsigned short type;	//ͼ����
}ALGraph;

void CreateALGraph(ALGraph &G);
void CreateUDG(ALGraph &G);
void Chart(const ALGraph &G);
void BFST(const ALGraph &G);
void DFST(const ALGraph &G);
void DFS(const ALGraph &G,unsigned i,bool *visited);
bool CreateArcNode(ALGraph &G,				//�ڽ�����
				   const unsigned &v1,		//����һ
				   const unsigned &v2,		//�����
				   const int &weight);		//Ȩ