// 요소의 개수가 n개인 배열 arr에서 key와 일치하는 모든 요소의 인덱스 배열 idx의
// 맨 앞부분부터 순서대로 저장하고, 일치한 요소의 개수를 반환하는 함수를 작성하세요
#include <stdio.h>
#include <stdlib.h>

int getLength() {
	int length;
	printf("배열 길이 입력 : ");
	scanf("%d", &length);
	return length;
} 

int* getArr(int length) {
	int* arr = calloc(length+1, sizeof(int));
	int i;
	for(i=0; i<length; ++i)
		scanf("%d", arr+i);
	return arr;
}

int searchIndex(int arr[], int n, int key, int idx[]) {
	int index = -1, i;
	arr[n] = key;
	for(i=0; i<n; ++i) {
		printf("%d %d\n", arr[i], key);
		if(arr[i] == key) {
			index++;
			idx[index] = i;
		}
	}
	return index+1;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int idx[length];
	int resultSearch = searchIndex(arr, length, 9, idx);
	int i;
	for(i=0; i<length; ++i) {
		printf("%2d ", *(idx+i));
	}
	printf("\n%d\n", resultSearch);
} 
