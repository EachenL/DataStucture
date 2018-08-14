//
// Created by markning on 8/10/18.
//
#include "head.h"
typedef struct BitNode{
    Elemtype data;
    struct BitNode *lchild, *rchild;

}BitNode, *BitNodePtr;
#ifndef DATASTUCTURE_LINKBINTREE_H
#define DATASTUCTURE_LINKBINTREE_H
Status InitLBT(BitNodePtr &T);
Status CreLBT(BitNodePtr &T);
Status DesLBT(BitNodePtr &T);
Status ClearLBT(BitNodePtr &T);
Status DepthLBT(BitNodePtr T);
Status RootLBT(BitNodePtr T);
Status ValueLBT(BitNodePtr T);
BitNodePtr ParentLBT(BitNodePtr T, BitNodePtr E);
BitNodePtr LeftChildLBT(BitNodePtr T, BitNodePtr E);
BitNodePtr RightChildLBT(BitNodePtr T, BitNodePtr E);
BitNodePtr LeftBroLBT(BitNodePtr T, BitNodePtr E);
BitNodePtr RightBroLBT(BitNodePtr T, BitNodePtr E);
Status InsChild(BitNodePtr T, BitNodePtr P, int LR, BitNodePtr C);
Status DelChild(BitNodePtr T, int LR, BitNodePtr P);
Status PreTraLBT(BitNodePtr T);
Status InTraLBT(BitNodePtr T);
Status PostTraLBT(BitNodePtr T);
Status LevelTraLeT(BitNodePtr T);
Status Visit(BitNodePtr T);
#endif //DATASTUCTURE_LINKBINTREE_H
