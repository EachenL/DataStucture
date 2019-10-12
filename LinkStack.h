// 
// Created by markning on 9/24/19.
// 链栈
//

#include "head.h"

typedef struct LsNode{//链栈节点数据抽象类型
	SElemType data;
	struct LsNode *next;
}LsNode, *LsNodePtr;

typedef struct LinkStack{//栈顶指针数据抽象类型
	SElemType depth;
	LsNodePtr top;
}LinkStack, *LinkStackPtr;

Status InitLinkStack(LinkStackPtr);
Status Ls_Push(LinkStackPtr, SElemType);
Status Ls_Pop(LinkStackPtr, SElemType*);
Status LsGetElem(LinkStackPtr p);
//Status Ls_Search();
