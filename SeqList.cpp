//
// Created by markning on 4/28/18.
//

#include "SeqList.h"
#include <malloc.h>
#include <cstdlib>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

typedef struct{
    Elemtype *elem;
    int length;
    int listSize;

}SeqList;
/**********************************************/
Status InitSeqList(SeqList &L){
    L.elem = (Elemtype *)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
    if(!L.elem) return(OVERFLOW);
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return 0;
}
/**************************************************/
Status SeqListInsert(SeqList &L, int i, Elemtype e){

    Elemtype *q, *p;

    if(i < 1 || i > L.length)
        return -1;
 /*
    if(L.length >= L.listSize){
        Elemtype *newbase;
        newbase = (Elemtype *)realloc(L.elem, (L.listSize + LISTINCREMENT) * sizeof(Elemtype));
        if(!newbase) return(OVERFLOW);
        L.elem = newbase;
        L.listSize += LISTINCREMENT;
    }
  */
    q = & (L.elem[i-1]);
    for(p = & (L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++L.length;
    return OK;

}
/***************************************************************/
Status SeqListDel(SeqList &L, int i, Elemtype &e){
    if((i < 1) || (i > L.length)) return ERROR;
    Elemtype *p, *q;
    p = & (L.elem[i-1]);
    e = *p;
    q = L.elem + L.length - 1;
    for(++p; p <= q; ++p) *(p - 1) = *p;
    --L.length;
    return OK;

}
/****************************************************************/

int SeqElemLoc(SeqList L, Elemtype e, Status (*compare)(Elemtype, Elemtype)) {
    int i = 1;
    Elemtype *p = L.elem;
    while(i <= L.length && !(*compare)(*p ++, e)) ++i;
    if(i <= L.length) return i;
    else return 0;

}
/******************************************************************/
void SeqMerge(SeqList La, SeqList Lb, SeqList &Lc){
    Elemtype *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La.elem; pb = Lb.elem;
    Lc.listSize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (Elemtype *)malloc(Lc.listSize * sizeof(Elemtype));
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while(pa <= pa_last && pb <= pb_last){
        if(*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;

    }
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
}







