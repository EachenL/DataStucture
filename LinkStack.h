// 
// Created by markning on 9/24/19.
// ��ջ
//

#include "head.h"

typedef struct LsNode{//��ջ�ڵ����ݳ�������
	SElemType data;
	struct LsNode *next;
}LsNode, *LsNodePtr;

typedef struct LinkStack{//ջ��ָ�����ݳ�������
	SElemType depth;
	LsNodePtr top;
}LinkStack, *LinkStackPtr;

Status InitLinkStack(LinkStackPtr);
Status Ls_Push(LinkStackPtr, SElemType);
Status Ls_Pop(LinkStackPtr, SElemType*);
Status LsGetElem(LinkStackPtr p);
//Status Ls_Search();
