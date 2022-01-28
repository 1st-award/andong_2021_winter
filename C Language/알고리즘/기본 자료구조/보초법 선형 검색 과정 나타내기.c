// 선형 검색 이캐닝 과정을 상세하게 표시하는 프로그램을 작성하세요
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
	int i, input;
	for(i=0; i<length; ++i) {
		printf("arr[%d] : ", i);
		scanf("%d", arr+i);
	}
	return arr;
}

void showArr(int arr[], int n) {
	int i;
	for(i=0; i<n; ++i)
		printf("%2d", arr[i]);
}

int search(int arr[], int n, int key) {
	int i, j;
	arr[n] = key;
	
	printf("   |");
	for(i=0; i<n; ++i)
		printf("%2d", i);
	printf("\n---+");
	for(i=0; i<n; ++i)
		printf("---");
	puts("");
	for(i=0; i<n; ++i) {
		
		printf("%2c\n", '*');
		// 배열 안의 요소들 출력 
		printf("%3d|", i);
		showArr(arr, n);
		puts("\n   |");
		// 배열 안의 요소가 찾는 값이라면 찾기 종료 
		if(arr[i] == key)
			break;
	}
	return i == n ? -1 : i;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int searchResult = search(arr, length, 3);
	printf("%d은 x[%d]에 존재합니다.\n", 3, searchResult);
} 
