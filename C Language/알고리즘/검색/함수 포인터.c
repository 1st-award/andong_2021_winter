// ÇÔ¼ö Æ÷ÀÎÅÍ¸¦ ÀÌ¿ëÇ× µ¡¼À, °ö¼ÀÇ¥
#include <stdio.h>

int sum(int x1, int x2) {
	return x1 + x2;
} 

int mul(int x1, int x2) {
	return x1 * x2;
}

void kuku(int(*calc)(int, int)) {
	int i, j;
	for(i=1; i<10; ++i) {
		for(j=1; j<10; ++j) {
			printf("%3d", (*calc)(i, j));
		}
		puts("");
	}
}

void main() {
	puts("µ¡¼ÀÇ¥");
	kuku(sum);
	puts("\n°ö¼ÀÇ¥");
	kuku(mul);
}
