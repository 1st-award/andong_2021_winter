// 두 변수 a, b를 입력하고 b - a를 출력하는 프로그램을 작성하세요
// 단, 변수 b에 입력한 값이 a이하면 b의 값을 다시 입력하세요 
#include <stdio.h>

int calcMinus(int a, int b) {
	return b - a;
} 

void main() {
	int a, b;
	
	printf("a의 값 : ");
	scanf("%d", &a);
	
	do {
		printf("b의 값 : ");
		scanf("%d", &b);
		if(a >= b)
			printf("a보다 큰 값을 입력하세요!\n");
	} while(a >= b);
	
	printf("b - a는 %d입니다.\n", calcMinus(a, b));
}
