#pragma once
#include "FuncHead.h"
#define maxsize 100
typedef struct {//������������
	int no;//������
	char info;//������Ϣ
}VertexType;

typedef struct {//ͼ����������
	int edges[maxsize][maxsize];//��ͼ���ڽӾ���
	int n, e;//ͼ�Ķ������ͱ���
	VertexType vex[maxsize];//��Ŷ�����Ϣ������
}MGraph;

typedef struct ArcNode {//�ڽӱ��ڵ�
	int adjvex;//�ڽӽڵ���, �û���ָ��Ķ������ڽӱ��е�λ��
	struct ArcNode* nextarc;//����, ָʾ��һ���߻򻡵�ָ��
	int info;//������, ��������Ϣ, ����û���Ȩֵ��Ϣ
}ArcNode;

typedef struct {//�ڽӱ�����
	char data;//������Ϣ
	ArcNode* firstarc;//��ָ��, ָ�����Լ����ӵĻ����
}VNode;

typedef struct {//�ڽӱ�
	VNode adjlist[maxsize];//�ڽӱ�
	int n, e;//��ǰ��Ķ������ͻ���
}AGraph;

llll










