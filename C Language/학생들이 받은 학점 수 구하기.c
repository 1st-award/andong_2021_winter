/*
   다음과 같이 학생들의 점수에 따라 학점을 부여합니다.
   
   85 ~ 100 : A
   70 ~ 84 : B
   55 ~ 69 : C
   0 ~ 39 : F
   
   학생들의 점수가 들어있는 배열을 입력했을 때 학점을 받은 학생들의 수를 배열에 담아 출력하세요. 
*/
#include <stdio.h>
#include <stdlib.h>

int getStudentNumber() {
	int i, studentNumber;
	
	printf("학생 수 입력(1 ~ 200) : "); 
	scanf("%d", &studentNumber);
	
	if(1 > studentNumber || 200 < studentNumber) {
		printf("범위 초과(미달)\n");
		exit(1);
	}	
	return studentNumber;
}	

int* getStudentsScore(int studentNumber) {
	int i, score;
	int* students = calloc(studentNumber, sizeof(int));
	
	for(i=0; i<studentNumber; ++i) {
		printf("%d번째 학생의 점수 입력(0 ~ 100) : ", i+1);
		scanf("%d", &score);
		
		if(0 > score || 100 < score) {
			printf("범위 초과(미달)\n");
			exit(1);
		} 
		else
			students[i] = score;
	}
	return students;
}

int* calcScore(int* studentsScore, int studentNumber) {
	int* scoreCountArray = calloc(5, sizeof(int));
	int i, score;
	
	for(i=0; i<studentNumber; ++i) {
		score = studentsScore[i];
		printf("%d\n", score);
		if(85 <= score && 100 >= score)
			scoreCountArray[0]++;
		else if(70 <= score)
			scoreCountArray[1]++;
		else if(55 <= score)
			scoreCountArray[2]++;
		else if(40 <= score)
			scoreCountArray[3]++;
		else
			scoreCountArray[4]++;
	}
	
	return scoreCountArray;
}

void main() {
	int studentNumber = getStudentNumber();
	int* studentsScore = getStudentsScore(studentNumber);
	int* result = calcScore(studentsScore, studentNumber);
	int i;
	for(i=0 ;i<5; ++i) {
		printf("%d ", result[i]);
	}
} 
