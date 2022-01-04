/*
   최근에 개발된 지능형 기차가 1번역(출발역)부터 4번역(종착역)까지 4개의 정차역이 있는 노선에서 운해되고 있다.
   이 기차에는 타거나 내리는 사람 수를 자동으로 인식할 수 있는 장치가 있다.
   이 장치를 이용하여 출발역에서 종착역까지 가는 도중 기차 안에 사람이 가장 많을 때의 사람 수를 계산하려고 한다.
   단, 이 기차를 이용하는 사람들은 질서 의식이 투철하여, 역에서 기차에 탈 때, 내릴 사람이 모두 내린 후에 기차에 탄다고 가정한다.
   1. 기차는 역 번호 순서대로 운행한다.
   2. 출발역에서 내린 사람 수와 종착역에서 탄 사람 수는 0이다.
   3. 각 역에서 현재 기차에 있는 사람보다 더 많은 사람이 내리는 경우는 없다.
   4. 기차의 정원은 최대 10,000명이고 정원을 초과하여 타는 경우는 없다.
*/

#include <stdio.h>
#include <stdlib.h>

int** getCountCustomer() {
	int i;
	int **countCustomer = calloc(4, sizeof(int**));
	
	for(i=0; i<4; ++i) {
		countCustomer[i] = calloc(2, sizeof(int));
		printf("내린 사람 수, 탄 사람 수 입력 : ");
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
