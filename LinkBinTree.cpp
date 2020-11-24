//
// Created by markning on 8/10/18.
//
#include "LinkBinTree.h"
//#define cirque_maxsiz;//循环队列最大长度
Status InitLBT(BitNodePtr &T){
    T = (BitNodePtr)malloc(sizeof(BitNode));
    T->lchild = NULL;
    T->rchild = NULL;
	return 0;
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
//Status DesLBT(BitNodePtr &T){}
//Status ClearLBT(BitNodePtr &T){}
//Status DepthLBT(BitNodePtr T){}
//Status RootLBT(BitNodePtr T){}
//Status ValueLBT(BitNodePtr T){}
//BitNodePtr ParentLBT(BitNodePtr T, BitNodePtr E){}
//BitNodePtr LeftChildLBT(BitNodePtr T, BitNodePtr E){}
//BitNodePtr RightChildLBT(BitNodePtr T, BitNodePtr E){}
//BitNodePtr LeftBroLBT(BitNodePtr T, BitNodePtr E){}
//BitNodePtr RightBroLBT(BitNodePtr T, BitNodePtr E){}
//Status InsChild(BitNodePtr T, BitNodePtr P, int LR, BitNodePtr C){}
//Status DelChild(BitNodePtr T, int LR, BitNodePtr P){}
Status PreTraLBT(BitNodePtr T){
    BitVisit(T);
    if(T->lchild != NULL)
        PreTraLBT(T->lchild);
    if(T->rchild != NULL)
        PreTraLBT(T->rchild);
	return 0;
}
Status InTraLBT(BitNodePtr T){
    if(T->lchild != NULL)
        InTraLBT(T->lchild);
    BitVisit(T);
    if(T->rchild != NULL)
        InTraLBT(T->rchild);
	return 0;
}

Status PostTraLBT(BitNodePtr T){
    if(T->lchild != NULL)
        PostTraLBT(T->lchild);
    if(T->rchild != NULL)
        PostTraLBT(T->rchild);
    BitVisit(T);
	return 0;
}
Status LevelTraLeT(BitNodePtr T) { return 0; }
Status BitVisit(BitNodePtr T){
    cout << T->data;
	return 0;
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

void level(BitNodePtr p) {//使用队列进行树的层次遍历
    int front, rear;
    BitNodePtr que[cirque_maxsize];
    front = rear = 0;
    BitNodePtr q;//元素出队列临时存放变量
    if (p != NULL) {
        que[rear] = p;
        rear = (rear + 1) % cirque_maxsize;
        while (front != rear) {//初始条件为队列中只有指向根节点的指针
            q = que[front];
            front = (front + 1) % cirque_maxsize;
            visit(q);//访问当前弹出节点

            if (q->lchild != NULL) {
                que[rear] = q->lchild;
                rear = (rear + 1) % cirque_maxsize;

            }
            if (q->rchild != NULL) {
                que[rear] = q->rchild;
                rear = (rear + 1) % cirque_maxsize;
            }

        }
    }
}

void PreOrderNonrecursion(BitNodePtr bt) {//使用栈实现先序非递归遍历树
    if (bt != NULL) {
        BitNodePtr Stack[cirque_maxsize];
        int top = -1;//栈顶指针初始值为-1
        BitNodePtr p;
        Stack[++top] = bt;//栈从0开始存入节点, 第一个存入的是树的根节点
        while (top != -1) {//进入此循环的初始条件为top=0, 栈空则退出, top=-1为栈空
            p = Stack[top--];
            visit(p);
            if (p->rchild != NULL)
                Stack[++top] = p->rchild;
            if (p->lchild != NULL)
                Stack[++top] = p->lchild;

        }
    }
}

void InThread(TBTNodePtr p, TBTNodePtr& pre) {//中序二叉树线索化函数, 其中pre为引用类型
    if (p != NULL) {                          //因为需要在上一层递归中使用下一层赋给的值
        InThread(p->lchild, pre);//左子树线索化
        if (p->lchild == NULL) {
            p->lchild = pre;//这里会用到pre变量, 若不是引用类型, 那么在下面的线索化中就不会把下层的pre传递到上层
            p->ltag = 1;

        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;

        }
        pre = p;
        InThread(p->rchild, pre);//右子树线索化

    }
}

void CreateInThread(TBTNodePtr root) {//将普通二叉树线索化的主程序
    TBTNodePtr pre = NULL;//pre指针, 递归式均为引用状态
    if (root != NULL) {
        InThread(root, pre);
        pre->rchild = NULL;//处理中序最后一个节点
        pre->rtag = 1;
    }

}

TBTNodePtr First(TBTNodePtr p) {//返回中序线索二叉树第一个节点
    while (p->ltag == 0)
        p = p->lchild;
    return p;
    
}

TBTNodePtr Next(TBTNodePtr p) {//返回中序线索二叉树中节点p的后继节点
    if (p->rtag == 0)
        return First(p->rchild);
    else
        return p->rchild;
}

void Inorder(TBTNodePtr root) {//遍历中序线索二叉树
    for (TBTNodePtr p = First(root); p != NULL; p = Next(p))
        visit(p);//
}

















