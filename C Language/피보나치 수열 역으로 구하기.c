/*
  하루에 한 번 산을 넘어가는 떡 장사 할머니는 호랑이에게 떡을 주어야 산을 넘어갈 수 있는데,
  욕심 많은 호랑이는 어제 받은 떡의 개수와 그저께 받은 떡으 ㅣ개수를 더한 만큼의 떡을 받아야만 할머니를 무사히 보내 준다고 한다.
  할머니가 넘어온 날(3<= D <=30)와 그 날 호랑이에게 준 떡의 개수(10<= K <= 100000)를 입력받아
  첫 째와 둘째날에 준 떡의 개수를 구하여라.
*/
#include <stdio.h>
#include <stdlib.h>

int getDay() {
	int day;
	printf("할머니가 넘어온 날 입력 : ");
	scanf("%d", &day);

	if (day < 3 || day > 30) {
		printf("범위 초과(미달)\n");
		exit(1);
	}

	return day;
}

int getCake() {
	int cake;
	printf("그 날 준 떡의 개수 입력 : ");
	scanf("%d", &cake);

	if (cake < 10 || cake > 100000) {
		printf("범위 초과(미달)\n");
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
	printf("첫째 날 : %d\n둘째 날 : %d\n", firstAndSecondDay[0], firstAndSecondDay[1]);
}
