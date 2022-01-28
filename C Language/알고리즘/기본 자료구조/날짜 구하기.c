// 날짜를 나타내는 구조체를 만들어 아래의 함수를 작성하세요

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int month;
	int date;
} Date;

// y년 m월 d일을 나타내는 구조체를 반환하는 함수
Date DateOf(int y, int m, int d);
// 날짜 x의 n일 뒤의 날짜를 반환하는 함수
Date After(Date x, int n);
// 날짜 x의 n일 앞에 날짜를 반환하는 함수
Date Before(Date x, int n);
// y년 m월 d일을 출력하는 함수
void showDate(Date x);
// 윤년을 계산후 결과를 반환하는 함수 
int isLeap(int year);
 
void main() {
	Date date = DateOf(2020, 12, 25);
	showDate(date);
	Date date1 = After(date, 815);
	showDate(date1);
	Date date2 = Before(date1, 815);
	showDate(date2);
} 

void showDate(Date x) {
	printf("%d %d %d\n", x.year, x.month, x.date);
}

int isLeap(int year) {
	return year%4 == 0 && year % 100 != 0 || year % 400 == 0;
}

Date DateOf(int y, int m, int d) {
	Date date;
	date.year = y;
	date.month = m;
	date.date = d;
	return date;
}

Date After(Date x, int n) {
	Date newDate;
	int date[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
					  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	
	newDate.year = x.year;
	newDate.month = x.month;
	newDate.date = x.date + n;
	
	while(date[isLeap(newDate.year)][newDate.month-1] < newDate.date) {
		newDate.date -= date[isLeap(newDate.year)][newDate.month-1];	
		newDate.month++;
		if(newDate.month == 13) {
			newDate.month = 1;
			newDate.year++;
		}
	}
	return newDate;
}

Date Before(Date x, int n) {
	Date newDate;
	int date[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
					  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	
	newDate.year = x.year;
	newDate.month = x.month;
	newDate.date = x.date - n;
	
	while(1 > newDate.date) {
		newDate.month--;
		if(newDate.month == 0) {
			newDate.month = 12;
			newDate.year--;
		}
		newDate.date += date[isLeap(newDate.year)][newDate.month-1];	
	}
	return newDate;
}
