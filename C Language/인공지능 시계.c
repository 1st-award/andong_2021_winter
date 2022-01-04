/*
   인공지능 오븐은 오븐구이가 끝나는 시간을 초 단위로 자동적으로 계산한다.
    또한, 인공지능 오븐 앞면에는 사용자에게 요리가 끝나는 시각을 알려주는 디지털 시계가 있다.
	요리를 시작하는 시각과 요리를 하는 데 필요한 시간이 초 단위로 주어졌을 때,
	오븐구이가 끝나는 시각을 계산하는 프로그램을 작성하세요.	 
*/

#include <stdio.h>
#include <stdlib.h>

int* getTime() {
	// time[0] = hour, time[1] = minute, time[2] = sec
	int* time = calloc(3, sizeof(int));
	
	printf("시 분 초 입력 : ");
	scanf("%d %d %d", &time[0], &time[1], &time[2]);
	
	if(0 > time[0] || time[0] > 23 || 0 > time[1] || time[1] > 59 || 0 > time[2] || time[2] > 59) {
		printf("허용범위 초과(미달)\n");
		exit(1);
	}
	
	return time;
}

int getNeedTime() {
	int time; 
	
	printf("요리에 필요한 시간 입력 : ");
	scanf("%d", &time);
	
	if(time < 0 || time > 500000) {
		printf("허용범위 초과(미달)\n");
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
	
	// 요리 후 시간 = 시작 시간 + 필요 시간 
	endTime[0] = startTime[0] + hour;
	endTime[1] = startTime[1] + minute;
	endTime[2] = startTime[2] + needTime;
	
	// 요리 후 시간 정리 ( sec 60 -> min 1, min 60 -> hour 1) 
	minute = upToMinFromSec(endTime[2], 0);
	hour = upToHourFromMin(endTime[1], 0);
	
	endTime[1] += minute;
	endTime[2] -= minute * 60;
	
	endTime[0] += hour;
	endTime[1] -= hour * 60;
	
	// 시간은 시간%24로 정리 
	endTime[0] %= 24; 
	
	return endTime;
}

void main() {
	int* startTime = getTime();
	int needTime = getNeedTime();
	int* result = calcAfterTime(startTime, needTime);
	
	printf("요리 후 시간 : %d %d %d\n", result[0], result[1], result[2]);
}
