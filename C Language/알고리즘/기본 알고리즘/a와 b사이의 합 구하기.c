// a ~ b사이의 정수의 합을 구하는 함수를 작성하세요.
#include <stdio.h>

int calcAdd(int a, int b) {
	int sum = 0;
	
	sum = (a + b) * ((b-a+1) / 2);
	
	if((b-a+1) % 2 == 1)
		sum += (a + b) / 2;
	return sum;	
} 

void main() {
	int a, b;
	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &a, &b);
	
	printf("%d ~ %d사이의 합 : %d\n", a, b, calcAdd(a, b));
}
