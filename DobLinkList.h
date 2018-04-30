#include "SeqList.h"

//
// Created by markning on 4/29/18.
//
typedef struct DubNode{
    Elemtype data;
    struct DubNode *prior;
    struct DubNode *next;
}DubNode, *DubLinkList;
#ifndef DATASTUCTURE_DOBLINKLIST_H
#define DATASTUCTURE_DOBLINKLIST_H
Status DubLinkIns(DubLinkList &L, int i, Elemtype e);
Status DubLinkDel(DubLinkList &L, int i);
Status DubLinkCreate(DubLinkList &L);
Status DubLinkMerge(DubLinkList &La, DubLinkList &Lb);
Status DubLinkDes(DubLinkList &L);
Status DubLinkGetElem(DubLinkList &L, int i);
Status DubLinkLocElem(DubLinkList &L, Elemtype e);
Status DubLinkTra(DubLinkList &L);
int DubLinkLength(DubLinkList &L);
#endif //DATASTUCTURE_DOBLINKLIST_H
