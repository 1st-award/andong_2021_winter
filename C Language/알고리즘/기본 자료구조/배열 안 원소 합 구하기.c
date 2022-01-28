// 배열을 입력받아 합계를 구하는 프로그램을 작성하세요
#include <stdio.h>
#include <stdlib.h>

int getArrLength() {
	int length;
	printf("배열 길이 입력 : ");
	scanf("%d", &length);
	return length;
} 

int* getArray(int length) {
	int* array = calloc(length, sizeof(int));
	int i;
	for(i=0; i<length; ++i) {
		scanf("%d", array+i);
	}
	
	return array;
}

int getSum(const int* array, int length) {
	int sum = 0, i;
	
	for(i=0; i<length; ++i) {
		sum += *(array+i);
	}
	return sum;
} 

void main() {
	int length = getArrLength();
	int* array = getArray(length);
	int sum = getSum(array, length);
	printf("배열의 합 : %d\n", sum);
}
