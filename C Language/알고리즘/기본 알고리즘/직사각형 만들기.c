// 높이와 너비를 입력받아 직사각형을 *로 출력하는 프로그램을 작성하세요
#include <stdio.h>

void showRect(int n, int m) {
	int i, j;
	
	for(i=0; i<n; ++i) {
		for(j=0; j<m; ++j) {
			printf("%2c", '*');
		}
		puts("");
	}
} 

void main() {
	int n, m;
	
	printf("높이 입력 : ");
	scanf("%d", &n);
	printf("너비 입력 : ");
	scanf("%d", &m);
	
	showRect(n, m);
}
