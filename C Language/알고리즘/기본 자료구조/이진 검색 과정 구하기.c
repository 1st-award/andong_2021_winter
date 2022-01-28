// 이진 검색 과정을 자세히 출력하는 프로그램을 작성하세요
#include <stdio.h>
#include <stdlib.h>

int getLength() {
	int length;
	printf("배열 길이 입력 : ");
	scanf("%d", &length);
	return length;
}

int* getArr(int length) {
	int* arr = calloc(length, sizeof(int));
	int i;
	for(i=0; i<length; ++i)
		scanf("%d", arr+i);
	return arr;
}

void drawFirst(int n) {
	int i;
	printf("   |");
	for(i=0; i<n; ++i)
		printf("%2d", i);
	printf("\n---+");
	for(i=0; i<n; ++i)
		printf("---");
	puts("");
}

void drawCheckPoint(int pl, int pc, int pr) {
	int i;
	printf("   |");
	for(i=0; i<pr; ++i) {
		if(i == pl)
			printf("%s", "<-");
		else if(i == pc)
			printf("%2c", '+');
		else
			printf("  ");
	}
	printf("%s\n", "->");
}

void showArr(int arr[], int n, int pc) {
	int i;
	printf("%3d|", pc);
	for(i=0; i<n; ++i)
		printf("%2d", arr[i]);
	puts("\n   |");
}

int searchBinary(int arr[], int n, int key) {
	int pl = 0;
	int pr = n-1;
	int i;
	
	drawFirst(n);
	do {
		int pc = (pl + pr) / 2;
		drawCheckPoint(pl, pc, pr);
		showArr(arr, n, pc);
		if(arr[pc] == key)
			return pc;
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
	int binSearch = searchBinary(arr, length, 2);
	printf("%d는 x[%d]에 있습니다.\n", 2, binSearch);
} 
