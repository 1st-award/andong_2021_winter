/*
   �� �л��� ���� ������ ����ִ� �迭�� �־����� ��,
   �� �л��� �ְ� ������ ���� ������ ������ ������ �������� �հ踦 ���Ϸ� �մϴ�.
   �̸� ���� ������ ���� 4�ܰ�� ���α׷� ������ �ۼ��߽��ϴ�.
   
   1. ��� ���� ������ ���� ���մϴ�.
   2. �ְ� ������ ���մϴ�.
   3. ���� ������ ���մϴ�.
   4. (��� ���� ���� ��) - (�ְ� ����) - (���� ����)�� ���� ��ȯ�մϴ�. 
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
	
	printf("�迭 �� �� �Է�(3 ~ 10) : ");
	scanf("%d", &len);
	
	if(3 > len || 10 < len) {
		printf("���� �ʰ�(�̴�) : ");
		exit(1);
	}
	return len;
}

int* getScoreArray(int len) {
	int i, score;
	int* scoreArray = calloc(len, sizeof(int));
	for(i=0; i<len; ++i) {
		printf("���� �Է�(0 ~ 100) : ");
		scanf("%d", &score);
		
		if(0 > score || 100 < score) {
			printf("���� �ʰ�(�̴�)");
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
