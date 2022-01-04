/*
  N(1 ~ 100)개의 자연수를 입력받아 각 자연수의 자리수의 합을 출력하는 프로그램을 작성하세요.
*/
#include <stdio.h>
#include <stdlib.h>

int* getNumArray() {
	int n, i;
	printf("입력할 자연수 개수 입력(1 ~ 100) : ");
	scanf("%d", &n);
	if(n<0 || n>100) {
		printf("자연수 개수 범위 초과\n");
		exit(1);
	}
	
	int* numArray = calloc(n+1, sizeof(int));
	numArray[0] = n;
	for(i=1; i<=n; ++i) {
		printf("100000이하의 자연수 입력 : ");
		scanf("%d", &numArray[i]);
		
		if(numArray[i] > 100000) {
			printf("범위 초과 다시 입력하세요.\n");
			i--;
		}
	} 
	return numArray;
} 

void calcNum(int* numberArray, int number) {
	int n = 100000;
	int i = 0;
	
	while(n != 0) {
		numberArray[i] += number / n;
		number = number % n;
		
		n = n / 10;
		i ++;
	}
}

void showResult(int* numArray) {	
	int n = numArray[0];
	int* resultNumber = calloc(6, sizeof(int));
	int i;
	
	for(i = 1; i <= n; ++i) {
		calcNum(resultNumber, numArray[i]);
	}
	
	int k = 100000;
	for(i = 0; i < 6; ++i) {
		if(resultNumber[i] != 0) {
			printf("%d 자리 : %2d\n", k, resultNumber[i]);
		}
		k = k / 10;
	}
}

void main() {
	int* numArray = getNumArray();
	showResult(numArray);
}
