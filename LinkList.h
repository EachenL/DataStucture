

//
// Created by markning on 4/28/18.
// ������
//
#include "head.h"
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode, *LinkList;
#ifndef DATASTUCTURE_LINKLIST_H
#define DATASTUCTURE_LINKLIST_H
Status LinkListIns(LinkList L, int i, Elemtype e);
void CreateLinkList(LinkList &L, int n);

void TraLinkList(LinkList L);
void MergeLinkList(LinkList &La, LinkList &Lb, LinkList &Lc);
Status LinkListDel(LinkList L, int i, Elemtype &e);
Status LinkGetElem(LinkList L, int i, Elemtype &e);
#endif //DATASTUCTURE_LINKLIST_H
