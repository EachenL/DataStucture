#include <iostream>
//#include "LinkList.h"
#include "DobLinkList.h"


int main() {
//    LinkList La;
//    LinkList Lb;
//    LinkList Lc;
//    CreateLinkList(La, 5);
//    CreateLinkList(Lb, 5);
//    LinkListIns(La, 3, 3);
//    MergeLinkList(La, Lb, Lc);
//    TraLinkList(Lc);
   // free(Lb);
    DubLinkList La;
    DubLinkCreate(La);
    DubLinkTra(La);
    cout << DubLinkLocElem(La, 3);
    cout << DubLinkGetElem(La, DubLinkLocElem(La, 3));
    return 0;
}