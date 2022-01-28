/*
   ���ڿ��� �Է¹����� �ݴ�� ���ڿ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
char* getString() {
	char* string = calloc(100, sizeof(char));
	int i;
	
	printf("���ڿ� �Է� (���ĺ� �ҹ��ڸ� ����): ");
	scanf("%s", string);
	
	for(i=0; i<strlen(string); ++i) {
		if(!islower(string[i])) {
			printf("���ĺ� �ҹ��ڰ� �ƴմϴ�.");
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
