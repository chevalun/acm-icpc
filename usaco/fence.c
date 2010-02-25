/*
ID: chevalu2
LANG: C
TASK: fence
*/
#include <stdio.h>
#include <stdlib.h>

int map[501][501], degree[501];
int x;
int rst[2000];
FILE *fo;
void dfs(int);

int main()
{
	FILE *fi = fopen("fence.in", "r");
	int N, i, s, a, b;
	fo = fopen("fence.out", "w");
	fscanf(fi, "%d\n", &N);
	for(i = 0; i < N; ++i) {
		fscanf(fi, "%d %d", &a, &b);
		++map[a][b]; ++map[b][a]; ++degree[a]; ++degree[b];
	}
	s = 0;
	for(i = 1; i <= 500; ++i)
		if(degree[i] & 1) {
			s = i;
			break;
		}
	if(!s)
		s = 1;
	dfs(s);
	for(i = x-1; i >= 0; --i)
		fprintf(fo, "%d\n", rst[i]);
	return 0;	
}

void dfs(int v)
{
	int i;
	for(i = 1; i <= 500; ++i)
		if (map[v][i]) {
			--map[v][i];
			--map[i][v];
			dfs(i);
		}
	rst[x++] = v;	
}