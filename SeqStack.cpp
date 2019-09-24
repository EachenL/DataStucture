//
// Created by markning on 4/30/18.
// Ë³ÐòÕ»
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
void CptAvgScore(){
    float a, b, c, d, e;
    int f = 1;
    while(f){
        cout << "please choose option" << endl;
        cin >> f;
        switch(f) {
            case 1:
                cout << "please input course score: ";
                cin >> a;
                cout << "please input grade: ";
                cin >> b;
                c += a;
                d += (b * a);
                e = d / c;
        }
    }
    cout << "your AvgGrade is: " << e;
}
