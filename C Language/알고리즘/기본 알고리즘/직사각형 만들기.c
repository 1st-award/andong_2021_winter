// ���̿� �ʺ� �Է¹޾� ���簢���� *�� ����ϴ� ���α׷��� �ۼ��ϼ���
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
	
	printf("���� �Է� : ");
	scanf("%d", &n);
	printf("�ʺ� �Է� : ");
	scanf("%d", &m);
	
	showRect(n, m);
}
