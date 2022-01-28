/*
   ���� ������ ���ǵ��� ���ݰ� ���� �ݾ��� �־����� ��, �Ž������� �󸶳� ����ϴ��� ���Ϸ� �մϴ�.
*/
#include <stdio.h>
#include <stdlib.h>

int getItemNumber() {
	int number;
	 
	printf("��ǰ ������ �Է��ϼ���(1 ~ 50) : ");
	scanf("%d", &number);
	
	if(1 > number || 50 < number) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}
	return number;
}

int* getItemPriceList(int itemNumber) {
	int i, price;
	int* itemPriceList = calloc(itemNumber, sizeof(int));
	
	for(i=0; i<itemNumber; ++i) {
		printf("%d��° ��ǰ ���� �Է� (10 ~ 100000) : ", i+1);
		scanf("%d", &price);
		
		if(10 > price || 100000 < price) {
			printf("���� �ʰ�(�̴�)\n"); 
		} 
		else {
			itemPriceList[i] = price;
		}
	}
	
	return itemPriceList;
}

int getMoney() {
	int money;
	
	printf("�������� �� ���� �Է��ϼ���(10 ~ 5000000) : ");
	scanf("%d", &money);
	
	if(10 > money || 5000000 < money) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	} 
	return money;
}

int calcItem(int* itemPriceList, int itemNumber, int money) {
	int i;
	for(i=0; i<itemNumber; ++i) {
		money -= itemPriceList[i];
	}
	// ���� �ݾ׺��� ���� �ݾ��� ���� ��� -1��ȯ 
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
