#pragma once
#include "FuncHead.h"
#define maxsize 100
/*邻接矩阵定义*/
typedef struct {//邻接矩阵顶点数据类型
	int no;//顶点编号
	char info;//顶点信息
}VertexType;

typedef struct {//邻接矩阵的数据类型
	int edges[maxsize][maxsize];//此图的邻接矩阵
	int n, e;//图的顶点数和边数
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
typedef struct 








