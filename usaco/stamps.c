/*
ID: chevalu2
LANG: C
TASK: stamps
*/
#include <stdio.h>

int dp[2000002];

int main()
{
	FILE *fi = fopen("stamps.in", "r");
	FILE *fo = fopen("stamps.out", "w");
	int N, K, stamp[50], i, j, m, max = 0;
	fscanf(fi, "%d %d", &K, &N);
	for(i = 0; i < N; ++i) {
		fscanf(fi, "%d", &stamp[i]);
		if (stamp[i] > max)
			max = stamp[i];
	}
	m = max * K + 1;
	for(i = 1; i < m; ++i)
		dp[i] = 500;
	for(i = 0; i < N; ++i)
		for(j = stamp[i]; j <= m; ++j)
			if (dp[j] > dp[j-stamp[i]] + 1)
				dp[j] = dp[j-stamp[i]] + 1;
	for(i = 1; i < m; ++i)
		if (dp[i] > K)
			break;
	fprintf(fo, "%d\n", i-1);
	return 0;	
}