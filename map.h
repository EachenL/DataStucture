#pragma once
#include "FuncHead.h"
#define maxsize 100
/*�ڽӾ�����*/
typedef struct {//�ڽӾ��󶥵���������
	int no;//������
	char info;//������Ϣ
}VertexType;

typedef struct {//�ڽӾ������������
	int edges[maxsize][maxsize];//��ͼ���ڽӾ���, �������Ϊ���������Ȩֵ
	int ver_num, side_num;//ͼ�Ķ������ͱ���
	VertexType vex[maxsize];//��Ŷ�����Ϣ������
}MGraph;

/*�ڽӱ�Adjacency List����*/
typedef struct ArcNode {//�߱��㶨��
	int adjvex;//�߱�����, �û���ָ��Ķ������ڽӱ��е�λ��
	struct ArcNode* nextarc;//����, ָʾ��һ���߻򻡵�ָ��
	int info;//������, ��������Ϣ, ����û���Ȩֵ��Ϣ
}ArcNode;

typedef struct {//�������
	char data;//������Ϣ
	ArcNode* firstarc;//��ָ��, ָ�����Լ����ӵĻ����
}VNode;

typedef struct {//�ڽӱ�
	VNode adjlist[maxsize];//�ڽӱ�
	int n, e;//��ǰ��Ķ������ͻ���
}AGraph;

/*ʮ������Orthogonal List*/
typedef struct ArcBox {//�߱�������
	int headvex, tailvex;//��ͷ�ͻ�β��λ��
	struct ArcBox *hlink, *tlink;//
	/*tlinkָ�����tailvex������һ���뻡, hlinkָ�����headvex������һ������*/
	//int info;//Ȩֵ��Ϣ
};

typedef struct VexNode {//���������
	char data;//������
	ArcBox* firstin, * firstout;//��һ�����ߺ����
}VexNode;

typedef struct {//ʮ������
	VexNode xlist[maxsize];
	int vexnum, arcnum;
}OLGraph;

/*�ڽӶ��ر�*/
typedef enum {unvisited, visited} VisitIf;
typedef struct EBox {//�߱���
	VisitIf mark;//��ʾ�Ƿ��ѱ������� 
	int ivex, jvex;//�ñ����ӵ���������λ��
	struct EBox* ilink, * jlink;//ilinkָ����һ�������ڶ���ivex�ı�
	//jlinkָ����һ�������ڶ���jvex�ı�
	int info;//�ñ�Ȩֵ
}EBox;

typedef struct VexBox {//�������
	int data;//����������
	EBox* firstedge;//�߱����ͷָ��
}VexBox;

typedef struct {
	VexBox adjmulist[maxsize];
	int vexnum, edgenum;//�������ͱ���
}AMLGraph;


void DFS(AGraph* G, int v);

void BFS(AGraph* G, int v, int visit[maxsize]);

void Prim(MGraph g, int v0, int& sum);

int getRoot(int a);

void Kruskal(MGraph g, int& sum, Road road[]);

void printfPath(int path[], int a);

void Dijstra(MGraph g, int v, int dist[], int path[]);

