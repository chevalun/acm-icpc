/*
ID: chevalu2
LANG: C
TASK: inflate
*/
#include <stdio.h>

long long dp[10001];

int main()
{
	FILE *fi = fopen("inflate.in", "r");
	FILE *fo = fopen("inflate.out", "w");
	int N, i, j, V, o[25];
	fscanf(fi, "%d %d", &V, &N);
	for(i = 0; i < V; ++i)
		fscanf(fi, "%d", &o[i]);
	dp[0] = 1;	
	for(i = 0; i < V; ++i)
		for(j = o[i]; j <= N; ++j)
			dp[j] += dp[j-o[i]];
	fprintf(fo, "%lld\n", dp[N]);
	return 0;	
}