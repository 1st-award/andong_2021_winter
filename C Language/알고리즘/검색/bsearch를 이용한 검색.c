// 내림차순으로 정렬된 배열을 bsearch 함수를 통해 검색하세요
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* a, const int* b) {
	return *a > *b ? -1 : *a < *b ? 1 : 0;
} 

int getLength() {
	int length;
	printf("배열 길이 입력 : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length, sizeof(int));
	int i;
	
	puts("내림차순으로 입력");
	printf("arr[0] : ");
	scanf("%d", arr); 
	for(i=1; i<length; ++i) {
		do {
			printf("arr[%d] : ", i);
			scanf("%d", arr+i);
		} while(arr[i-1] < arr[i]);
	}
	return arr;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int key;
	int* result;
	
	printf("검색 값 : ");
	scanf("%d", &key);
	result = bsearch(&key, arr, length, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	
	if(result != NULL)
		printf("%d는 arr[%d]에 있습니다.\n", key, (int)(result-arr));
	else
		puts("검색에 실패했습니다.");
}
