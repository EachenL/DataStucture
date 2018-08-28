//
// Created by markning on 8/23/18.
//

#include "ThreadNode.h"

void PreCreThreadTree(ThreadNodePtr &T) {
    int n;
    cin >> n;
    if (n != 0) {
        InitThreadNode(T);
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

void FirstNodeInOrdTraThreadTree(ThreadNodePtr P){
    for(ThreadNodePtr p = FirstNode(P); p != NULL; p = NextNode(p))
        cout << p->data;
};
ThreadNodePtr FirstNode(ThreadNodePtr p){
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}
ThreadNodePtr NextNode(ThreadNodePtr p){
    if(p->rtag == 0)
        return FirstNode(p->rchild);
    else return p->rchild;
}
ThreadNodePtr LastNode(ThreadNodePtr p){
    while(p->rtag == 0)
        p = p->rchild;
    return p;
}
void InOrdIndexThreadTree(ThreadNodePtr &p, ThreadNodePtr &pre) {
    if (p != NULL) {
        InOrdIndexThreadTree(p->lchild, pre);
        if (p->lchild == NULL) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InOrdIndexThreadTree(p->rchild, pre);
    }
};
void InThread(ThreadNodePtr T){
    ThreadNodePtr pre = NULL;
    if(T != NULL){
        InOrdIndexThreadTree(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
void TestThread(){
    ThreadNodePtr p;
    cout << "please input your tree" << endl;
    PreCreThreadTree(p);
    cout << "threading..." << endl;
    InThread(p);
    cout << "your tree is: ";
    FirstNodeInOrdTraThreadTree(p);


}