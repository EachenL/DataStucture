#include "Sort.h"

/*********************************************************************/
void InsertSort(int *R, int n) {//插入排序 *R为待排数组，n为数组长度
	int i, j;
	int temp;
	for (i=1; i<n; ++i) {
		temp = R[i];
		j = i - 1;
		while (j >= 0 && temp < R[j]) {
			R[j + 1] = R[j];
			--j;
		}
		R[j + 1] = temp;
	}
}
/***************************************************************************/
void CoutArray(int *R) {//输出数组元素，元素之间有空格
	for (int i = 0; i < 9; i++) {
		cout << R[i] << " ";
	}
}
/*****************************************************************************/
void GenArray(int *R, int n) {//生成随机数数组 *R为输入数组，n为数组长度
	srand((unsigned)(time(NULL)));
	for (int i = 0; i < n; i++) {
		R[i] = rand();
	}
}
/*****************************************************************************/
