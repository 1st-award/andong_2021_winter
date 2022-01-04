/*
   1 ~ 100개의 정수를 입력받아 오름차순으로 정렬하는 프로그램을 작성하세요. 
*/
#include <stdio.h>
#include <stdlib.h>
 
int getArrayNumber() {
	int number;
	
	printf("배열의 총 량 입력(1 ~ 100) : ");
	scanf("%d", &number);
	
	if(0 > number || number > 100) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	return number;
}

int* getArray(int number) {
	int* array = calloc(number, sizeof(int));
	int i;
	
	for(i = 0; i<number; ++i) {
		printf("%d번째 배열 정수 입력 : ", i+1);
		scanf("%d", &array[i]);
	}
	
	return array;
}

void insertSort(int* array, int num) {
	int i, j;
	
	for(i = 1; i<num; ++i) {
		for(j = 0; j < i; ++j) {
			if(array[i] < array[j]) {
				array[i] = array[i] ^ array[j];
				array[j] = array[i] ^ array[j];
				array[i] = array[j] ^ array[i];
			}
		}
	}
}

void main(void) {
	int num = getArrayNumber();
	int* array = getArray(num);
	insertSort(array, num);
	int i;
	for(i = 0; i<num; ++i) {
		printf("%d ", array[i]);
	}
}
