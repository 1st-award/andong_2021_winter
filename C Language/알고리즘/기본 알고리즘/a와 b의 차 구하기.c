// �� ���� a, b�� �Է��ϰ� b - a�� ����ϴ� ���α׷��� �ۼ��ϼ���
// ��, ���� b�� �Է��� ���� a���ϸ� b�� ���� �ٽ� �Է��ϼ��� 
#include <stdio.h>

int calcMinus(int a, int b) {
	return b - a;
} 

void main() {
	int a, b;
	
	printf("a�� �� : ");
	scanf("%d", &a);
	
	do {
		printf("b�� �� : ");
		scanf("%d", &b);
		if(a >= b)
			printf("a���� ū ���� �Է��ϼ���!\n");
	} while(a >= b);
	
	printf("b - a�� %d�Դϴ�.\n", calcMinus(a, b));
}
