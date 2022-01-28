/*
   �л����� Ű�� ����ִ� ��Ͽ��� Ű�� k���� ū ����� �� ������ ���Ϸ��մϴ�.
   Ű�� �Էµ� �迭�� �޾� k���� ū ����� ���� ���ϼ���.
*/
#include <stdio.h>
#include <stdlib.h>

int getHeightNumber() {
	int number; 
	printf("Ű ��� ũ�� �Է�(1 ~ 100) : ");
	scanf("%d", &number);
	
	if(1 > number || 100 < number) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}
	return number;
} 

int* getHeightArray(int number) {
	int* heightArray = calloc(number, sizeof(int));
	int i, height;
	
	for(i=0 ;i<number; ++i) {
		printf("%d��° �л��� Ű �Է�(100 ~ 300) : ", i+1);
		scanf("%d", &height);
		
		if(100 > height || 300 < height) {
			printf("���� �ʰ�(�̴�)\n");
			exit(1);
		}
		else
			heightArray[i] = height;
	}
	return heightArray;
}

int getK() {
	int height;
	 
	printf("���� Ű �Է� : ");
	scanf("%d", &height);
	if(100 > height || 300 < height) {
			printf("���� �ʰ�(�̴�)\n");
			exit(1);
	}
	return height;
}

int aboveAvgHeight(int* heightArray, int heightNumber, int k) {
	int i, count = 0;
	
	for(i=0; i<heightNumber; ++i) {
		if(heightArray[i] > k)
			count++;
	}
	return count;
}

void main() {
	int heightNumber = getHeightNumber();
	int* heightArray = getHeightArray(heightNumber);
	int k = getK();
	int result = aboveAvgHeight(heightArray, heightNumber, k);
	printf("Result : %d\n", result);
}
    
