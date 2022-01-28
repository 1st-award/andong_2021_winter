/*
   공항에서 n일 동안 매일 공항 방문객 수를 조사했습니다.
   이때, 가장 많은 방문객 수와 두 번째로 많은 방문객 수의 차이를 구하려고 합니다.
   (단, 방문갱의 수가 같은 날은 없다고 가정합니다.)
   이를 위해 다음과 같이 4단계로 간단히 프로그램 구조를 작성했습니다.
   
   1. 입력으로 주어진 배열에서 가장 많은 방문객 수를 찾습니다.
   2. 1단계에서 찾은 값을 제외하고, 나머지 값들로 이루어진 새로운 배열을 만듭니다.
   3. 2단계에서 만든 새로운 배열에서 가장 큰 방문객의 수를 찾습니다.
   4. 1단계와 3단계에서 구한 값의 차이를 구합니다. 
*/
#include <stdio.h>
#include <stdlib.h>

int getVisitorNumber() {
	int visitor;
	
	printf("방문객 수 입력 : ");
	scanf("%d", &visitor);
	
	if(0 > visitor || 100 < visitor) {
		printf("범위 초과(미달)\n");
		exit(1);
	}
	
	return visitor;
}

int validation(int* visitors, int visitorNumber) {
	int i, j;
	for(i=0; i<visitorNumber; ++i) {
		for(j=0; j<visitorNumber; ++j) {
			if(j == i || visitors[i] == 0)
				continue;
			else if(visitors[i] == visitors[j])
				return 0;
		}
	}
	return 1;
}

int* getVisitor(int visitor) {
	int i;
	int* visitors = calloc(visitor, sizeof(int));
	
	for(i=0; i<visitor; ++i) {
		printf("%d번째 방문객 입력 : ", i+1);
		scanf("%d", &visitors[i]);
		if(!validation(visitors, visitor)) {
			printf("방문객은 같을 수 없습니다.\n");
			exit(1);
		}
	}
	return visitors;
}

int getMaxVisitor(int* visitors, int visitorNumber) {
	int i, max = visitors[0];
	
	for(i=1; i<visitorNumber; ++i) {
		if(max < visitors[i])
			max = visitors[i];
	}
	return max;
}

int* getExclusiveMaxVisitorArray(int* visitors, int visitorNumber, int max) {
	int i, newNum = 0;
	int* newVisitors = calloc(visitorNumber-1, sizeof(int));
	
	for(i=0 ;i<visitorNumber; ++i) {
		if(visitors[i] != max)
			newVisitors[newNum++] = visitors[i];
	}
	
	return newVisitors;
}

int getCalc(int* visitors, int visitorNumber) {
	int max = getMaxVisitor(visitors, visitorNumber);
	int* exMaxVisitors = getExclusiveMaxVisitorArray(visitors, visitorNumber, max);
	int secondMax = getMaxVisitor(exMaxVisitors, visitorNumber-1);
	
	return max - secondMax;
}

void main() {
	int visitorNumber = getVisitorNumber();
	int* visitors = getVisitor(visitorNumber);
	int result = getCalc(visitors, visitorNumber);
	printf("Result : %d\n", result);
}
