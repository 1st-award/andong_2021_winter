// ��¥�� ��Ÿ���� ����ü�� ����� �Ʒ��� �Լ��� �ۼ��ϼ���

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int month;
	int date;
} Date;

// y�� m�� d���� ��Ÿ���� ����ü�� ��ȯ�ϴ� �Լ�
Date DateOf(int y, int m, int d);
// ��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ�
Date After(Date x, int n);
// ��¥ x�� n�� �տ� ��¥�� ��ȯ�ϴ� �Լ�
Date Before(Date x, int n);
// y�� m�� d���� ����ϴ� �Լ�
void showDate(Date x);
// ������ ����� ����� ��ȯ�ϴ� �Լ� 
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
