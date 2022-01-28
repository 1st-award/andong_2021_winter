// 배열 a의 모든요소의 순서를 뒤섞는 함수를 작성하세요
#include <stdio.h>
#include <stdlib.h>

int getLength() {
	int length;
	printf("배열 길이 입력 : ");
	scanf("%d", &length);
	return length;
} 

int* getArr(int length) {
	int* arr = calloc(length, sizeof(int));
	int i;
	
	for(i=0; i<length; ++i)
		scanf("%d", arr+i);
	return arr;
}

void shuffleArr(int a[], int n) {
	int i;
	for(i=0; i<n/2; ++i) {
		a[i] = a[i] ^ a[n-i-1];
		a[n-i-1] = a[i] ^ a[n-i-1];
		a[i] = a[n-i-1] ^ a[i];
	}
}

void showArr(int a[], int n) {
	int i;
	for(i=0; i<n; ++i)
		printf("a[%d] : %d\n", i, a[i]);
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	
	puts("==== Before ====");
	showArr(arr, length);
	shuffleArr(arr, length);
	puts("==== After ====");
	showArr(arr, length);
}
