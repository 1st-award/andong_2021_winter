// ���� �̵ �ﰢ���� ����ϴ� �κ��� �ۼ��ϼ���. 
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
	printf("���� �Է� : ");
	scanf("%d", &n);
	showTriangleLB(n);
} 
