// �Է��� ���� �� ������ �ϴ� ���簢���� *�� ����ϴ� ���α׷��� �ۼ��ϼ���. 
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
	printf("�� ���� ���� �Է� : ");
	scanf("%d", &n);
	
	showSquare(n);
}
