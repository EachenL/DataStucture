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


/**
普利姆算法Prim, 原理以点求边
使用邻接矩阵实现适用于无向图
在构造过程中, 需要使用两个数组vset[]和lowcost[]
vset[i]=1表示顶点i已经被并入生成树中, 0表示还未被并入
lowcost[j]存放的是j结点的最小权值边的权值
返回的是最小生成树的权值之和
*/

const int INF = 100;
void Prim(MGraph g, int v0, int& sum) {//g为邻接矩阵, v0为结点位置
	int lowcost[maxsize], vset[maxsize], v;
	int i, j, k, min;
	v = v0;//根节点
	for (i = 0; i < g.ver_num; ++i) {//ver_num图的结点总数
		lowcost[i] = g.edges[v0][i];//遍历v0结点与其他结点的连接, 并将v0的与其他结点的权值赋给lowcost[]
		vset[i] = 0;
	}
	vset[v0] = 1;//将v0结点在vset中的值赋1, 表示已经访问过
	sum = 0;
	for (i = 0; i < g.ver_num - 1; ++i) {
		min = INF;
		for (j = 0; j < g.ver_num; ++j) {
			if (vset[j] == 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		vset[k] = 1;//若程序第一次运行到这, 此时的k为与v0连接的权值最小的顶点
		v = k;
		sum += min;
		for (j = 0; j < g.ver_num; j++) {
			if (vset[j] == 0 && g.edges[v][j] < lowcost[j])//如果j结点还未被访问, 
				lowcost[j] = g.edges[v][j];//并且v到j结点的权值小于之前遍历所留下的j结点的边的最小权值
				//就将最小权值数组里面的j值换掉
		}
	}
}


/*克鲁斯卡尔算法kruskal
依然还是返回的是整个图最小生成树的权值之和
*/
typedef struct {//存储边的结构体
	int a, b;//边的两个顶点
	int w;//权值
}Road;
Road road[maxsize];//边的集合
int v[maxsize];//并查集数组
int getRoot(int a) {
	while (a != v[a]) a = v[a];
	return a;
}
void Kruskal(MGraph g, int& sum, Road road[]) {
	int i, a, b;
	sum = 0;
	for (i = 0; i < g.ver_num; ++i) v[i] = i;
	//sort(road, g.side_num);//对边的排序算法暂时未实现
	for (i = 0; i < g.side_num; ++i) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			sum += road[i].w;
		}
	}
}
/*迪杰斯特拉算法*/
void printfPath(int path[], int a) {
	int stack[maxsize], top = -1;
	while (path[a] != -1) {
		stack[++top] = a;
		a = path[a];
	}
	stack[++top];
	while (top != -1)
		cout << stack[top--] << "";
	cout << endl;
}
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
	int set[maxsize];
	int min, i, j, u;
	for (i = 0; i < g.ver_num; ++i) {
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	set[v] = 1;
	path[v] = -1;
	for (i = 0; i < g.ver_num - 1; ++i) {
		min = INF;
		for(j=0;j<g.ver_num;++j)
			if (set[j] == 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		set[u] = 1;
		for (j = 0; j < g.ver_num; ++j) {
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}
	}
}
