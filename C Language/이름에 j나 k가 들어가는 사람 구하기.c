/*
  �л����� �̸��� ����ִ� ��ܿ��� �̸��� j �Ǵ� k�� ���� �л��� ���� ���ϼ���.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getListLength() {
	int length;
	
	printf("����� ũ�⸦ �Է��ϼ���(1 ~ 100) : ");
	scanf("%d", &length);
	
	if(1 > length || 100 < length) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	} 
	
	return length;
} 

int validation(char* string) {
	int i;
	for(i=0; i<strlen(string); ++i) {
		if(!islower(string[i])) {
			return 0; 
		}
	}
	return 1;
}

char** getNameList(int listLength) {
	char** nameList = calloc(listLength, sizeof(char*));
	int i;
	
	for(i=0; i<listLength; ++i) {
		nameList[i] = calloc(20, sizeof(char));
		printf("%d��° �л��̸� �Է�(1 ~20, �ҹ��ڸ� ����) : ", i+1);
		scanf("%s", nameList[i]);
		
		if(!validation(nameList[i]) || 1 > strlen(nameList[i]) || 20 < strlen(nameList[i])) {
			printf("���� �ʰ�(�̴�) �Ǵ� �ҹ��ڰ� �ƴմϴ�.\n");
		}
	} 
	return nameList;
}

int countIncludeJorK(char** nameList, int listLength) {
	int i, j, count = 0;
	
	for(i=0; i<listLength; ++i) {
		for(j=0; j<strlen(nameList[i]); ++j) {
			if(nameList[i][j] == 'j' || nameList[i][j] == 'k') {
				count++;
				break;
			}
		}
	}
	
	return count;
}

void main() {
	int listLength = getListLength();
	char** nameList = getNameList(listLength);
	int result = countIncludeJorK(nameList, listLength);
	printf("Result : %d\n", result);
}
