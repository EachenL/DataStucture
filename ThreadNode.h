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
void PreCreThreadTree(ThreadNodePtr &T);
void InitThreadNode(ThreadNodePtr &p);
void FirstNodeInOrdTraThreadTree(ThreadNodePtr P);
void InOrdIndexThreadTree(ThreadNodePtr &p, ThreadNodePtr &pre);
ThreadNodePtr FirstNode(ThreadNodePtr p);
ThreadNodePtr LastNode(ThreadNodePtr p);
void InThread(ThreadNodePtr T);
void TestThread();
ThreadNodePtr NextNode(ThreadNodePtr p);
#endif //DATASTUCTURE_THREADNODE_H
