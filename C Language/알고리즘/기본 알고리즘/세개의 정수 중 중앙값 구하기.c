// 세 값의 대소 관계 13종류의 모든 조합에 대해 중앙값을 구하여 
// 출력하는 프로그램을 작성하세요.
#include <stdio.h>

int med3(int a, int b, int c) {
	if(a >= b) {
		if(b >= c)
			return b;
		else if(a <= c)
			return a;
		else
			return c;
	}
	else if(a > c)
		return a;
	else if(b > c)
		return c;
	else
		return b;
}

void main() {
	int a, b, c;
	printf("세 정수 입력 : ");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("세 정수의 중앙 값 : %d\n", med3(a, b, c)); 
}
