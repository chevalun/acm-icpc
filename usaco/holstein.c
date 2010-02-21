/*
ID: chevalu2
LANG: C
TASK: holstein
*/
#include <stdio.h>

int V, G, rst = 16;
int v[25], g[15][25], r[15], temp[15], check[25];
void dfs(int s, int n);
 
int main()
{
	FILE *fi = fopen("holstein.in", "r");
	FILE *fo = fopen("holstein.out", "w");
	int i, j;
	fscanf(fi, "%d", &V);
	for(i = 0; i < V; ++i)
		fscanf(fi, "%d", &v[i]);
	fscanf(fi, "%d", &G);
	for(i = 0; i < G; ++i)
		for (j = 0; j < V; ++j)
			fscanf(fi, "%d", &g[i][j]);
	dfs(0, 0);
	fprintf(fo, "%d", rst);
	for (i = 0; i < rst; ++i)
		fprintf(fo, " %d", r[i] + 1);
	fputc('\n', fo);
	return 0;	
}

void dfs(int s, int n)
{
	int i, j;
	if (n >= rst)
		return;
	if (s == G) {
		for(i = 0; i < V; ++i)
			check[i] = 0;
		for(i = 0; i < n; ++i)
			for(j = 0; j < V; ++j)
				check[j] += g[temp[i]][j];
		for(i = 0; i < V; ++i)
			if (check[i] < v[i])
				return;	
		rst = n;		
		for(i = 0; i < rst; ++i)
			r[i] = temp[i];
		return;
	}
	temp[n] = s;
	dfs(s+1, n+1);
	dfs(s+1, n);
}