#include <iostream>
#include "FuncHead.h"
int main() {
	int R[9];
	GenArray(R, 9);
	InsertSort(R, 9);
	CoutArray(R);
	while (1);
    return 0;
}