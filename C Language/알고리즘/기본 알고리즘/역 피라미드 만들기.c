// �Ʒ��� ���� n���� �Ƕ�̵带 ���弼��
#include <stdio.h>

void showReversePiramid(int n) {
	int i, j;
	
	for(i=0; i<n; ++i) {
		for(j=n-i; j<n; ++j) {
			printf("  ");
		}
		for(j=0; j<(n-i)*2-1; ++j) {
			printf("%2c", 'c');
		}
		puts("");
	}
} 

void main() {
	int n;
	printf("���� �Է� : ");
	scanf("%d", &n);
	showReversePiramid(n);
} 
