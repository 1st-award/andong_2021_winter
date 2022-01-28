// �÷� ������ ��� �迭�� �Է¹޾� *�� ǥ���ϴ� ���α׷��� �ۼ��ϼ���
#include <stdio.h>
#define VMAX 21

typedef struct {
	char name[20];
	int height;
	double vision;
} PhysCheck;

double ave_height(const PhysCheck data[], int n) {
	int i;
	double sum = 0;
	for(i=0; i<n; ++i)
		sum += data[i].height;
	return sum/n;
}

void dist_vision(const PhysCheck data[], int n, int dist[]) {
	int i;
	for(i=0; i<VMAX; ++i)
		dist[i] = 0;
	for(i=0; i<n; ++i) {
		if(data[i].vision >= 0.0 && data[i].vision <= VMAX/10.0)
			dist[(int)(data[i].vision * 10)]++;
	}
}

void main() {
	int i, j;
	PhysCheck x[] = {
		{"������", 162, 0.3},
		{"������", 173, 0.7},
		{"������", 175, 2.0},
		{"�ڿ��", 169, 0.7}
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	puts("==== ��ü �˻�ǥ ====");
	puts("�̸�\t\tŰ  �÷�");
	puts("-------------------------");
	for(i=0; i<nx; ++i)
		printf("%-15s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	printf("��� Ű : %5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);
	printf("\n�÷� ����\n");
	for(i=0; i<VMAX; i++) {
		if(vdist[i] != 0) {
			printf("%3.1f ~ : ", i/10.0);
			for(j=0; j<vdist[i]; j++)
				printf("*");
			puts("");
		}
	}
}
