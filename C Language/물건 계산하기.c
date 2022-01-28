/*
   고객이 구매한 물건들의 가격과 지불 금액이 주어졌을 때, 거스름돈을 얼마나 줘야하는지 구하려 합니다.
*/
#include <stdio.h>
#include <stdlib.h>

int getItemNumber() {
	int number;
	 
	printf("제품 개수를 입력하세요(1 ~ 50) : ");
	scanf("%d", &number);
	
	if(1 > number || 50 < number) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	return number;
}

int* getItemPriceList(int itemNumber) {
	int i, price;
	int* itemPriceList = calloc(itemNumber, sizeof(int));
	
	for(i=0; i<itemNumber; ++i) {
		printf("%d번째 상품 가격 입력 (10 ~ 100000) : ", i+1);
		scanf("%d", &price);
		
		if(10 > price || 100000 < price) {
			printf("범위 초과(미달)\n"); 
		} 
		else {
			itemPriceList[i] = price;
		}
	}
	
	return itemPriceList;
}

int getMoney() {
	int money;
	
	printf("점원에게 줄 돈을 입력하세요(10 ~ 5000000) : ");
	scanf("%d", &money);
	
	if(10 > money || 5000000 < money) {
		printf("범위 초과(미달)\n");
		exit(1);
	} 
	return money;
}

int calcItem(int* itemPriceList, int itemNumber, int money) {
	int i;
	for(i=0; i<itemNumber; ++i) {
		money -= itemPriceList[i];
	}
	// 구매 금액보다 지불 금액이 작은 경우 -1반환 
	if(0 > money)
		return -1;
	return money;
}

void main() {
	int itemNumber = getItemNumber();
	int* itemPriceList = getItemPriceList(itemNumber);
	int money = getMoney();
	int change = calcItem(itemPriceList, itemNumber, money);
	printf("Result : %d\n", change);
}
