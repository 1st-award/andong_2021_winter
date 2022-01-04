/*
   1 ~ 100���� ������ �Է¹޾� ������������ �����ϴ� ���α׷��� �ۼ��ϼ���. 
*/
#include <stdio.h>
#include <stdlib.h>
 
int getArrayNumber() {
	int number;
	
	printf("�迭�� �� �� �Է�(1 ~ 100) : ");
	scanf("%d", &number);
	
	if(0 > number || number > 100) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}
	return number;
}

int* getArray(int number) {
	int* array = calloc(number, sizeof(int));
	int i;
	
	for(i = 0; i<number; ++i) {
		printf("%d��° �迭 ���� �Է� : ", i+1);
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
