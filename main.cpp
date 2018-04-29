#include <iostream>
#include "LinkList.h"


int main() {
    LinkList La;
    LinkList Lb;
    LinkList Lc;
    CreateLinkList(La, 5);
    CreateLinkList(Lb, 5);
    LinkListIns(La, 3, 3);
    MergeLinkList(La, Lb, Lc);
    TraLinkList(Lc);
    return 0;
}