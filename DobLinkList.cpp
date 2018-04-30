//
// Created by markning on 4/29/18.
//

#include "DobLinkList.h"
/*************************Duble-Link-Insert*******************************/
Status DubLinkIns(DubLinkList &L, int i, Elemtype e){
    DubLinkList p, q, t;
    p = L;
    q = (DubLinkList)malloc(sizeof(DubNode));
    if(i <= DubLinkLength(L)){
        for(int k = 0; k < i-1; k++) p = p->next;
        p->next->prior = q;
        q->prior = p;
        q->next = p->next;
        p->next = q;
        return OK;
    }
    else return ERROR;


}
/****************************Double-Link-Delete*****************************/
Status DubLinkDel(DubLinkList &L, int i){

}
/*****************************Double-Link-Create********************************/
Status DubLinkCreate(DubLinkList &L){
    L = (DubLinkList)malloc(sizeof(DubNode));
    L->prior = NULL;
    DubLinkList q;
    q = L;
    Elemtype i;
    while(i != -1){
        cin >> i;
        if(i != -1){
            DubLinkList p = (DubLinkList) malloc(sizeof(DubNode));
            p->data = i;
            p->prior = q;
            q->next = p;
            q = q->next;
            p->next = NULL;
        }

    }

    return OK;
}
/***************************Double-Link-Merge******************************/
Status DubLinkMerge(DubLinkList &La, DubLinkList &Lb);
Status DubLinkDes(DubLinkList &L);
/***************************Double-Link-Get-Elem*****************************/
Status DubLinkGetElem(DubLinkList &L, int i){
    DubLinkList p = L;
    int q = 0;
    while(q != i){
        p = p->next;
        q++;
    }
    return(p->data);
}
/*************************Double-Link-Locate-Elem*****************************/
int DubLinkLocElem(DubLinkList &L, Elemtype e){
    DubLinkList p = L;
    int i = 0;
    while(p->data != e){
        p = p->next;
        i++;
    }
    return i;
}
/******************Double-Link-Traverse*************************************/
Status DubLinkTra(DubLinkList &L){
    DubLinkList p = L;
    while(p->next != NULL){
        p = p->next;
        cout << p->data;
    }
    return OK;
}
/******************************Double-Link-Length*********************************/
int DubLinkLength(DubLinkList &L){
    DubLinkList p = L;
    int i = 1;
    while(p->next != NULL){
        p = p->next;
        i++;
    }
    return i;
}
//跳过一元多项式的表示和相加