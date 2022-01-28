// n단의 피라미드를 출력하는 함수를 작성하세요
#include <stdio.h>

void showPiramid(int n) {
	int i, j;
	
	for(i=0; i<n; ++i) {
		for(j=n-i-1; j>0; --j) {
			printf("  ");
		}
		for(j=0; j<(i*2)+1; ++j) {
			printf("%2c", '*');
		}
		puts("");
	}
} 

void main() {
	int n;
	printf("높이 입력 : ");
	scanf("%d", &n);
	
	showPiramid(n);
}
