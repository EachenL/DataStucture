#include "map.h"


/*ʹ�õݹ�Ļ����ڽӱ��������������㷨Depth First Search*/
int visit[maxsize];//ȫ�ַ��ʱ�־����
void Visit(int v);//
void DFS(AGraph* G, int v) {
	ArcNode* p;//�߱���ָ��
	visit[v] = 1;//v�����
	Visit(v);
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visit[p->adjvex] == 0)
			DFS(G, p->adjvex);//���ȷ���δ���ʵĽ��
		p = p->nextarc;
	}
}

/*������ȱ���*/
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
����ķ�㷨Prim, ԭ���Ե����
ʹ���ڽӾ���ʵ������������ͼ
�ڹ��������, ��Ҫʹ����������vset[]��lowcost[]
vset[i]=1��ʾ����i�Ѿ���������������, 0��ʾ��δ������
lowcost[j]��ŵ���j������СȨֵ�ߵ�Ȩֵ
���ص�����С��������Ȩֵ֮��
*/

const int INF = 100;
void Prim(MGraph g, int v0, int& sum) {//gΪ�ڽӾ���, v0Ϊ���λ��
	int lowcost[maxsize], vset[maxsize], v;
	int i, j, k, min;
	v = v0;//���ڵ�
	for (i = 0; i < g.ver_num; ++i) {//ver_numͼ�Ľ������
		lowcost[i] = g.edges[v0][i];//����v0�����������������, ����v0������������Ȩֵ����lowcost[]
		vset[i] = 0;
	}
	vset[v0] = 1;//��v0�����vset�е�ֵ��1, ��ʾ�Ѿ����ʹ�
	sum = 0;
	for (i = 0; i < g.ver_num - 1; ++i) {
		min = INF;
		for (j = 0; j < g.ver_num; ++j) {
			if (vset[j] == 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		vset[k] = 1;//�������һ�����е���, ��ʱ��kΪ��v0���ӵ�Ȩֵ��С�Ķ���
		v = k;
		sum += min;
		for (j = 0; j < g.ver_num; j++) {
			if (vset[j] == 0 && g.edges[v][j] < lowcost[j])//���j��㻹δ������, 
				lowcost[j] = g.edges[v][j];//����v��j����ȨֵС��֮ǰ���������µ�j���ıߵ���СȨֵ
				//�ͽ���СȨֵ���������jֵ����
		}
	}
}


/*��³˹�����㷨kruskal
��Ȼ���Ƿ��ص�������ͼ��С��������Ȩֵ֮��
*/
typedef struct {//�洢�ߵĽṹ��
	int a, b;//�ߵ���������
	int w;//Ȩֵ
}Road;
Road road[maxsize];//�ߵļ���
int v[maxsize];//���鼯����
int getRoot(int a) {
	while (a != v[a]) a = v[a];
	return a;
}
void Kruskal(MGraph g, int& sum, Road road[]) {
	int i, a, b;
	sum = 0;
	for (i = 0; i < g.ver_num; ++i) v[i] = i;
	//sort(road, g.side_num);//�Աߵ������㷨��ʱδʵ��
	for (i = 0; i < g.side_num; ++i) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			sum += road[i].w;
		}
	}
}
/*�Ͻ�˹�����㷨*/
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
