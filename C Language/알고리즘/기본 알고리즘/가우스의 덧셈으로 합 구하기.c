// ���콺�� �����̶�� ����� �̿��Ͽ� 1���� n������ ����
// ���� ���ϴ� ���α׷��� �ۼ��ϼ���. 
#include <stdio.h>

int calcPlus(int n) {
	int sum = 0;
	
	sum += (1 + n) * (n/2);
	
	if(n % 2 == 1)
		sum += (n + 1) / 2;
		
	return sum;
}

void main() {
	int n;
	printf("���� �Է� : ");
	scanf("%d", &n);
	printf("1 ~ %d������ �� : %d", n, calcPlus(n));
}
