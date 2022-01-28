/*
  학생들의 이름이 들어있는 명단에서 이름에 j 또는 k가 들어가는 학생의 수를 구하세요.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getListLength() {
	int length;
	
	printf("명단의 크기를 입력하세요(1 ~ 100) : ");
	scanf("%d", &length);
	
	if(1 > length || 100 < length) {
		printf("범위 초과(미달)\n");
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
		printf("%d번째 학생이름 입력(1 ~20, 소문자만 가능) : ", i+1);
		scanf("%s", nameList[i]);
		
		if(!validation(nameList[i]) || 1 > strlen(nameList[i]) || 20 < strlen(nameList[i])) {
			printf("범위 초과(미달) 또는 소문자가 아닙니다.\n");
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
