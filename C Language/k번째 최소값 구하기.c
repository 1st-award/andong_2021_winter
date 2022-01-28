/*
   2차원 배열에서 k번째로 작은 수를 구하세요.
*/ 
#include <stdio.h>
#include <stdlib.h>

int getArrayLength() {
	int length;
	
	printf("배열의 길이를 입력하세요(1 ~ 20) : ");
	scanf("%d", &length);
	
	if(1 > length || 20 < length) {
		printf("범위 초과(미달)\n");
		exit(1); 
	} 
	return length;
}

int** getArray(int arrayLength) {
	int** array = calloc(arrayLength, sizeof(int*));
	int i, j, input;
	
	for(i=0; i<arrayLength; ++i) {
		// 가로의 길이는 4 고정 
		array[i] = calloc(4, sizeof(int));
		for(j=0; j<4; ++j) {
			printf("정수 입력 (1 ~ 1000) : ");
			scanf("%d", &input);
			
			if(1 > input || 1000 < input) {
				printf("범위 초과(미달)");
				exit(1);
			}
			else
				array[i][j] = input;
		}
	}
	
	return array;
}

int getK(int arrayLength) {
	int k;
	printf("k입력(1 ~ %d) : ", arrayLength*4);
	scanf("%d", &k);
	 
	if(1 > k || arrayLength*4 < k) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	
	return k;
}

void showArray(int** array, int arrayLength) {
	int i,j;
	for(i=0; i<arrayLength; ++i) {
		for(j=0; j<4; ++j) {
			printf("%d ", array[i][j]);
		}
		puts("");
	}
}

void sortArray(int* stack, int k) {
	int i, j;
	
	for(i=1; i<k; ++i) {
		for(j=0; j<i; ++j) {
			if(stack[i] < stack[j]) {
				stack[i] = stack[i] ^ stack[j];
				stack[j] = stack[i] ^ stack[j];
				stack[i] = stack[j] ^ stack[i];
			}
		}
	}
	
	puts("stack sorting");
	for(i=0; i<k; ++i) 
		printf("%d ", stack[i]);
	puts("");
}

void setMinStack(int* stack, int k) {
	int i;
	for(i=0; i<k; ++i)
		stack[i] = 9999;
}

int* inputStack(int* stack, int min, int k) {
	int i, minCnt = 0;
	for(i=0; i<k; ++i) {
		if(stack[i] > min)
			minCnt++;
	}
	
	if(minCnt==0)
		return stack;
	
	int* newStack = calloc(k, sizeof(int));
	setMinStack(newStack, k);
	newStack[0] = min;
	for(i=1; i<k; ++i) {
		newStack[i] = stack[i-1];
	}
	
	sortArray(newStack, k);	
	free(stack);
	return newStack;
}

int minOfK(int** array, int arrayLength, int k) {
	int i, j, min = 9999;
	int* minStack = calloc(k, sizeof(int));
	setMinStack(minStack, k);
	showArray(array, arrayLength);
	
	for(i=0; i < arrayLength; ++i) {
		for(j=0; j<4; ++j) {
			minStack = inputStack(minStack, array[i][j], k);
		}
		sortArray(minStack, k);
		puts("");
	}
	sortArray(minStack, k);
	return minStack[k-1];
}

void main() {
	int arrayLength = getArrayLength();
	int** array = getArray(arrayLength);
	int k = getK(arrayLength);
	int result = minOfK(array, arrayLength, k);
	printf("Result : %d\n", result);
}
