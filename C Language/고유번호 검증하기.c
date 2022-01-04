/* 컴퓨터를 제조하는 회사인 KOI 전자에서는 제조하는 컴퓨터마다 6자리의 고유번호를 매긴다.
   고유번호의 처음 5자리에는 00000부터 99999까지의 수 중 하나가 주어지며 6번째 자리에는 검증수가 들어간다.
   검증수는 고유번호의 처음 5자리에 들어가는 5개의 숫자를 각각 제곱한 수의 합을 10으로 나눈 나머지이다.
   예를들어, 고유번호의 처음 5자리의 숫자들이 04256이면, 각 숫자를 제곱한 수들의 합 0+16+4+25+36 = 81을 10으로 나눈 나머지인 1이 검증수이다.
   고유번호의 처음 5자리의 숫자들을 입력받아 검증수를 계산하는 프로그램을 작성하시오.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* getSerial() {
	static char serial[6];
	printf("00000 ~ 99999 사이의 숫자 입력 : ");
	scanf("%s", &serial);
	
	return serial;
} 

int powAfterSum(int sum, int n) {
	sum = sum + pow(n, 2);
	return sum;
}

int compareSerial(char* serial) {
	int i = 10000, sum = 0, n;
	int integerSerial = atoi(serial);
	while(i > 0) {
		n = integerSerial / i;
		integerSerial = integerSerial % i;
		
		sum = powAfterSum(sum, n);
		i = i / 10;
	}
	
	return sum%10;
}

void main() {
	char *serial = getSerial();
	int result = compareSerial(serial);
	printf("Result : %d\n", result);
}

