/*
   1 ~ 10������ ���ڰ� �ϳ��� ���� �� ���� ī��� '����'�� �Ѵ�.
   ������ �� �� ���� '����'�� �����ǰ�, �� ���� ���� �ڽ��� ������ �ִ� ī�� �� �ϳ��� �����ϰ�,
   �� �� ������ ī��� ������. ���� ���д� ������ ���� �����ȴ�.
   
   1. �� ����� �� ���� ���ڸ� ������ ����� �¸��ϰ�, �����Ѽ��ڰ� ���� ���� ����.
   2. �� ���� ���忡�� �� ���� ���带 �¸��� ����� ������ �¸��ϰ�, �¸��� ���� Ƚ���� ������ ��� ����.
   A�� �¸��ϸ� A, B�� �¸��ϸ� B, ���� D�� ����Ѵ�. 
*/
#include <stdio.h>
#include <stdlib.h>

void showCard(int* count) {
	int i;
	for(i = 0; i < 10; ++i) {
		if(count[i] != 0)
			printf("%d ", i+1);
	}
	puts("");
}

int* getCard() {
	int i;
	int* count = calloc(10, sizeof(10));
	int* cardArray = calloc(10, sizeof(10));
	
	for(i=0; i<10; ++i) {
		printf("==== ���� �Է��� ���� ====\n");
		showCard(count);
		printf("1 ~ 10������ ������ ���� �� ���� �Է� : ");
		scanf("%d", &cardArray[i]);
		
		if(count[cardArray[i]-1] != 0) {
			printf("�̹� �Է��� ���� �ٽ� �Է�\n");
			i = i - 1;
		}
		else
			count[cardArray[i]-1]++;
	}
	return cardArray;
}

char getResultGame(int countA, int countB) {
	if(countA > countB)
		return 'A';
	else if(countA < countB)
		return 'B';
	else
		return 'D';
	return '0';
}

char startGame(int* playerA, int* playerB) {
	int i;
	int countA = 0, countB = 0;
	
	for(i = 0; i < 10; ++i) {
		if(playerA[i] > playerB[i])
			countA++;
		else if(playerA[i] < playerB[i])
			countB++;
		else
			continue;
	}
	
	return getResultGame(countA, countB);
}

void main() {
	int *ACardArray = getCard();
	int *BCardArray = getCard();
	char result = startGame(ACardArray, BCardArray);
	printf("Result : %c\n", result);
}
