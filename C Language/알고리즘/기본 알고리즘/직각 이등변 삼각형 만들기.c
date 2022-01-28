// 직각 이등변 삼각형을 출력하는 부분을 작성하세요. 
#include <stdio.h>

void showTriangleLB(int n) {
	int i, j;
	for(i=0; i<n; ++i) {
		for(j=0; j<=i; ++j) {
			printf("%2c", '*');
		}
		puts("");
	}
}

void main() {
	int n;
	printf("길이 입력 : ");
	scanf("%d", &n);
	showTriangleLB(n);
} 
