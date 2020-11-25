#pragma once
#include "FuncHead.h"
#define maxsize 100
/*邻接矩阵定义*/
typedef struct {//邻接矩阵顶点数据类型
	int no;//顶点编号
	char info;//顶点信息
}VertexType;

typedef struct {//邻接矩阵的数据类型
	int edges[maxsize][maxsize];//此图的邻接矩阵, 存入的数为连接情况或权值
	int ver_num, side_num;//图的顶点数和边数
	VertexType vex[maxsize];//存放顶点信息的数组
}MGraph;

/*邻接表Adjacency List定义*/
typedef struct ArcNode {//边表结点定义
	int adjvex;//边表结点域, 该弧所指向的顶点在邻接表中的位置
	struct ArcNode* nextarc;//链域, 指示下一条边或弧的指针
	int info;//数据域, 存放相关信息, 比如该弧的权值信息
}ArcNode;

typedef struct {//顶点表结点
	char data;//顶点信息
	ArcNode* firstarc;//弧指针, 指向与自己链接的弧或边
}VNode;

typedef struct {//邻接表
	VNode adjlist[maxsize];//邻接表
	int n, e;//当前表的顶点数和弧数
}AGraph;

/*十字链表Orthogonal List*/
typedef struct ArcBox {//边表结点类型
	int headvex, tailvex;//弧头和弧尾的位置
	struct ArcBox *hlink, *tlink;//
	/*tlink指向的是tailvex结点的下一条入弧, hlink指向的是headvex结点的下一个出弧*/
	//int info;//权值信息
};

typedef struct VexNode {//顶点表类型
	char data;//数据域
	ArcBox* firstin, * firstout;//第一条出边和入边
}VexNode;

typedef struct {//十字链表
	VexNode xlist[maxsize];
	int vexnum, arcnum;
}OLGraph;

/*邻接多重表*/
typedef enum {unvisited, visited} VisitIf;
typedef struct EBox {//边表结点
	VisitIf mark;//表示是否已被搜索过 
	int ivex, jvex;//该边连接的两个结点的位置
	struct EBox* ilink, * jlink;//ilink指向下一条依附于顶点ivex的边
	//jlink指向下一条依附于顶点jvex的边
	int info;//该边权值
}EBox;

typedef struct VexBox {//顶点表结点
	int data;//顶点数据域
	EBox* firstedge;//边表结点的头指针
}VexBox;

typedef struct {
	VexBox adjmulist[maxsize];
	int vexnum, edgenum;//顶点数和边数
}AMLGraph;


void DFS(AGraph* G, int v);

void BFS(AGraph* G, int v, int visit[maxsize]);

void Prim(MGraph g, int v0, int& sum);

int getRoot(int a);

void Kruskal(MGraph g, int& sum, Road road[]);

void printfPath(int path[], int a);

void Dijstra(MGraph g, int v, int dist[], int path[]);

