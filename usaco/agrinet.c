/*
ID: chevalu2
LANG: C
TASK: agrinet
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int l, s, t;
};
typedef struct node edge;
int f[100];
edge e[10000];
void uni(int x, int y);
int find(int x);
int cmp(const void *, const void *);

int main()
{
	FILE *fi = fopen("agrinet.in", "r");
	FILE *fo = fopen("agrinet.out", "w");
	int i, j, c = 0, N, temp, rst = 0, cc = 0;
	fscanf(fi, "%d", &N);
	for(i = 0; i < N; ++i)
		for(j = 0; j < N; ++j) {
			fscanf(fi, "%d", &temp);
			if (j > i) {
				e[c].l = temp;
				e[c].s = i;
				e[c].t = j;
				++c;
			}
	}
	for(i = 0; i < N; ++i)
		f[i] = i;
	qsort(e, c, sizeof(edge), cmp);
	for(i = 0; i < c; ++i)
		if(find(e[i].s) != find(e[i].t)) {
			rst += e[i].l;
			uni(e[i].s, e[i].t);
			++cc;
			if (cc == N-1)
				break;
		}
	fprintf(fo, "%d\n", rst);
	return 0;	
}

int find(int x)
{
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

void uni(int x, int y)
{
	f[find(x)] = find(y);
}

int cmp(const void *a, const void *b)
{
	return ((edge *)a)->l - ((edge *)b)->l;
}