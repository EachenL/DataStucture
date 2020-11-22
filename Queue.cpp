//
// Created by markning on 7/22/18.
//
#include "Queue.h"
void InitQueue(Queue &Q){
    Q.head = (QElemType*)malloc(sizeof(Queue) * QUEUE_INIT_SIZE);
    Q.tail = Q.head;
    Q.length = QUEUE_INIT_SIZE;
}
Status QueueEmpty(Queue &Q){
    if (Q.head == Q.tail)
        return ERROR;
    else
        return OK;
}
Status EnQueue(Queue &Q, Status e){
    if (Q.tail - Q.head >= Q.length){
        Q.head = (QElemType*)realloc(Q.head, sizeof(Queue) * QUEUE_INIT_SIZE + QUEUEINCREMENT);
        Q.length += QUEUEINCREMENT;
    }
    if (Q.head != NULL){
       *Q.tail++ = e;
    }
	return 0;
}
Status GetHead(Queue &Q, Status e){
    if(QueueEmpty(Q) == ERROR)
        return ERROR;
    e = *Q.head;
    return e;
}
Status ClearQueue(Queue &Q){

    if(QueueEmpty(Q) == ERROR)
        return ERROR;
    Q.tail = Q.head;
    return OK;
}
Status DestroyQueue(Queue &Q){
    if (Q.head != NULL){
        free(Q.head);
        return OK;
    }
    else
        return ERROR;
}
Status QueueLength(Queue &Q){
    Status e = Q.tail - Q.head;
    return e;
}
Status DeQueue(Queue &Q, Status e){
    if(QueueEmpty(Q) == ERROR)
        return ERROR;
    QElemType *p = Q.head;
    e = *Q.head++;
    free(p);
    Q.length--;
    return e;
}

void QueueTraverse(Queue &Q){
    while(Q.tail-Q.head >= 0){
        cout << *Q.tail--;
    }
}
void QueueTest(){
    Queue Q;
    int e = 1;
    while(e){
        cout << "please choose the option"<<endl;
        cout << "1. InitQueue"<<endl << "2. DestroyQueue"<<endl <<"3. ClearQueue"<<endl;
        cout << "4. QueueEmpty"<<endl << "5. QueueLength"<<endl << "6. GetHead"<<endl;
        cout << "7. EnQueue"<<endl << "8. DeQueue"<<endl << "9. QueueTraverse"<<endl;
        cin >> e;
        switch (e){
            case 1:

                InitQueue(Q);
                cout << "your queue has been initial"<<endl;
                break;
            case 2:
                DestroyQueue(Q);
                cout << "your queue has been destroyed"<<endl;
                break;
            case 3:
                ClearQueue(Q);
                cout << "your queue has been cleared"<<endl;
                break;
            case 4:
                QueueEmpty(Q);
                break;
            case 5:
                cout << "the queue length is " <<QueueLength(Q)<<endl;
                break;
            case 6:
                int a;
                GetHead(Q,a);
                cout <<"the head elem is " << a<<endl;
                break;
            case 7:
                int b;
                cout << "please input the number u want insert"<<endl;
                cin >> b;
                EnQueue(Q,b);
                break;
            case 8:
                int c;
                DeQueue(Q,c);
                cout << "the head elem is " << c<<endl;
                break;
            case 9:
                cout << "your queue is "<<endl ;
                QueueTraverse(Q);
                cout << endl;
                break;
            default:
                break;

        }
    }
}
