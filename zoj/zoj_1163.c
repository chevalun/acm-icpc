#include <stdio.h>

double dp[501];

int main()
{
	int i, j, x;
	dp[0] = 1;
	for(j = 1; j < 501; ++j)
		for(i = 500; i >= j; --i)
			dp[i] += dp[i-j];
	while(scanf("%d", &x) && x)
		printf("%.0lf\n", dp[x] - 1);
	return 0;			
}