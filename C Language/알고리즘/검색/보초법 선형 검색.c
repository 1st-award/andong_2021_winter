// 보초법 선형 검색을 for문을 통해 작성하세요 
#include <stdio.h>
#include <stdlib.h>

int getLength() {
	int length;
	printf("배열 길이 입력 : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length + 1
	, sizeof(int));
	int i, input;
	puts("오름차순으로 입력");
	scanf("%d", arr);
	for(i=1; i<length; ++i) {
		do {
			scanf("%d", &input);
			arr[i] = input;
		} while(arr[i-1] > input);
	}
	return arr;
}

int search(int arr[], int n, int key) {
	int i = 0;
	arr[n] = key;
	for(i=0; i<n; ++i) {
		if(key == arr[i])
			break;
	}
	return i == n ? -1 : i;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int resultSearch = search(arr, length, 3);
	printf("%d(은)는 arr[%d]에 있습니다.\n", 3, resultSearch);
}
