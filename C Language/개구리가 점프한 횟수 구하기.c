/*
   �������� ������ �������� �Ϸķ� �����ִ� ¡�˴ٸ��� �ǳʷ��� �մϴ�.
   ¡�˴ٸ����� �ڿ����� ����������, �����ִ� ���ڸ�ŭ �������� �����ؾ��մϴ�.
   �������� ¡�˴ٸ��� ��� �ǳʱ����� �ʿ��� ���� Ƚ���� ��ȯ�ϵ��� �ϼ���. 
*/
#include <stdio.h>
#include <stdlib.h>

int getRockNumber() {
	int number;
	
	printf("¡�˴ٸ� ���� �Է�(1 ~ 100) : "); 
	scanf("%d", &number);
	
	if(0 > number || 100 < number) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}
	return number;
}

int* getJumps(int rockNumber) {
	int i, jump;
	int* jumpArray = calloc(rockNumber, rockNumber);
	
	for(i=0; i<rockNumber; ++i) {
		printf("%d��° ¡�˴ٸ����� �����ؾ��� �Ÿ�(1 ~ 5) : ", i+1);
		scanf("%d", &jump);
		
		if(0 > jump || 5 < jump) {
			printf("���� �ʰ�(�̴�)\n");
			exit(1); 
		}
		else
			jumpArray[i] = jump;		
	}
	
	return jumpArray;
}

int totalOfJumps(int* jumpArray, int rockNumber) {
	int jumpCount = 0;
	int jumpDistance = 0;
	int i;
	
	do {
		jumpDistance = jumpArray[jumpCount++];
		printf("%d\n", jumpDistance);
	} while(jumpDistance < rockNumber-1);
	
	return jumpCount;
}

void main() {
	int rockNumber = getRockNumber();
	int* jumpArray = getJumps(rockNumber);
	int result = totalOfJumps(jumpArray, rockNumber);
	printf("Result : %d\n", result);
} 
