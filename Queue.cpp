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
