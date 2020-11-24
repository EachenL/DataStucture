//
// Created by markning on 8/10/18.
//
#include "LinkBinTree.h"
//#define cirque_maxsiz;//ѭ��������󳤶�
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

void level(BitNodePtr p) {//ʹ�ö��н������Ĳ�α���
    int front, rear;
    BitNodePtr que[cirque_maxsize];
    front = rear = 0;
    BitNodePtr q;//Ԫ�س�������ʱ��ű���
    if (p != NULL) {
        que[rear] = p;
        rear = (rear + 1) % cirque_maxsize;
        while (front != rear) {//��ʼ����Ϊ������ֻ��ָ����ڵ��ָ��
            q = que[front];
            front = (front + 1) % cirque_maxsize;
            visit(q);//���ʵ�ǰ�����ڵ�

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

void PreOrderNonrecursion(BitNodePtr bt) {//ʹ��ջʵ������ǵݹ������
    if (bt != NULL) {
        BitNodePtr Stack[cirque_maxsize];
        int top = -1;//ջ��ָ���ʼֵΪ-1
        BitNodePtr p;
        Stack[++top] = bt;//ջ��0��ʼ����ڵ�, ��һ������������ĸ��ڵ�
        while (top != -1) {//�����ѭ���ĳ�ʼ����Ϊtop=0, ջ�����˳�, top=-1Ϊջ��
            p = Stack[top--];
            visit(p);
            if (p->rchild != NULL)
                Stack[++top] = p->rchild;
            if (p->lchild != NULL)
                Stack[++top] = p->lchild;

        }
    }
}

void InThread(TBTNodePtr p, TBTNodePtr& pre) {//�������������������, ����preΪ��������
    if (p != NULL) {                          //��Ϊ��Ҫ����һ��ݹ���ʹ����һ�㸳����ֵ
        InThread(p->lchild, pre);//������������
        if (p->lchild == NULL) {
            p->lchild = pre;//������õ�pre����, ��������������, ��ô��������������оͲ�����²��pre���ݵ��ϲ�
            p->ltag = 1;

        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;

        }
        pre = p;
        InThread(p->rchild, pre);//������������

    }
}

void CreateInThread(TBTNodePtr root) {//����ͨ��������������������
    TBTNodePtr pre = NULL;//preָ��, �ݹ�ʽ��Ϊ����״̬
    if (root != NULL) {
        InThread(root, pre);
        pre->rchild = NULL;//�����������һ���ڵ�
        pre->rtag = 1;
    }

}

TBTNodePtr First(TBTNodePtr p) {//��������������������һ���ڵ�
    while (p->ltag == 0)
        p = p->lchild;
    return p;
    
}

TBTNodePtr Next(TBTNodePtr p) {//�������������������нڵ�p�ĺ�̽ڵ�
    if (p->rtag == 0)
        return First(p->rchild);
    else
        return p->rchild;
}

void Inorder(TBTNodePtr root) {//������������������
    for (TBTNodePtr p = First(root); p != NULL; p = Next(p))
        visit(p);//
}

















