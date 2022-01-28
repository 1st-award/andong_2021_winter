// �迭 b�� ��� ��Ҹ� �迭 a�� �������� �����ϴ� �Լ��� �ۼ��ϼ���
#include <stdio.h>
#include <stdlib.h>

void reverseCopyArr(int a[], int b[], int n) {
	int i;
	for(i=0; i<n; ++i)
		a[i] = b[n-i-1];
} 

int getArrLength() {
	int length;
	printf("�迭 ���� �Է� : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length, sizeof(int));
	int i;
	for(i=0; i<length; ++i) {
		scanf("%d", arr+i);
	}
	return arr;
} 

void showArr(int a[], int n) {
	int i;
	for(i=0; i<n; ++i)
		printf("a[%d] : %d\n", i, a[i]);
}

void main() {
	int length = getArrLength();
	int* a = calloc(length, sizeof(int));
	int* b = getArr(length);
	reverseCopyArr(a, b, length);
	showArr(a, length);
}
