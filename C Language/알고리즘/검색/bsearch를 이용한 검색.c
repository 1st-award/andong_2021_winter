// ������������ ���ĵ� �迭�� bsearch �Լ��� ���� �˻��ϼ���
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* a, const int* b) {
	return *a > *b ? -1 : *a < *b ? 1 : 0;
} 

int getLength() {
	int length;
	printf("�迭 ���� �Է� : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length, sizeof(int));
	int i;
	
	puts("������������ �Է�");
	printf("arr[0] : ");
	scanf("%d", arr); 
	for(i=1; i<length; ++i) {
		do {
			printf("arr[%d] : ", i);
			scanf("%d", arr+i);
		} while(arr[i-1] < arr[i]);
	}
	return arr;
}

void main() {
	int length = getLength();
	int* arr = getArr(length);
	int key;
	int* result;
	
	printf("�˻� �� : ");
	scanf("%d", &key);
	result = bsearch(&key, arr, length, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	
	if(result != NULL)
		printf("%d�� arr[%d]�� �ֽ��ϴ�.\n", key, (int)(result-arr));
	else
		puts("�˻��� �����߽��ϴ�.");
}
