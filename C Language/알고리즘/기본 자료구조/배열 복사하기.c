// �迭 b�� ��� ��Ҹ� �迩 a�� �����ϴ� �Լ��� �ۼ��ϼ���
#include <stdio.h>
#include <stdlib.h>

void copyArr(int a[], int b[], int n) {
	int i;
	for(i=0; i<n; ++i)
		a[i] = b[i];
} 

void showArr(int a[], int n) {
	int i;
	for(i=0; i<n; ++i)
		printf("a[%d] : %d\n", i, a[i]);
}

int getArrLength() {
	int length;
	printf("�迭 ���� �Է� : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int i;
	int* arr = calloc(length, sizeof(int)); 
	for(i=0; i<length; ++i) {
		scanf("%d", arr+i);
	}
	
	return arr;
} 

void main() {
	int length = getArrLength();
	int* a = calloc(length, sizeof(int));
	int* b = getArr(length);
	copyArr(a, b, length);
	showArr(a, length);
}
