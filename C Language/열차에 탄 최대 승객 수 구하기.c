/*
   �ֱٿ� ���ߵ� ������ ������ 1����(��߿�)���� 4����(������)���� 4���� �������� �ִ� �뼱���� ���صǰ� �ִ�.
   �� �������� Ÿ�ų� ������ ��� ���� �ڵ����� �ν��� �� �ִ� ��ġ�� �ִ�.
   �� ��ġ�� �̿��Ͽ� ��߿����� ���������� ���� ���� ���� �ȿ� ����� ���� ���� ���� ��� ���� ����Ϸ��� �Ѵ�.
   ��, �� ������ �̿��ϴ� ������� ���� �ǽ��� ��ö�Ͽ�, ������ ������ Ż ��, ���� ����� ��� ���� �Ŀ� ������ ź�ٰ� �����Ѵ�.
   1. ������ �� ��ȣ ������� �����Ѵ�.
   2. ��߿����� ���� ��� ���� ���������� ź ��� ���� 0�̴�.
   3. �� ������ ���� ������ �ִ� ������� �� ���� ����� ������ ���� ����.
   4. ������ ������ �ִ� 10,000���̰� ������ �ʰ��Ͽ� Ÿ�� ���� ����.
*/

#include <stdio.h>
#include <stdlib.h>

int** getCountCustomer() {
	int i;
	int **countCustomer = calloc(4, sizeof(int**));
	
	for(i=0; i<4; ++i) {
		countCustomer[i] = calloc(2, sizeof(int));
		printf("���� ��� ��, ź ��� �� �Է� : ");
		scanf("%d %d", &countCustomer[i][0], &countCustomer[i][1]);
	}
	
	return countCustomer;
}

int maxCustomer(int **countCustomer) {
	int max = 0, i, count=0;
	
	for(i=0; i<4; ++i) {
		count = count - countCustomer[i][0];
		count = count + countCustomer[i][1];
		if(max < count)
			max = count;
	}
	return max;
}

void main() {
	int **countCustomer = getCountCustomer();
	int result = maxCustomer(countCustomer);
	printf("Result : %d\n", result);
}
