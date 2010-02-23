/*
ID: chevalu2
LANG: C
TASK: stamps
*/
#include <stdio.h>

int dp[100001];

int main()
{
	FILE *fi = fopen("stamps.in", "r");
	FILE *fo = fopen("stamps.out", "w");
	int N, K, stamp[50], i, j, m;
	fscanf(fi, "%d %d", &K, &N);
	for(i = 0; i < N; ++i)
		fscanf(fi, "%d", &stamp[i]);
	m = 0;
	for(i = 1; i < 100000; ++i)
		dp[i] = 500;
	for(;;) {
		++m;
		for(i = 0; i < N; ++i)
			for(j = stamp[i]; j <= m; ++j)
				if (dp[j] > dp[j-stamp[i]] + 1)
					dp[j] = dp[j-stamp[i]] + 1;
		if (dp[m] > K)
			break;
	}
	fprintf(fo, "%d\n", m-1);
	return 0;	
}