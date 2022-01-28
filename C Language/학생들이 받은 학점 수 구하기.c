/*
   ������ ���� �л����� ������ ���� ������ �ο��մϴ�.
   
   85 ~ 100 : A
   70 ~ 84 : B
   55 ~ 69 : C
   0 ~ 39 : F
   
   �л����� ������ ����ִ� �迭�� �Է����� �� ������ ���� �л����� ���� �迭�� ��� ����ϼ���. 
*/
#include <stdio.h>
#include <stdlib.h>

int getStudentNumber() {
	int i, studentNumber;
	
	printf("�л� �� �Է�(1 ~ 200) : "); 
	scanf("%d", &studentNumber);
	
	if(1 > studentNumber || 200 < studentNumber) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1);
	}	
	return studentNumber;
}	

int* getStudentsScore(int studentNumber) {
	int i, score;
	int* students = calloc(studentNumber, sizeof(int));
	
	for(i=0; i<studentNumber; ++i) {
		printf("%d��° �л��� ���� �Է�(0 ~ 100) : ", i+1);
		scanf("%d", &score);
		
		if(0 > score || 100 < score) {
			printf("���� �ʰ�(�̴�)\n");
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
