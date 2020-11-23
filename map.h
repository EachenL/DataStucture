#pragma once
#include "FuncHead.h"
#define maxsize 100
typedef struct {//顶点数据类型
	int no;//顶点编号
	char info;//顶点信息
}VertexType;

typedef struct {//图的数据类型
	int edges[maxsize][maxsize];//此图的邻接矩阵
	int n, e;//图的顶点数和边数
	VertexType vex[maxsize];//存放顶点信息的数组
}MGraph;

typedef struct ArcNode {//邻接表弧节点
	int adjvex;//邻接节点域, 该弧所指向的顶点在邻接表中的位置
	struct ArcNode* nextarc;//链域, 指示下一条边或弧的指针
	int info;//数据域, 存放相关信息, 比如该弧的权值信息
}ArcNode;

typedef struct {//邻接表顶点结点
	char data;//顶点信息
	ArcNode* firstarc;//弧指针, 指向与自己链接的弧或边
}VNode;

typedef struct {//邻接表
	VNode adjlist[maxsize];//邻接表
	int n, e;//当前表的顶点数和弧数
}AGraph;

llll










