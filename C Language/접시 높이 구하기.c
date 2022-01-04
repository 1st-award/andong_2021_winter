/*
   �׸��� �ٴڿ� ������ �� �� ���̴� 10cm �̴�. �׷��� �� ���� �׸��� ���� �������� ������ �� ���̴� 5cm�� �����ȴ�.
   ���� �׸��� ���� �ݴ�������� ���̸� ���̴� �׸���ŭ, �� 10cm �þ��. �׸��� �Է¹޾� ���̸� ���ض�.
*/

#include <stdio.h>
#include <stdlib.h>

char* getDish() {
	char* dishes = calloc(50, sizeof(char));
	printf("3 ~ 50���� ����('(' �Ǵ� ')') �Է� : ");
	scanf("%s", dishes);
	
	return dishes;
}

int getCount(char* dishes) {
	int count = 0, i;
	
	for(i=0; ; ++i) {
		if(dishes[i] != '\0')
			count = count + 1;
		else
			return count;
	}
	return 0;
}

int getHeight(char* dishes) {
	int n = getCount(dishes);
	int height = 10, i;
	char lastestDish = dishes[0];
	
	for(i=1; i<n; ++i) {
		if(lastestDish == '(' && dishes[i] == '(')
			height = height + 5;
		else if(lastestDish == '(' && dishes[i] == ')')
			height = height + 10;
		else if(lastestDish == ')' && dishes[i] == ')')
			height = height + 5;
		else
			height = height + 10;
			
		lastestDish = dishes[i];
	}
	return height;
}

void main() {
	char* dishes = getDish();
	int height = getHeight(dishes);
	
	printf("Result : %d\n", height);
}
