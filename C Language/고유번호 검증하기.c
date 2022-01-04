/* ��ǻ�͸� �����ϴ� ȸ���� KOI ���ڿ����� �����ϴ� ��ǻ�͸��� 6�ڸ��� ������ȣ�� �ű��.
   ������ȣ�� ó�� 5�ڸ����� 00000���� 99999������ �� �� �ϳ��� �־����� 6��° �ڸ����� �������� ����.
   �������� ������ȣ�� ó�� 5�ڸ��� ���� 5���� ���ڸ� ���� ������ ���� ���� 10���� ���� �������̴�.
   �������, ������ȣ�� ó�� 5�ڸ��� ���ڵ��� 04256�̸�, �� ���ڸ� ������ ������ �� 0+16+4+25+36 = 81�� 10���� ���� �������� 1�� �������̴�.
   ������ȣ�� ó�� 5�ڸ��� ���ڵ��� �Է¹޾� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* getSerial() {
	static char serial[6];
	printf("00000 ~ 99999 ������ ���� �Է� : ");
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

