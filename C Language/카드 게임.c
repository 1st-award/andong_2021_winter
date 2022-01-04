/*
   1 ~ 10까지의 숫자가 하나씩 적힌 열 장의 카드로 '게임'을 한다.
   게임은 총 열 번의 '라운드'로 구성되고, 각 라운드 마다 자신이 가지고 있는 카드 중 하나를 제시하고,
   한 번 제시한 카드는 버린다. 게임 승패는 다음과 같이 결정된다.
   
   1. 각 라운드는 더 높은 수자를 제시한 사람이 승리하고, 제시한숫자가 같은 경우는 비긴다.
   2. 열 번의 라운드에서 더 많은 라운드를 승리한 사람이 게임을 승리하고, 승리한 라운드 횟수가 동일한 경우 비긴다.
   A가 승리하면 A, B가 승리하면 B, 비기면 D를 출력한다. 
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
		printf("==== 현재 입력한 정수 ====\n");
		showCard(count);
		printf("1 ~ 10까지의 정수를 각각 한 번씩 입력 : ");
		scanf("%d", &cardArray[i]);
		
		if(count[cardArray[i]-1] != 0) {
			printf("이미 입력한 정수 다시 입력\n");
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
