// �� ���� �ִ밪�� ���ϴ� �Լ� max4�� �ۼ��ϼ���
#include <stdio.h>

int max4(int a, int b, int c, int d) {
	int max = a;
	
	max = max < b ? b : max;
	max = max < c ? c : max;
	max = max < d ? d : max;
	return max;
} 

void main() {
	int a, b, c, d;
	
	printf("�� ���� ���� �Է� : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("�� ���� �ִ밪 : %d\n", max4(a, b, c, d));
}
