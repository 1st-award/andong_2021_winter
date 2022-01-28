// �迭�� �Է¹޾� ����� ���ϴ� ���α׷��� �ۼ��ϼ���
#include <stdio.h>
#include <stdlib.h>

int getArrLength() {
	int length;
	printf("�迭 ���� �Է� : ");
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
	printf("��� : %.2lf\n", avg);
}

