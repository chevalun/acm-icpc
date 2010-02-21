/*
ID: chevalu2
LANG: C
TASK: ariprog
*/
#include <stdio.h>
#include <stdlib.h>

int flag[250*250*2+10];
int num[250*250 + 10];
 
struct result {
	int s, d;
};
typedef struct result node;
int cmp(const void *, const void *);
node r[21000];

int main()
{
	FILE *fi = fopen("ariprog.in", "r");
	FILE *fo = fopen("ariprog.out", "w");
	int N, M, i, j, k, max = 0, nn = 0, f, rst = 0;
	fscanf(fi, "%d", &N);
	fscanf(fi, "%d", &M);
	for(i = 0; i <= M; ++i) {
		for(j = i; j <= M; ++j) {
			flag[i*i + j*j] = 1;
			if (i*i+j*j > max)
				max = i*i+j*j;
		}
	}
	for (i = 0; i <= max; ++i) {
		if (flag[i]) {
			num[nn++] = i;
		}
	}
	for (i = 0; i < nn; ++i) {
		for(j = i+1; j < nn; ++j) {
			f = 1;
			for (k = N - 1; k >= 2; --k) {
				if (num[i] + k*(num[j]-num[i]) > 250*250*2) {
					f = -1;
					break;
				}	
				if (!flag[num[i] + k*(num[j]-num[i])]) {
					f = 0;
					break;
				}
			}
			if (f < 0)
				break;
			if (f) {
				r[rst].s = num[i];
				r[rst].d = num[j]-num[i];
				++rst;
			}
		}
	}
	qsort(r, rst, sizeof(node), cmp);
	for (i = 0; i < rst; ++i)
		fprintf(fo, "%d %d\n", r[i].s, r[i].d);
	if (!rst)	
		fprintf(fo, "NONE\n");
	return 0;	
}

int cmp(const void *a, const void *b)
{
	if (((node *)a)->d != ((node *)b)->d)
		return ((node *)a)->d - ((node *)b)->d;
	return ((node *)a)->s - ((node *)b)->s;
}