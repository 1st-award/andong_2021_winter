/*
   개구리가 일정한 간격으로 일렬로 놓여있는 징검다리를 건너려고 합니다.
   징검다리에는 자연수가 적혀있으며, 적혀있는 숫자만큼 앞쪽으로 점프해야합니다.
   개구리가 징검다리를 모두 건너기위해 필요한 점프 횟수를 반환하도록 하세요. 
*/
#include <stdio.h>
#include <stdlib.h>

int getRockNumber() {
	int number;
	
	printf("징검다리 개수 입력(1 ~ 100) : "); 
	scanf("%d", &number);
	
	if(0 > number || 100 < number) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	return number;
}

int* getJumps(int rockNumber) {
	int i, jump;
	int* jumpArray = calloc(rockNumber, rockNumber);
	
	for(i=0; i<rockNumber; ++i) {
		printf("%d번째 징검다리에서 점프해야할 거리(1 ~ 5) : ", i+1);
		scanf("%d", &jump);
		
		if(0 > jump || 5 < jump) {
			printf("범위 초과(미달)\n");
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
