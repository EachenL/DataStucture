#include <iostream>
#include "LinkList.h"


int main() {
    LinkList L;
    CreateLinkList(L,5);
    //1
    LinkListIns(L, 3, 3);
    TraLinkList(L);
    return 0;
}