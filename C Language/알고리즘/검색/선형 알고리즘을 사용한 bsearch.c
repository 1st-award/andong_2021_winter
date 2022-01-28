// bsearch �Լ��� ���� �������� ȣ����  ���ִ� ���� �Լ��� �ۼ��ϼ��� 
// ���� �˰����� ����ϰ�, �迭�� ���ĵǾ� ���� �ʾƵ� �˴ϴ�.
// void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, 
//                    int(*compar)(const void*, const void*));
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* a, const int* b) {
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size,
                int(*compar)(const void*, const void*)) {
    int i;
    for(i=0; i<nmemb; ++i) {
    	if((*compar)((base+size*i), key) == 0)
    		return base+size*i;
	}
	return NULL;
}

void main() {
	int key = 3;
	int arr[] = {1, 2, 3, 4, 5, 6};
	int* result = seqsearch(&key, arr, 6, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	printf("%d\n", result-arr);
}
