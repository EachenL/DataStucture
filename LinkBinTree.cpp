//
// Created by markning on 8/10/18.
//
#include "LinkBinTree.h"
Status InitLBT(BitNodePtr &T){
    T = (BitNodePtr)malloc(sizeof(BitNode));
    T->lchild = NULL;
    T->rchild = NULL;
}

Status PreCreLBT(BitNodePtr &T){

    int n;
    cin >> n;
    if(n != 0){
        T = (BitNodePtr)malloc(sizeof(BitNode));
        T->data = n;
        PreCreLBT(T->lchild);
        PreCreLBT(T->rchild);
    }

    return 0;
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
void SelLBTOpt(BitNodePtr &T){
    int n = 1;
    while(n != 0){
        cout << "please choose your option" << endl << "1.Init" <<endl<<"2.Pre Cre"<<endl<<"3.Pre Tra"<<endl<<"4.In Tra"<<endl<<"5.Post Tra"<<endl;
        cin >> n;
        switch(n){
            case 1:
                InitLBT(T);
                cout << "Init success "<<endl;
                break;
            case 2:
                cout << "please input your tree:"<<endl;
                PreCreLBT(T);
                cout << "you have cre a bin tree"<<endl;
                break;
            case 3:
                PreTraLBT(T);
                cout<<endl;
                break;
            case 4:
                InTraLBT(T);
                cout<<endl;
                break;
            case 5:
                PostTraLBT(T);
                cout<<endl;
                break;
            default:break;
        }
    }
}