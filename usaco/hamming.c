/*
ID: chevalu2
LANG: C
TASK: hamming
*/
#include <stdio.h>
#include <stdlib.h>

int N, B, D, max;
int rst[64], dis[512][512], flag[512];
int cal(int a, int b);
void dfs(int s);
FILE *fo;

int main()
{
	FILE *fi = fopen("hamming.in", "r");
	fo = fopen("hamming.out", "w");
	int i, j;
	fscanf(fi, "%d %d %d", &N, &B, &D);
	max = (1 << B);
	for(i = 0; i < max; ++i)
		for(j = i; j < max; ++j) {
			dis[i][j] = cal(i, j);
			dis[j][i] = dis[i][j];
		}
	dfs(0);	
	return 0;
}

void dfs(int s)
{
	int i, j, f;
	if (rst[14] == 120)
		++i;
	if (s == N) {
		i = 0;
		while (N - 1 - i > 10) {
			for (j = 0; j < 9; ++j, ++i)
				fprintf(fo, "%d ", rst[i]);
			fprintf(fo, "%d\n", rst[i++]);
		}
		for (; i < N - 1; ++i)
			fprintf(fo, "%d ", rst[i]);
		fprintf(fo, "%d\n", rst[N-1]);
		exit(0);
	}
	j = s ? rst[s-1] : 0;
	for (i = j; i < max; ++i) {
		if (flag[i])
			continue;
		f = 1;	
		for(j = 0; j < s; ++j)
			if (dis[rst[j]][i] < D) {
				f = 0;
				break;
			}
		if (f) {
			flag[i] = 1;
			rst[s] = i;
			dfs(s+1);
			flag[i] = 0;
		}	
	}
}

int cal(int a, int b)
{
	int r = 0;
	while (a) {
		r += !((a & 1) == (b & 1));
		a >>= 1;
		b >>= 1;
	}
	while (b) {
		r += b & 1;
		b >>= 1;
	}
	return r;
}