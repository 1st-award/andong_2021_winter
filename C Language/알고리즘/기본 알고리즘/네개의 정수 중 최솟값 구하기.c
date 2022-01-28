// 네 값의 최솟값을 구하는 min4 함수를 작성하세요
#include <stdio.h>

int min4(int a, int b, int c, int d) {
	int min = a;
	
	min = min < b ? min : b;
	min = min < c ? min : c;
	min = min < d ? min : d;
	
	return min;
} 

void main() {
	int a, b, c, d;
	
	printf("네 개의 정수 입력 : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	printf("네 개의 정수 중 최소값 : %d\n", min4(a, b, c, d));
}
