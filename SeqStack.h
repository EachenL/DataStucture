//
// Created by markning on 4/30/18.
// À≥–Ú’ª
//
#include "head.h"
typedef struct{
    SElemType *base;
    SElemType *top;
    int stackSize;
}SeqStack;

#ifndef DATASTUCTURE_SEQSTACK_H
#define DATASTUCTURE_SEQSTACK_H
Status InitStack(SeqStack &S);
Status StackGetTop(SeqStack S, SElemType &e);
Status StackPush(SeqStack &S, SElemType e);
Status StackPop(SeqStack &S, SElemType &e);
void Conversion();
Status DestroyStack();
Status StackTraverse();
void CptAvgScore();


Status ClearStack();

#endif //DATASTUCTURE_SEQSTACK_H
