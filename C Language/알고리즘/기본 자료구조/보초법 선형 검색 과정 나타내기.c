// ���� �˻� ��ĳ�� ������ ���ϰ� ǥ���ϴ� ���α׷��� �ۼ��ϼ���
#include <stdio.h>
#include <stdlib.h> 

int getLength() {
	int length; 
	printf("�迭 ���� �Է� : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length+1, sizeof(int));
	int i, input;
	for(i=0; i<length; ++i) {
		printf("arr[%d] : ", i);
		scanf("%d", arr+i);
	}
	return arr;
}

void showArr(int arr[], int n) {
	int i;
	for(i=0; i<n; ++i)
		printf("%2d", arr[i]);
}

int search(int arr[], int n, int key) {
	int i, j;
	arr[n] = key;
	
	printf("   |");
	for(i=0; i<n; ++i)
		printf("%2d", i);
	printf("\n---+");
	for(i=0; i<n; ++i)
		printf("---");
	puts("");
	for(i=0; i<n; ++i) {
		
		printf("%2c\n", '*');
		// �迭 ���� ��ҵ� ��� 
		printf("%3d|", i);
		showArr(arr, n);
		puts("\n   |");
		// �迭 ���� ��Ұ� ã�� ���̶�� ã�� ���� 
		if(arr[i] == key)
			break;
	}
	return i == n ? -1 : i;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int searchResult = search(arr, length, 3);
	printf("%d�� x[%d]�� �����մϴ�.\n", 3, searchResult);
} 
