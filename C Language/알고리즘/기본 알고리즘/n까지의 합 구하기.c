// n�� 7�̸� 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28�� ����ϴ� ���α׷��� �ۼ��ϼ���. 
#include <stdio.h>

void showPlus(int n) {
	int i = 1, sum = 0;
	while(i <= n) {
		printf("%d ", i);
		if(i != n)
			printf("+ ");
		sum += i;
		i++;
	}
	printf("= %d\n", sum);
}

void main() {
	int n;
	printf("���� �Է� : ");
	scanf("%d", &n);
	showPlus(n);
}
