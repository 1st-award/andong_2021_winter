/*
   학생들의 키가 들어있는 목록에서 키가 k보다 큰 사람은 몇 명인지 구하려합니다.
   키가 입력된 배열을 받아 k보다 큰 사람의 수를 구하세요.
*/
#include <stdio.h>
#include <stdlib.h>

int getHeightNumber() {
	int number; 
	printf("키 목록 크기 입력(1 ~ 100) : ");
	scanf("%d", &number);
	
	if(1 > number || 100 < number) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	return number;
} 

int* getHeightArray(int number) {
	int* heightArray = calloc(number, sizeof(int));
	int i, height;
	
	for(i=0 ;i<number; ++i) {
		printf("%d번째 학생의 키 입력(100 ~ 300) : ", i+1);
		scanf("%d", &height);
		
		if(100 > height || 300 < height) {
			printf("범위 초과(미달)\n");
			exit(1);
		}
		else
			heightArray[i] = height;
	}
	return heightArray;
}

int getK() {
	int height;
	 
	printf("기준 키 입력 : ");
	scanf("%d", &height);
	if(100 > height || 300 < height) {
			printf("범위 초과(미달)\n");
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
    
