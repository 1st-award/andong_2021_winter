// �迭�� �Է¹޾� �ּڰ��� ���ϴ� �Լ��� �����ϼ���
#include <stdio.h>
#include <stdlib.h>
 
int getArrLength() {
	int length;
	printf("�迭�� ���� �Է� : ") ;
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
	printf("�迭 ���� �� �ּҰ� : %d\n", min);
}
