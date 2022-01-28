// n이 7이면 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28로 출력하는 프로그램을 작성하세요. 
#include <stdio.h>

void showPlus(int n) {
	int i = 1, sum = 0;
	while(i <= n) {
		printf("%d ", i);
		if(i != n)
			printf("+ ");
		sum += i;
		i++;
	}
	printf("= %d\n", sum);
}

void main() {
	int n;
	printf("정수 입력 : ");
	scanf("%d", &n);
	showPlus(n);
}
