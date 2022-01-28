// 이진 검색 알고리즘 프로그램을 검색하였을 때 맨 앞의 결과값을 출력하게 작성하세요
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
	int i, input;
	for(i=0; i<length; ++i) {
		printf("arr[%d] : ", i);
		scanf("%d", arr+i);
	}
	return arr;
}

int searchFirst(const int arr[], int pc, int key) {
	int i, index = -1;
	for(i=pc; i>=0; --i) {
		if(arr[i] == key)
			index = i;
	}
	return index;
}

int binarySearch(const int arr[], int n, int key) {
	int pl = 0;
	int pr = n-1;
	
	do {
		int pc = (pl + pr) / 2;
		
		if(arr[pc] == key) 
			return searchFirst(arr, pc, key);
		else if(arr[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while(pl <= pr);
	return -1;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int result = binarySearch(arr, length, 7);
	printf("%d는 arr[%d]에 있습니다.\n", 7, result);
}
 
