// �� ���� �ּڰ��� ���ϴ� min3 �Լ��� �ۼ��ϼ���.
#include <stdio.h>

int min3(int a, int b, int c) {
	int min = a;
	
	min = min > b ? b : min;
	min = min > c ? c : min;
	
	return min;
} 

void main() {
	int a, b, c;
	printf("�� ���� ���� �Է� : ");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("�� ���� ���� �� �ּڰ� : %d\n", min3(a, b, c));
}
