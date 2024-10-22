//
// Created by eachen on 8/12/18.
//
#include "head.h"
typedef struct BitNode{
    Elemtype data;
    struct BitNode *lchild,*rchild;
}BitNode, *BitNodePtr;
typedef struct TBTNode {
    Elemtype data;
    struct TBTNode* lchild, * rchild;
    int ltag = 0, rtag = 0;
}TBTNode, *TBTNodePtr;
#ifndef DATASTUCTURE_LINKBINTREE_H
#define DATASTUCTURE_LINKBINTREE_H
Status InitLBT(BitNodePtr &T);
Status PreCreLBT(BitNodePtr &T);
Status PreTraLBT(BitNodePtr T);
Status BitVisit(BitNodePtr T);
Status InTraLBT(BitNodePtr T);
Status PostTraLBT(BitNodePtr T);
void SelLBTOpt(BitNodePtr &T);
void level(BitNodePtr T);
void visit(BitNodePtr T);
void visit(TBTNodePtr T);
void PreOrderNonrecursion(BitNodePtr T);
void InThread(TBTNodePtr T);
void CreateInThread(TBTNodePtr root);
#endif //DATASTUCTURE_LINKBINTREE_H
