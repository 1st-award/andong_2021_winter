/*
  �Ϸ翡 �� �� ���� �Ѿ�� �� ��� �ҸӴϴ� ȣ���̿��� ���� �־�� ���� �Ѿ �� �ִµ�,
  ��� ���� ȣ���̴� ���� ���� ���� ������ ������ ���� ���� �Ӱ����� ���� ��ŭ�� ���� �޾ƾ߸� �ҸӴϸ� ������ ���� �شٰ� �Ѵ�.
  �ҸӴϰ� �Ѿ�� ��(3<= D <=30)�� �� �� ȣ���̿��� �� ���� ����(10<= K <= 100000)�� �Է¹޾�
  ù °�� ��°���� �� ���� ������ ���Ͽ���.
*/
#include <stdio.h>
#include <stdlib.h>

int getDay() {
	int day;
	printf("�ҸӴϰ� �Ѿ�� �� �Է� : ");
	scanf("%d", &day);

	if (day < 3 || day > 30) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}

	return day;
}

int getCake() {
	int cake;
	printf("�� �� �� ���� ���� �Է� : ");
	scanf("%d", &cake);

	if (cake < 10 || cake > 100000) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}

	return cake;
}

int calcCake(int firstDay, int secondDay, int day) {
	int i, sum = 0;
	int oneDay = firstDay, twoDay = secondDay;

	for (i = 2; i < day; ++i) {
		sum = oneDay + twoDay;
		oneDay = twoDay;
		twoDay = sum;
	}

	return sum;
}

int* getFirstAndSecondDay(int day, int cake) {
	int oneDay = 0, twoDay = 1;
	int resultCake;
	int* resultCalcDay = calloc(2, sizeof(int));
	printf("d: %d c : %d\n", day, cake);

	do {
		resultCake = 0;
		if (oneDay >= twoDay) {
			oneDay = 1;
			twoDay++;
		}
		else if (oneDay < twoDay) {
			oneDay++;
		}

		resultCake = calcCake(oneDay, twoDay, day);
		printf("%d %d %d\n", oneDay, twoDay, resultCake);

	} while (resultCake != cake);


	resultCalcDay[0] = oneDay, resultCalcDay[1] = twoDay;
	return resultCalcDay;
}

void main() {
	int day = getDay();
	int cake = getCake();
	int* firstAndSecondDay = getFirstAndSecondDay(day, cake);
	printf("ù° �� : %d\n��° �� : %d\n", firstAndSecondDay[0], firstAndSecondDay[1]);
}
