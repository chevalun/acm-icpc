/*
ID: chevalu2
LANG: C
TASK: milk2
*/
#include <stdio.h>
short int flag[1000000];
int m[2], c[2];
int main()
{
	FILE *fi = fopen("milk2.in", "r");
	FILE *fo = fopen("milk2.out", "w");
	int N, i, j, s, t, max = 0, min = 2<<20;
	fscanf(fi, "%d\n", &N);
	for (i = 0; i < N; ++i) {
		fscanf(fi, "%d %d\n", &s, &t);
		for (j = s; j < t; ++j)
			flag[j] = 1;
		if (t > max)
			max = t;
		if (s < min)
			min = s;
	}
	for (i = min; i <= max; ++i) {
		if (flag[i] != flag[i-1]) {
			if (c[flag[i-1]] > m[flag[i-1]])
				m[flag[i-1]] = c[flag[i-1]];
			c[flag[i-1]] = 0;	
		}
		++c[flag[i]];
	}
	fprintf(fo, "%d %d\n", m[1], m[0]);
	return 0;	
}