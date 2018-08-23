//
// Created by markning on 8/23/18.
//
#include "head.h"
typedef struct ThreadNode{
    Elemtype data;
    int ltag, rtag;
    struct ThreadNode *lchild, *rchild;
}ThreadNode, *ThreadNodePtr;
#ifndef DATASTUCTURE_THREADNODE_H
#define DATASTUCTURE_THREADNODE_H
void PreCreThreadTree();
void InitThreadNode();
void InOrdTraThreadTree();
void InOrdIndexTreadTree();
#endif //DATASTUCTURE_THREADNODE_H
