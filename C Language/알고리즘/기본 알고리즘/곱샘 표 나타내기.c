// 곱셈표를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
 
void showMulChart() {
	int i, j;
	printf("   |   1  2  3  4  5  6  7  8  9\n");
	printf("---+-----------------------------\n");
	for(i=1; i<10; ++i) {
		printf("%3d| ", i);
		for(j=1; j<10; ++j) {
			printf("%3d", i * j);
		}
		puts("");
	}
} 

void main() {
	showMulChart();
}
