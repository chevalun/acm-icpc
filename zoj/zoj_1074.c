#include <stdio.h>

int dp[101][101], sum[101][101];

int main()
{
	int N, i, j, k, max = 0, tot, m = -250;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= N; ++j) {
			scanf("%d", &sum[i][j]);
			if (sum[i][j] > m)
				m = sum[i][j];
			sum[i][j] += sum[i][j-1];
		}	
	for(i = 1; i <= N; ++i)	
		for(j = i; j <= N; ++j)  {
			tot = 0;
			for(k = 1; k <= N; ++k) {
				tot += sum[k][j] - sum[k][i-1];
				if (tot > max)
					max = tot;
				if (tot < 0)
					tot = 0;
			}
		}
	if (!max)
		max = m;
	printf("%d\n", max);	
	return 0;
}