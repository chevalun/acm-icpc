/*
ID: chevalu2
LANG: C
TASK: butter
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int s, t, dis;
};
typedef struct node path;
int cmp(const void *, const void *);
path p[3000];
int pos[810], map[810], q[1100], P;
void spfa(int start);

int main()
{
	FILE *fi = fopen("butter.in", "r");
	FILE *fo = fopen("butter.out", "w");
	int i, cow[810], C, N, j, temp, min = 9999999;
	fscanf(fi, "%d %d %d", &N, &P, &C);
	for(i = 0; i < N; ++i)
		fscanf(fi, "%d", &cow[i]);
	for(i = 0; i < C; ++i) {
		fscanf(fi, "%d %d %d", &p[i << 1].s, &p[i << 1].t, &p[i << 1].dis);
		p[(i << 1) + 1] = (path) { p[i << 1].t, p[i << 1].s, p[i << 1].dis };
	}
	C <<= 1;
	qsort(p, C, sizeof(path), cmp);
	for(i = 0; i < C; ++i)
		++pos[p[i].s];
	for(i = 1; i <= P; ++i)
		pos[i] += pos[i-1];
	for(i = 1; i <= P; ++i) {
		spfa(i);
		temp = 0;
		for(j = 0; j < N; ++j)
			temp += map[cow[j]];
		if (temp < min)
			min = temp;
	}	
	fprintf(fo, "%d\n", min);
	return 0;	
}

void spfa(int start)
{
	int s = 0, t = 1, i, o;
	for(i = 1; i <= P; ++i)
		map[i] = 99999999;
	map[start] = 0;	
	q[0] = start;
	do {
		for(i = pos[q[s]-1]; i < pos[q[s]]; ++i) {
			o = p[i].t;
			if(map[o] > map[q[s]] + p[i].dis) {
				map[o] = map[q[s]] + p[i].dis;
				q[t] = o;
				t = (t + 1) % 1000;
			}
		}
		s = (s + 1) % 1000;
	} while(t != s);
}

int cmp(const void *a, const void *b)
{
	return ((path *) a)->s - ((path *) b)->s;
}