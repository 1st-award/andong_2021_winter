// 세 값의 최솟값을 구하는 min3 함수를 작성하세요.
#include <stdio.h>

int min3(int a, int b, int c) {
	int min = a;
	
	min = min > b ? b : min;
	min = min > c ? c : min;
	
	return min;
} 

void main() {
	int a, b, c;
	printf("세 개의 정수 입력 : ");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("세 개의 정수 중 최솟값 : %d\n", min3(a, b, c));
}
