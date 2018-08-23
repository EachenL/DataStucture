//
// Created by markning on 8/23/18.
//

#include "ThreadNode.h"

void PreCreThreadTree(ThreadNodePtr &T) {
    int n;
    cin >> n;
    if (n != 0) {
        T = (ThreadNodePtr) malloc(sizeof(ThreadNode));
        T->data = n;
        PreCreThreadTree(T->lchild);
        PreCreThreadTree(T->rchild);
    }
};

void InitThreadNode(ThreadNodePtr &p) {
    p = (ThreadNodePtr) malloc(sizeof(ThreadNode));
    p->ltag = 0;
    p->rtag = 0;
    p->rchild = NULL;
    p->lchild = NULL;
};

void InOrdTraThreadTree();

void InOrdIndexTreadTree(ThreadNodePtr p, ThreadNodePtr pre) {
    if (p != NULL) {
        InOrdIndexTreadTree(p->lchild, pre);
        if (p->lchild != NULL) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InOrdIndexTreadTree(p->rchild, pre);
    }
};
