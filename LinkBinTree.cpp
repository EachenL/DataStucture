//
// Created by markning on 8/10/18.
//
#include "LinkBinTree.h"
Status InitLBT(BitNodePtr &T){
    T = (BitNodePtr)malloc(sizeof(BitNode));
    T->lchild = NULL;
    T->rchild = NULL;
}
Status CreLBT(BitNodePtr &T){
    cout << "please input the node value:";
    char n;
    cin >> n;
    BitNodePtr P;
    P = T;
    while(n != ' '){
        InitLBT(P);
        P->data = n;

    }

}
Status PreCreLBT(BitNodePtr T){//T need Init
    int n;
    cin >> n;
    if(n != 0){
        T->data = n;
        InitLBT(T->lchild);
        T = T->lchild;
        PreCreLBT(T);
        InitLBT(T->rchild);
        T = T->rchild;
        PreCreLBT(T);
    }
    free(T);
}
Status DesLBT(BitNodePtr &T){}
Status ClearLBT(BitNodePtr &T){}
Status DepthLBT(BitNodePtr T){}
Status RootLBT(BitNodePtr T){}
Status ValueLBT(BitNodePtr T){}
BitNodePtr ParentLBT(BitNodePtr T, BitNodePtr E){}
BitNodePtr LeftChildLBT(BitNodePtr T, BitNodePtr E){}
BitNodePtr RightChildLBT(BitNodePtr T, BitNodePtr E){}
BitNodePtr LeftBroLBT(BitNodePtr T, BitNodePtr E){}
BitNodePtr RightBroLBT(BitNodePtr T, BitNodePtr E){}
Status InsChild(BitNodePtr T, BitNodePtr P, int LR, BitNodePtr C){}
Status DelChild(BitNodePtr T, int LR, BitNodePtr P){}
Status PreTraLBT(BitNodePtr T){
    Visit(T);
    if(T->lchild != NULL)
        PreTraLBT(T->lchild);
    if(T->rchild != NULL)
        PreTraLBT(T->rchild);
}
Status InTraLBT(BitNodePtr T){
    if(T->lchild != NULL)
        InTraLBT(T->lchild);
    Visit(T);
    if(T->rchild != NULL)
        InTraLBT(T->rchild);
}

Status PostTraLBT(BitNodePtr T){
    if(T->lchild != NULL)
        PostTraLBT(T->lchild);
    if(T->rchild != NULL)
        PostTraLBT(T->rchild);
    Visit(T);
}
Status LevelTraLeT(BitNodePtr T){}
Status Visit(BitNodePtr T){
    cout << T->data;
}
