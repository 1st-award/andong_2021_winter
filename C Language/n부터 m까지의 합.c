/*
   두 자연수 n부터 m까지의 합을 구하려고 합니다. 이를 위해 다음과 같이 3단계로
   간단히 프로그램 구조를 작성했습니다.
   
   1. 1부터 m까지의 합을 구합니다
   2. 1부터 n-1까지의 합을 구합니다
   3. 1단계에서 구한 값에서 2단계에서 구한 값을 뺍니다. 
*/
#include <stdio.h>
#include <stdlib.h>

int getNum() {
	int number;
	
	printf("정수 입력 (1 ~ 10000): ");
	scanf("%d", &number);
	
	if(1 > number || 10000 < number) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	return number;
} 

int calcAdd(int num) {
	int sum = 0;
	int i;
	
	for(i = 1; i<= num; ++i) {
		sum+=i;
	}
	return sum;
}

int addNum(int n, int m) {
	int k = calcAdd(m);
	int j = calcAdd(n-1);
	
	return k - j;
}

void main() {
	int n = getNum();
	int m = getNum();
	int result = addNum(n, m);
	
	printf("Result : %d\n", result); 
}
