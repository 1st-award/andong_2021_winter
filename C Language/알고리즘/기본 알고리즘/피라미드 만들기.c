// n���� �Ƕ�̵带 ����ϴ� �Լ��� �ۼ��ϼ���
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
	printf("���� �Է� : ");
	scanf("%d", &n);
	
	showPiramid(n);
}
