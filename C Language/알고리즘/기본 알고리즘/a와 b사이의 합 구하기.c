// a ~ b������ ������ ���� ���ϴ� �Լ��� �ۼ��ϼ���.
#include <stdio.h>

int calcAdd(int a, int b) {
	int sum = 0;
	
	sum = (a + b) * ((b-a+1) / 2);
	
	if((b-a+1) % 2 == 1)
		sum += (a + b) / 2;
	return sum;	
} 

void main() {
	int a, b;
	printf("�� ���� ���� �Է� : ");
	scanf("%d %d", &a, &b);
	
	printf("%d ~ %d������ �� : %d\n", a, b, calcAdd(a, b));
}
