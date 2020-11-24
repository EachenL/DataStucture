#include "map.h"


/*使用递归的基于邻接表的深度优先搜索算法Depth First Search*/
int visit[maxsize];//全局访问标志数组
void Visit(int v);//
void DFS(AGraph* G, int v) {
	ArcNode* p;//边表结点指针
	visit[v] = 1;//v起点编号
	Visit(v);
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visit[p->adjvex] == 0)
			DFS(G, p->adjvex);//率先访问未访问的结点
		p = p->nextarc;
	}
}

/*广度优先遍历*/
void BFS(AGraph* G, int v, int visit[maxsize]) {
	ArcNode* p;
	int que[maxsize], front = 0, rear = 0;
	int j;
	Visit(v);
	visit[v] = 1;
	que[rear] = v;
	rear = (rear + 1) % maxsize;
	//que[rear] = v;
	while (front != rear) {
		//front = (front + 1) % maxsize;
		j = que[front];
		front = (front + 1) % maxsize;
		p = G->adjlist[j].firstarc;
		while (p != NULL) {
			if (visit[p->adjvex] == 0) {
				Visit(p->adjvex);
				visit[p->adjvex] = 1;
				//rear = (rear + 1) % maxsize;
				que[rear] = p->adjvex;
				rear = (rear + 1) % maxsize;
			}
			p = p->nextarc;
		}
	}
}