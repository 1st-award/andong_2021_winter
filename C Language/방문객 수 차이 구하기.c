/*
   ���׿��� n�� ���� ���� ���� �湮�� ���� �����߽��ϴ�.
   �̶�, ���� ���� �湮�� ���� �� ��°�� ���� �湮�� ���� ���̸� ���Ϸ��� �մϴ�.
   (��, �湮���� ���� ���� ���� ���ٰ� �����մϴ�.)
   �̸� ���� ������ ���� 4�ܰ�� ������ ���α׷� ������ �ۼ��߽��ϴ�.
   
   1. �Է����� �־��� �迭���� ���� ���� �湮�� ���� ã���ϴ�.
   2. 1�ܰ迡�� ã�� ���� �����ϰ�, ������ ����� �̷���� ���ο� �迭�� ����ϴ�.
   3. 2�ܰ迡�� ���� ���ο� �迭���� ���� ū �湮���� ���� ã���ϴ�.
   4. 1�ܰ�� 3�ܰ迡�� ���� ���� ���̸� ���մϴ�. 
*/
#include <stdio.h>
#include <stdlib.h>

int getVisitorNumber() {
	int visitor;
	
	printf("�湮�� �� �Է� : ");
	scanf("%d", &visitor);
	
	if(0 > visitor || 100 < visitor) {
		printf("���� �ʰ�(�̴�)\n");
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
		printf("%d��° �湮�� �Է� : ", i+1);
		scanf("%d", &visitors[i]);
		if(!validation(visitors, visitor)) {
			printf("�湮���� ���� �� �����ϴ�.\n");
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
