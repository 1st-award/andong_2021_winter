// n������ ��ȯ�ϴ� ������ ����� ����ϴ� ���α׷��� �ۼ��ϼ���
// �迭�� �� ���ʿ� �Ʒ��ڸ��� �ƴ϶� ���ڸ��� �����ϴ� �Լ��� �ۼ��ϼ��� 
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
	
	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf("%u", &no);
		
		do {
			printf("� ������ ��ȯ�ұ��(2 - 36) : ");
			scanf("%d", &cd);
		} while(cd < 2 || cd > 36);
		
		dno = cardConverter(no, cd, cno);
		printf("%d�����δ�", cd);
		for(i=0; i<dno; ++i) {
			printf("%c", cno[i]);
		}
		printf("�Դϴ�.\n");
		printf("�� �� �� �ұ��?(1 ... ��/ 0 ...�ƴϿ�) : ");
		scanf("%d", &retry); 
	} while(retry == 1);
} 
