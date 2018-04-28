#include "SeqList.h"

//
// Created by markning on 4/28/18.
//
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode, *LinkList;
#ifndef DATASTUCTURE_LINKLIST_H
#define DATASTUCTURE_LINKLIST_H
Status LinkListIns(LinkList L, int i, Elemtype e);
void CreateLinkList(LinkList &L, int n);
void TraLinkList(LinkList L);
#endif //DATASTUCTURE_LINKLIST_H
