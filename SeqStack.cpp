//
// Created by markning on 4/30/18.
//

#include "SeqStack.h"
Status InitStack(SeqStack &S){
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    S.top = S.base;
    S.stackSize = STACK_INIT_SIZE;
    return OK;
}
/*****************************************/
Status StackGetTop(SeqStack S, SElemType &e){
    if(S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}
/****************************************/
Status StackPush(SeqStack &S, SElemType e){
    if(S.top - S.base >= S.stackSize){
        S.base = (SElemType*)realloc(S.base, (S.stackSize + STACKINCREMENT) * sizeof(SElemType));
        S.top = S.stackSize + S.base;
        S.stackSize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}
/********************************************/
Status StackPop(SeqStack &S, SElemType &e){
    if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
Status StackEmpty(SeqStack S){
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
void Conversion(){//input a >0 int number and output 8bit number
    SeqStack S;
    InitStack(S);
    SElemType N;
    cin >> N;
    SElemType  e = 0;
    while(N){
        StackPush(S, N % 8);
        N = N / 8;
    }
    while(!StackEmpty(S)){
        StackPop(S, e);
        cout << e;
    }
}
