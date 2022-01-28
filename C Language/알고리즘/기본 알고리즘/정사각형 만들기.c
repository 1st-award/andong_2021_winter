// 입력한 수를 한 변으로 하는 정사각형을 *로 출력하는 프로그램을 작성하세요. 
#include <stdio.h>

void showSquare(int n) {
	int i, j;
	
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			printf("%2c", '*');
		}
		puts("");
	}
}

void main() {
	int n;
	printf("한 변의 길이 입력 : ");
	scanf("%d", &n);
	
	showSquare(n);
}
