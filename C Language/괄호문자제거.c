/*
  �Էµ� ���ڿ����� �Ұ�ȣ('()') ���̿� �����ϴ� ��� ���ڸ� �����ϰ� ���� ���ڸ� ����ϴ� ���α׷��� �ۼ��ϼ���.
*/
#include <stdio.h>
#include <stdlib.h>

char* getString() {
	char* string = calloc(100, sizeof(100));
	printf("���ڿ� �Է� : ");
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
