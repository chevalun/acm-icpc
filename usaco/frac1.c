/*
ID: chevalu2
LANG: C
TASK: frac1
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int a, b;
	double val;
};
typedef struct node node;
int cmp(const void *, const void *);
int gcd(int, int);

int main()
{
	FILE *fi = fopen("frac1.in", "r");
	FILE *fo = fopen("frac1.out", "w");
	int i,j, rst = 0, N;
	node frac[10000];
	fscanf(fi, "%d", &N);
	for(i = 0; i <= N; ++i)
		for (j = i; j <= N; ++j)
			if (gcd(i,j) == 1) {
				frac[rst].a = i;
				frac[rst].b = j;
				frac[rst].val = (double) i / j;
				++rst;
			}
	qsort(frac, rst, sizeof(node), cmp);
	for(i = 0; i < rst; ++i)
		fprintf(fo, "%d/%d\n", frac[i].a, frac[i].b);
	return 0;	
}

int cmp(const void *a, const void *b)
{
	return (((node *)a)->val > ((node *)b)->val) ? 1 : -1;
}

int gcd(int a, int b)
{
	if (!a)
		return b;
	return gcd(b % a, a);
}