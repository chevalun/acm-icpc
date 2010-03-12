/*
ID: chevalu2
LANG: C
TASK: rockers
*/
#include <stdio.h>
#define max(a,b) ((a) > (b)) ? (a) : (b)

int dp[21][21][21];

int main()
{
	FILE *fi = fopen("rockers.in", "r");
	FILE *fo = fopen("rockers.out", "w");
	int i, j, k, time[21], N, T, M;
	fscanf(fi, "%d %d %d", &N, &T, &M);
	for(i = 1; i <= N; ++i)
		fscanf(fi, "%d", &time[i]);
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= M; ++j) {
			dp[i][j][0] = dp[i][j-1][T];
			for(k = 1; k <= T; ++k) {
				dp[i][j][k] = max(dp[i-1][j][k], dp[i][j][k-1]);
				if(k >= time[i])
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-time[i]] + 1);		
			}
		}
	fprintf(fo, "%d\n", dp[N][M][T]);	
	return 0;	
}