/*
   �ΰ����� ������ ���챸�̰� ������ �ð��� �� ������ �ڵ������� ����Ѵ�.
    ����, �ΰ����� ���� �ո鿡�� ����ڿ��� �丮�� ������ �ð��� �˷��ִ� ������ �ð谡 �ִ�.
	�丮�� �����ϴ� �ð��� �丮�� �ϴ� �� �ʿ��� �ð��� �� ������ �־����� ��,
	���챸�̰� ������ �ð��� ����ϴ� ���α׷��� �ۼ��ϼ���.	 
*/

#include <stdio.h>
#include <stdlib.h>

int* getTime() {
	// time[0] = hour, time[1] = minute, time[2] = sec
	int* time = calloc(3, sizeof(int));
	
	printf("�� �� �� �Է� : ");
	scanf("%d %d %d", &time[0], &time[1], &time[2]);
	
	if(0 > time[0] || time[0] > 23 || 0 > time[1] || time[1] > 59 || 0 > time[2] || time[2] > 59) {
		printf("������ �ʰ�(�̴�)\n");
		exit(1);
	}
	
	return time;
}

int getNeedTime() {
	int time; 
	
	printf("�丮�� �ʿ��� �ð� �Է� : ");
	scanf("%d", &time);
	
	if(time < 0 || time > 500000) {
		printf("������ �ʰ�(�̴�)\n");
		exit(1); 
	}
	return time;
}

int calcHour(int time, int countHour) {
	if(time - 3600 < 0)
		return countHour;
	else {
		return countHour + calcHour(time - 3600, countHour++);
	}
}

int calcMinute(int time, int countMin) {
	if(time - 60 < 0) {
		return countMin;
	}
	else {
		return countMin + calcMinute(time - 60, countMin++);
	}
}

int upToMinFromSec(int sec, int cntUp) {
	if(sec < 60) 
		return cntUp;
	else 
		return cntUp + upToMinFromSec(sec - 60, cntUp++);
}

int upToHourFromMin(int min, int cntUp) {
	if(min < 60)
		return cntUp;
	else
		return cntUp + upToHourFromMin(min - 60, cntUp++);
}

int* calcAfterTime(int* startTime, int needTime) {
	int* endTime = calloc(3, sizeof(int));
	int hour = calcHour(needTime, 0);
	needTime = needTime - (hour * 3600);
	int minute = calcMinute(needTime, 0);
	needTime = needTime - (minute * 60);
	
	// �丮 �� �ð� = ���� �ð� + �ʿ� �ð� 
	endTime[0] = startTime[0] + hour;
	endTime[1] = startTime[1] + minute;
	endTime[2] = startTime[2] + needTime;
	
	// �丮 �� �ð� ���� ( sec 60 -> min 1, min 60 -> hour 1) 
	minute = upToMinFromSec(endTime[2], 0);
	hour = upToHourFromMin(endTime[1], 0);
	
	endTime[1] += minute;
	endTime[2] -= minute * 60;
	
	endTime[0] += hour;
	endTime[1] -= hour * 60;
	
	// �ð��� �ð�%24�� ���� 
	endTime[0] %= 24; 
	
	return endTime;
}

void main() {
	int* startTime = getTime();
	int needTime = getNeedTime();
	int* result = calcAfterTime(startTime, needTime);
	
	printf("�丮 �� �ð� : %d %d %d\n", result[0], result[1], result[2]);
}
