/*
  가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.
  이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이으 변과 도화지의 변이 평행하도록 붙인다.
  이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 넓이를 구하는 프로그램을 작성하시오.
  (색종이의 수는 100이하) 
*/
#include <stdio.h>
#include <stdlib.h>
 
int** getColorPaper() {
	int n, i;
	printf("1 ~ 100개의 정수 입력 : ");
	scanf("%d", &n);
	
	if(n < 1 || n > 100) {
		printf("범위 초과(미달)\n");
		exit(1); 
	}
	
	
	int** colorPaperArray = calloc(n+1, sizeof(int*));
	colorPaperArray[0] = calloc(2, sizeof(int));
	colorPaperArray[0][0] = n;
	for(i = 1; i <= n; ++i) {
		colorPaperArray[i] = calloc(2, sizeof(int));
		printf("종이 좌표 입력 : ");
		scanf("%d %d", &colorPaperArray[i][0], &colorPaperArray[i][1]);
		
		if(colorPaperArray[i][0] < 0 || colorPaperArray[i][0] > 100 || colorPaperArray[i][1] < 0 || colorPaperArray[i][1] > 100) {
			printf("범위 초과(미달) 다시 입력하세요\n");
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
	printf("넓이 : %d\n", area);
}
