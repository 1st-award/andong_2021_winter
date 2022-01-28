// 배열을 입력받아 최솟값을 구하는 함수를 구현하세요
#include <stdio.h>
#include <stdlib.h>
 
int getArrLength() {
	int length;
	printf("배열의 길이 입력 : ") ;
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

int getMin(const int* array, int length) {
	int min = array[0];
	int i;
	for(i=1; i<length; ++i) {
		if(min > array[i])
			min = array[i];
	}
	return min;
}

void main() {
	int length = getArrLength();
	int* array = getArray(length);
	int min = getMin(array, length);
	printf("배열 원소 중 최소값 : %d\n", min);
}
