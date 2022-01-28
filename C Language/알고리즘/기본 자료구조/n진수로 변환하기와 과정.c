// n진수로 변환하는 과정과 결과를 출력하는 프로그램을 작성하세요
// 배열의 맨 앞쪽에 아랫자리가 아니라 윗자리를 저장하는 함수를 작성하세요 
#include <stdio.h>
#include <stdlib.h>

int cardConverter(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0, i;
	if(x) {
		while(x) {
			d[digits++] = dchar[x%n];
			printf("%2d|\t%2d ... %2d\n", n, x, x%n);
			printf("  +-------\n");
			x /= n;
		}
		printf("\t 0\n");
	}
	else
		d[digits++] = dchar[0];
		
	for(i=0; i<digits/2; ++i) {
		d[i] = d[i] ^ d[digits-i-1];
		d[digits-i-1] = d[i] ^ d[digits-i-1];
		d[i] = d[digits-i-1] ^ d[i];
	}
	return digits;
}

void main() {
	int i;
	unsigned no;
	int cd;
	int dno;
	char cno[512];
	int retry;
	
	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수 : ");
		scanf("%u", &no);
		
		do {
			printf("어떤 진수로 변환할까요(2 - 36) : ");
			scanf("%d", &cd);
		} while(cd < 2 || cd > 36);
		
		dno = cardConverter(no, cd, cno);
		printf("%d진수로는", cd);
		for(i=0; i<dno; ++i) {
			printf("%c", cno[i]);
		}
		printf("입니다.\n");
		printf("한 번 더 할까요?(1 ... 예/ 0 ...아니오) : ");
		scanf("%d", &retry); 
	} while(retry == 1);
} 
