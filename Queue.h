//
// Created by markning on 7/22/18.
// ╤сап
//
#include "head.h"
typedef struct {
    QElemType *head;
    QElemType *tail;
    QElemType length;

}Queue;
#ifndef DATASTUCTURE_QUEUE_H
#define DATASTUCTURE_QUEUE_H
void InitQueue(Queue &);
Status ClearQueue(Queue &);
Status DestroyQueue(Queue &);
Status QueueEmpty(Queue &);
Status QueueLength(Queue &);
Status GetHead(Queue &Q, Status e);
void QueueTest();
Status EnQueue(Queue &Q, Status e);
Status DeQueue(Queue &Q, Status e);
void QueueTraverse();
#endif //DATASTUCTURE_QUEUE_H
