// �迭�� �Է¹޾� �հ踦 ���ϴ� ���α׷��� �ۼ��ϼ���
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
	printf("�迭�� �� : %d\n", sum);
}
