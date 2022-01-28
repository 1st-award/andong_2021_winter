// ����� ������ n���� �迭 arr���� key�� ��ġ�ϴ� ��� ����� �ε��� �迭 idx��
// �� �պκк��� ������� �����ϰ�, ��ġ�� ����� ������ ��ȯ�ϴ� �Լ��� �ۼ��ϼ���
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
	int i;
	for(i=0; i<length; ++i)
		scanf("%d", arr+i);
	return arr;
}

int searchIndex(int arr[], int n, int key, int idx[]) {
	int index = -1, i;
	arr[n] = key;
	for(i=0; i<n; ++i) {
		printf("%d %d\n", arr[i], key);
		if(arr[i] == key) {
			index++;
			idx[index] = i;
		}
	}
	return index+1;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int idx[length];
	int resultSearch = searchIndex(arr, length, 9, idx);
	int i;
	for(i=0; i<length; ++i) {
		printf("%2d ", *(idx+i));
	}
	printf("\n%d\n", resultSearch);
} 
