/*
   한 학생의 과목별 점수가 들어있는 배열이 주어졌을 때,
   이 학생의 최고 점수와 최저 점수를 제외한 나머지 점수들의 합계를 구하려 합니다.
   이를 위해 다음과 같이 4단계로 프로그램 구조를 작성했습니다.
   
   1. 모든 과목 점수의 합을 구합니다.
   2. 최고 점수를 구합니다.
   3. 최저 점수를 구합니다.
   4. (모든 과목 점수 합) - (최고 점수) - (최저 점수)의 값을 반환합니다. 
*/
#include <stdio.h>
#include <stdlib.h>

int getMaxScore(int* scoreArray, int len) {
	int i, max=scoreArray[0];
	for(i=1; i<len; ++i) {
		if(max < scoreArray[i])
			max = scoreArray[i];
	}
	printf("max : %d\n", max);
	return max;
} 

int getMinScore(int* scoreArray, int len) {
	int i, min = scoreArray[0];
	for(i=1; i<len; ++i) {
		if(min > scoreArray[i])
			min = scoreArray[i];
	}
	printf("min : %d\n", min);
	return min;
}

int getSumScore(int* scoreArray, int len) {
	int i, sum = scoreArray[0];
	for(i=1; i<len; ++i)
		sum += scoreArray[i];
	printf("sum : %d\n", sum);
	return sum;
}

int calcExclusiveMaxMinScore(int* scoreArray, int len) {
	int min = getMinScore(scoreArray, len);
	int max = getMaxScore(scoreArray, len);
	int sum = getSumScore(scoreArray, len);
	printf("%d %d %d\n", min, max, sum);
	return sum - max - min;
}

int getLength() {
	int len;
	
	printf("배열 총 량 입력(3 ~ 10) : ");
	scanf("%d", &len);
	
	if(3 > len || 10 < len) {
		printf("범위 초과(미달) : ");
		exit(1);
	}
	return len;
}

int* getScoreArray(int len) {
	int i, score;
	int* scoreArray = calloc(len, sizeof(int));
	for(i=0; i<len; ++i) {
		printf("점수 입력(0 ~ 100) : ");
		scanf("%d", &score);
		
		if(0 > score || 100 < score) {
			printf("범위 초과(미달)");
			exit(1); 
		}
		else {
			scoreArray[i] = score;
		}
	}
	return scoreArray;
}

void main() {
	int length = getLength();
	int* scoreArray = getScoreArray(length);
	int result = calcExclusiveMaxMinScore(scoreArray, length);
	
	printf("Result : %d\n", result);
}
