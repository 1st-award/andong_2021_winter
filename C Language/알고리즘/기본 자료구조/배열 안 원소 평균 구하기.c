// 배열을 입력받아 평균을 구하는 프로그램을 작성하세요
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

double getAverage(const int* array, int length) {
	double avg = 0.0;
	int i, sum = 0;
	for(i=0; i<length; ++i) {
		sum += *(array + i);
	}
	avg = sum / (double)length;
	return avg;
}

void main() {
	int length = getArrLength();
	int* array = getArray(length);
	double avg = getAverage(array, length);
	printf("평균 : %.2lf\n", avg);
}

