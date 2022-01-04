/*
  입력된 문자열에서 소괄호('()') 사이에 존재하는 모든 문자를 제거하고 남은 문자만 출력하는 프로그램을 작성하세요.
*/
#include <stdio.h>
#include <stdlib.h>

char* getString() {
	char* string = calloc(100, sizeof(100));
	printf("문자열 입력 : ");
	scanf("%s", string);
	
	return string;
}

int getLength(char* string) {
	int count = 0;
	int i=0;
	
	while(1) {
		if(string[i++] != '\0')
			count++;
		else
			break;
	}
	return count;
}

char* removeSymbol(char* string) {
	int n = getLength(string);
	int i, j = 0, symbol = 0;
	char* afterString = calloc(100, sizeof(char));
	
	for(i = 0; i < n; ++i) {
		if(string[i] == '(')
			symbol++;
		else if(symbol == 0) {
			afterString[j] = string[i];
			j++;
		}
		else if(string[i] == ')')
			symbol--;
		
		printf("%c %d\n", string[i], symbol);
	}
	
	return afterString;
}

void main() {
	char* string = getString();
	char* afterString = removeSymbol(string);
	printf("Result : %s\n", afterString);
} 
