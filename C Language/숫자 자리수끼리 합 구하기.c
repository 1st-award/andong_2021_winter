/*
  N(1 ~ 100)���� �ڿ����� �Է¹޾� �� �ڿ����� �ڸ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
*/
#include <stdio.h>
#include <stdlib.h>

int* getNumArray() {
	int n, i;
	printf("�Է��� �ڿ��� ���� �Է�(1 ~ 100) : ");
	scanf("%d", &n);
	if(n<0 || n>100) {
		printf("�ڿ��� ���� ���� �ʰ�\n");
		exit(1);
	}
	
	int* numArray = calloc(n+1, sizeof(int));
	numArray[0] = n;
	for(i=1; i<=n; ++i) {
		printf("100000������ �ڿ��� �Է� : ");
		scanf("%d", &numArray[i]);
		
		if(numArray[i] > 100000) {
			printf("���� �ʰ� �ٽ� �Է��ϼ���.\n");
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
			printf("%d �ڸ� : %2d\n", k, resultNumber[i]);
		}
		k = k / 10;
	}
}

void main() {
	int* numArray = getNumArray();
	showResult(numArray);
}
