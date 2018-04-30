//
// Created by markning on 4/28/18.
//
//#include "LinkList.h"
#include "head.h"

typedef struct{
    Elemtype *elem;
    int length;
    int listSize;

}SeqList;
#ifndef DATASTUCTURE_SEQLIST_H
#define DATASTUCTURE_SEQLIST_H
Status InitSeqList(SeqList &L);
Status SeqListInsert(SeqList &L, int i, Elemtype e);
Status SeqListDel(SeqList &L, int i, Elemtype &e);
int SeqElemLoc(SeqList L, Elemtype e, Status (*compare)(Elemtype, Elemtype));
void SeqMerge(SeqList La, SeqList Lb, SeqList &Lc);
#endif //DATASTUCTURE_SEQLIST_H
