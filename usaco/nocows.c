/*
ID: chevalu2
LANG: C
TASK: nocows
*/
#include <stdio.h>

int dp[100][200];

int main()
{
	FILE *fi = fopen("nocows.in", "r");
	FILE *fo = fopen("nocows.out", "w");
	int i, j, N, K, k;
	fscanf(fi, "%d %d", &N, &K);
	for(i = 1; i <= K; ++i)
		dp[i][1] = 1;
	for(i = 1; i <= K; ++i)
		for(j = 3; j <= N; j += 2)
			for (k = 1; k <= j-2; k += 2)
				dp[i][j] = (dp[i][j] + dp[i-1][k]*dp[i-1][j-1-k]) % 9901;
	fprintf(fo, "%d\n", (dp[K][N] - dp[K-1][N] + 9901) % 9901);
	return 0;
}