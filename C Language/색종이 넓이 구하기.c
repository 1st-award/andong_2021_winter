/*
  ����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ���� �ִ�.
  �� ��ȭ�� ���� ����, ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ �����̸� �������� ���� ��ȭ���� ���� �����ϵ��� ���δ�.
  �̷��� ������� �����̸� �� �� �Ǵ� ���� �� ���� �� �����̰� ���� ���� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
  (�������� ���� 100����) 
*/
#include <stdio.h>
#include <stdlib.h>
 
int** getColorPaper() {
	int n, i;
	printf("1 ~ 100���� ���� �Է� : ");
	scanf("%d", &n);
	
	if(n < 1 || n > 100) {
		printf("���� �ʰ�(�̴�)\n");
		exit(1); 
	}
	
	
	int** colorPaperArray = calloc(n+1, sizeof(int*));
	colorPaperArray[0] = calloc(2, sizeof(int));
	colorPaperArray[0][0] = n;
	for(i = 1; i <= n; ++i) {
		colorPaperArray[i] = calloc(2, sizeof(int));
		printf("���� ��ǥ �Է� : ");
		scanf("%d %d", &colorPaperArray[i][0], &colorPaperArray[i][1]);
		
		if(colorPaperArray[i][0] < 0 || colorPaperArray[i][0] > 100 || colorPaperArray[i][1] < 0 || colorPaperArray[i][1] > 100) {
			printf("���� �ʰ�(�̴�) �ٽ� �Է��ϼ���\n");
			i--;
		}
	}
	return colorPaperArray;
} 

int** setArea() {
	int** area = calloc(100, sizeof(int*));
	int i;
	for(i=0; i<100; ++i)
		area[i] = calloc(100, sizeof(int));
		
	return area;
}

void setPapperToArea(int **area, int* paper) {
	int i, j;
	
	for(i = 0; i < 10; ++ i) {
		for(j = 0; j < 10; ++ j) {
			area[paper[0] + i][paper[1] + j]++;
		}
	}
}

int countArea(int** area) {
	int i, j;
	int count = 0;
	
	for(i = 0; i < 100; ++i) {
		for(j = 0; j < 100; ++j) {
			if(area[i][j] != 0)
				count++;
		}
	}
	return count;
}

void showArea(int** area) {
	int i, j;
	for(i=0; i<100; i++) {
		for(j=0; j<100; j++) {
			printf("%d", area[i][j]);
		}
		puts("");
	}
}

int getArea(int** colorPaperArray) {
	int n = colorPaperArray[0][0];
	int** area = setArea();
	int i, count = 0;
	
	for(i = 1; i <= n; ++ i) {
		setPapperToArea(area, colorPaperArray[i]);
	}
	
	showArea(area);
	count = countArea(area);
	return count;
}

void main() {
	int** colorPaperArray = getColorPaper();
	int area = getArea(colorPaperArray);
	printf("���� : %d\n", area);
}
