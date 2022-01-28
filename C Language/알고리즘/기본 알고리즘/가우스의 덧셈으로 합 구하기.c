// 가우스의 덧셈이라는 방법을 이용하여 1부터 n까지의 정수
// 합을 구하는 프로그래을 작성하세요. 
#include <stdio.h>

int calcPlus(int n) {
	int sum = 0;
	
	sum += (1 + n) * (n/2);
	
	if(n % 2 == 1)
		sum += (n + 1) / 2;
		
	return sum;
}

void main() {
	int n;
	printf("정수 입력 : ");
	scanf("%d", &n);
	printf("1 ~ %d까지의 합 : %d", n, calcPlus(n));
}
