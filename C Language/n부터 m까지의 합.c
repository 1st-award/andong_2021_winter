/*
   �� �ڿ��� n���� m������ ���� ���Ϸ��� �մϴ�. �̸� ���� ������ ���� 3�ܰ��
   ������ ���α׷� ������ �ۼ��߽��ϴ�.
   
   1. 1���� m������ ���� ���մϴ�
   2. 1���� n-1������ ���� ���մϴ�
   3. 1�ܰ迡�� ���� ������ 2�ܰ迡�� ���� ���� ���ϴ�. 
*/
#include <stdio.h>
#include <stdlib.h>

int getNum() {
	int number;
	
	printf("���� �Է� (1 ~ 10000): ");
	scanf("%d", &number);
	
	if(1 > number || 10000 < number) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}
	return number;
} 

int calcAdd(int num) {
	int sum = 0;
	int i;
	
	for(i = 1; i<= num; ++i) {
		sum+=i;
	}
	return sum;
}

int addNum(int n, int m) {
	int k = calcAdd(m);
	int j = calcAdd(n-1);
	
	return k - j;
}

void main() {
	int n = getNum();
	int m = getNum();
	int result = addNum(n, m);
	
	printf("Result : %d\n", result); 
}
