// ���� �˻� �˰��� ���α׷��� �˻��Ͽ��� �� �� ���� ������� ����ϰ� �ۼ��ϼ���
#include <stdio.h>
#include <stdlib.h>

int getLength() {
	int length; 
	printf("�迭 ���� �Է� : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length, sizeof(int));
	int i, input;
	for(i=0; i<length; ++i) {
		printf("arr[%d] : ", i);
		scanf("%d", arr+i);
	}
	return arr;
}

int searchFirst(const int arr[], int pc, int key) {
	int i, index = -1;
	for(i=pc; i>=0; --i) {
		if(arr[i] == key)
			index = i;
	}
	return index;
}

int binarySearch(const int arr[], int n, int key) {
	int pl = 0;
	int pr = n-1;
	
	do {
		int pc = (pl + pr) / 2;
		
		if(arr[pc] == key) 
			return searchFirst(arr, pc, key);
		else if(arr[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while(pl <= pr);
	return -1;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int result = binarySearch(arr, length, 7);
	printf("%d�� arr[%d]�� �ֽ��ϴ�.\n", 7, result);
}
 
