// �� ���� �ּڰ��� ���ϴ� min4 �Լ��� �ۼ��ϼ���
#include <stdio.h>

int min4(int a, int b, int c, int d) {
	int min = a;
	
	min = min < b ? min : b;
	min = min < c ? min : c;
	min = min < d ? min : d;
	
	return min;
} 

void main() {
	int a, b, c, d;
	
	printf("�� ���� ���� �Է� : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	printf("�� ���� ���� �� �ּҰ� : %d\n", min4(a, b, c, d));
}
