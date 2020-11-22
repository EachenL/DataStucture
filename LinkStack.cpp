// 
// Created by markning on 9/24/19.
// Á´Õ»
//
#include "LinkStack.h"
Status InitLinkStack(LinkStackPtr p) {
	p->top = (LsNodePtr)malloc(sizeof(LsNode));
	p->top->next = NULL;
	p->depth = 1;
	return 0;
}
Status Ls_Push(LinkStackPtr p, SElemType data) {
	LsNodePtr i = (LsNodePtr)malloc(sizeof(LsNode));
	i->data = data;
	i->next = p->top;
	p->top = i;
	p->depth++;
	return 0;
}
Status Ls_Pop(LinkStackPtr p, int *a) {
	if (p->top->next > 1) {
		*a = p->top->data;
		LsNodePtr i;
		i = p->top;
		p->top = p->top->next;
		free(i);
		p->depth--;
	}
	else if(p->depth == 1){
		*a = p->top->data;
		p->depth--;
	}
	else {
		cout << "The stack is empty";
	}
	return 0;
}
Status LsGetElem(LinkStackPtr p) {
	cout << "please input a number";
}