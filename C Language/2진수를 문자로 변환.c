/*
   ȫ���̴� �������� ���� A, B, C, D, E, F, G, H�� ������ ������ ������ �����µ�,
   ��ǻ�ͷ� ������ ���������, �� ���ڸ��� 0 �Ǵ� 1�� ���� ���� ���� ����Ͽ� ������.
   �� ������ ����� ������ ����.
   A 000000	B 001111 C 010011 D 011100 E 100110 F 101001 G 110101 H 111010
   
   �� ���ڸ� Ʋ���� ���� ���, �����̴� ���� �������� ���ڸ� �˾� �� �� �ִ�.
   2���̻� Ʋ���� ���� ���, �߸��� ���� ó�� ������ ������ ��ġ�� ����Ѵ�. 
*/
#include <stdio.h>
#include <stdlib.h>

int getDigitNum() {
	int num;
	
	printf("������ ���� �Է�(�ִ� 10����) : ");
	scanf("%d", &num);
	
	if(num < 0 || num > 10) {
		printf("������ �ʰ�");
		exit(1); 
	}
	return num;
}

char* getDigit(int num) {
	int max = num*6;
	char* digit = calloc(max, sizeof(char));
	scanf("%s", digit);
	
	return digit;
}

void setTempDigit(char* tempDigit, char* digit, int num) {
	int i;
	for(i=0; i<6; ++i) {
		tempDigit[i] = digit[num++]; 
	}
}

char compareDigit(char* tempDigit) {
	int i, j, cnt = 0;
	char digitAlpha[][6] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
	char charAlpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	
	for(i=0; i<8; ++i) {
		cnt = 0;
		for(j=0; j<6; ++j) {
			if(digitAlpha[i][j] != tempDigit[j]) {
				cnt++;
			}
		}
		if(cnt == 1 || cnt == 0)
			return charAlpha[i];
	}
	
	return '0';
}

char* digitToChar(char* digit, int digitNum) {
	char* word = calloc(digitNum, sizeof(char));
	char* tempDigit = calloc(6, sizeof(int));
	static char symbol;
	int i, j;
	
	for(i=0; i<digitNum; ++i) {
		setTempDigit(tempDigit, digit, i*6);
		symbol = compareDigit(tempDigit);
		if(isalpha(symbol)) {
			word[i] = symbol;
		}
		else {
			symbol = (char) (i+1) + '0'; 
			return &symbol;
		}
	}
	return word;
}

void main() {
	int digitNum = getDigitNum();
	char* digit = getDigit(digitNum);
	char* result = digitToChar(digit, digitNum);
	printf("Result : %s\n", result);
}
