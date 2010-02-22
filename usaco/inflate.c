/*
ID: chevalu2
LANG: C
TASK: inflate
*/
#include <stdio.h>

int dp[10001], v[10001], m[10001];

int main()
{
	FILE *fi = fopen("inflate.in", "r");
	FILE *fo = fopen("inflate.out", "w");
	int N, i, j, V;
	fscanf(fi, "%d %d", &V, &N);
	for(i = 0; i < N; ++i)
		fscanf(fi, "%d %d", &v[i], &m[i]);
	dp[0] = 0;	
	for(j = 0; j < N; ++j)
		for(i = m[j]; i <= V; ++i)
			if (dp[i] < dp[i-m[j]] + v[j])
				dp[i] = dp[i-m[j]] + v[j];
	fprintf(fo, "%d\n", dp[V]);
	return 0;	
}