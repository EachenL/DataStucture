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