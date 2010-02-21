/*
ID: chevalu2
LANG: C
TASK: barn1
*/
#include <stdio.h>

struct barn {
	int s, t, next;
};
typedef struct barn node;
int cmp(const void *, const void *);
node b[210];
int main()
{
	FILE *fi = fopen("barn1.in", "r");
	FILE *fo = fopen("barn1.out", "w");
	int M, S, C, i, tmp, sum = 0, c, min, q;
	fscanf(fi, "%d %d %d", &M, &S, &C);
	for (i = 0; i < C; ++i) {
		fscanf(fi, "%d", &tmp);
		b[i].s = b[i].t = tmp;
	}
	qsort(b, C, sizeof(node), cmp);
	for (i = 0; i < C; ++i) {
		b[i].next = i+1;
	}
	b[C-1].next = -1;
	c = C;
	sum = C;
	while (c > M) {
		i = 0;
		min = S;
		while(b[i].next > 0) {
			if (b[b[i].next].s - b[i].t < min) {
				min = b[b[i].next].s - b[i].t;
				q = i;
			}
			i = b[i].next;
		}
		sum += b[b[q].next].s - b[q].t - 1;
		b[q].t = b[b[q].next].t;
		b[q].next = b[b[q].next].next;
		--c;
	}
	fprintf(fo, "%d\n", sum);
	return 0;	
}

int cmp(const void *a, const void *b)
{
	return ((node *)a)->s - ((node *)b)->s;
}