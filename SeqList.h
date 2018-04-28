//
// Created by markning on 4/28/18.
//
#include "SeqList.h"
#include <malloc.h>
#include <cstdlib>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

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
