// 네 값의 최대값을 구하는 함수 max4를 작성하세요
#include <stdio.h>

int max4(int a, int b, int c, int d) {
	int max = a;
	
	max = max < b ? b : max;
	max = max < c ? c : max;
	max = max < d ? d : max;
	return max;
} 

void main() {
	int a, b, c, d;
	
	printf("네 개의 정수 입력 : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("네 값의 최대값 : %d\n", max4(a, b, c, d));
}
