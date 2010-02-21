/*
ID: chevalu2
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

struct farmer {
	int p, n;
};
typedef struct farmer node;
int cmp(const void *, const void *);

int main()
{
	FILE *fi = fopen("milk.in", "r");
	FILE *fo = fopen("milk.out", "w");
	node f[5100];
	int N, M, i, rst = 0;
	
	fscanf(fi, "%d %d", &N, &M);
	for (i = 0; i < M; ++i)
		fscanf(fi, "%d %d", &f[i].p, &f[i].n);
	qsort(f, M, sizeof(node), cmp);
	for (i = 0; i < M; ++i) {
		if (N > f[i].n) {
			N -= f[i].n;
			rst += f[i].p * f[i].n;
		}
		else {
			rst += f[i].p * N;
			break;
		}
	}
	fprintf(fo, "%d\n", rst);
	return 0;	
}

int cmp(const void *a, const void *b)
{
	return ((node *)a)->p - ((node *)b)->p;
}
