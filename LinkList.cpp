//
// Created by markning on 4/28/18.
//
#include "LinkList.h"

Status LinkGetElem(LinkList L, int i, Elemtype &e){
    LinkList p = L->next; int j = 1;
    while(p && j < i){
        p = p->next; ++j;
    }
    if(!p || j > i) return ERROR;
    e = p->data;
    return OK;
}
/*************************************************************/
Status LinkListIns(LinkList L, int i, Elemtype e){
    LinkList p;
    int j = 0;
    p = L;
    while(p && j < i-1){
        p = p->next;
        ++j;
    }
    if(!p || j > i-1) return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
/**************************************************************/
Status LinkListDel(LinkList L, int i, Elemtype &e){
    LinkList p = L;
    int j = 0;
    while(p->next && j < i-1){
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i-1) return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;

}
/******************************************************/
void CreateLinkList(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList tmp;
    tmp = L;
    for(int i = n; i > 0; --i){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        cin >> p->data;
        tmp->next = p;
        tmp = p;

    }
}
/*************************************************************/

/**************************************************/
void TraLinkList(LinkList L){
    LinkList p;
    p = L->next;

    while(p->next != NULL){
        cout << p->data;
        p = p->next;
    }
    cout << p->data;
}













