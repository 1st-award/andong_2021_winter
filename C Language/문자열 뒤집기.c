/*
   문자열을 입력받으면 반대로 문자열을 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
char* getString() {
	char* string = calloc(100, sizeof(char));
	int i;
	
	printf("문자열 입력 (알파벳 소문자만 가능): ");
	scanf("%s", string);
	
	for(i=0; i<strlen(string); ++i) {
		if(!islower(string[i])) {
			printf("알파벳 소문자가 아닙니다.");
			exit(1); 
		}
	}
	return string;
}

char* getReverseString(char* string) {
	int i, length = strlen(string);
	char* reverseString = strcpy(reverseString, string);
	char tempChar;
	
	for(i = 0; i<length/2; ++i) {
		tempChar = reverseString[i];
		reverseString[i] = reverseString[length-(i+1)];
		reverseString[length-(i+1)] = tempChar;
	}
	return reverseString;
}

void main() {
	char* string = getString();
	char* reverseString = getReverseString(string);
	printf("Result : %s\n", reverseString);
}
