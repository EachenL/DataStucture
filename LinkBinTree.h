//
// Created by eachen on 8/12/18.
//
#include "head.h"
typedef struct BitNode{
    Elemtype data;
    struct BitNode *lchild,*rchild;
}BitNode, *BitNodePtr;
#ifndef DATASTUCTURE_LINKBINTREE_H
#define DATASTUCTURE_LINKBINTREE_H
Status InitLBT(BitNodePtr &T);
Status PreCreLBT(BitNodePtr T);
Status PreTraLBT(BitNodePtr T);
Status Visit(BitNodePtr T);
Status InTraLBT(BitNodePtr T);
Status PostTraLBT(BitNodePtr T);
#endif //DATASTUCTURE_LINKBINTREE_H
