/*
   그릇을 바닥에 놓았을 때 그 높이는 10cm 이다. 그런데 두 개의 그릇을 같은 방향으로 포개면 그 높이는 5cm만 증가된다.
   만일 그릇이 서로 반대방향으로 쌓이면 높이는 그릇만큼, 즉 10cm 늘어난다. 그릇을 입력받아 높이를 구해라.
*/

#include <stdio.h>
#include <stdlib.h>

char* getDish() {
	char* dishes = calloc(50, sizeof(char));
	printf("3 ~ 50개의 접시('(' 또는 ')') 입력 : ");
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
