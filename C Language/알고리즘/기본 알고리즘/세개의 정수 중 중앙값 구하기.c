// �� ���� ��� ���� 13������ ��� ���տ� ���� �߾Ӱ��� ���Ͽ� 
// ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

int med3(int a, int b, int c) {
	if(a >= b) {
		if(b >= c)
			return b;
		else if(a <= c)
			return a;
		else
			return c;
	}
	else if(a > c)
		return a;
	else if(b > c)
		return c;
	else
		return b;
}

void main() {
	int a, b, c;
	printf("�� ���� �Է� : ");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("�� ������ �߾� �� : %d\n", med3(a, b, c)); 
}
