#include <stdio.h>
#include <string.h>

int dp[110001];

int main()
{
	int i, j ,cash, N, n[1001], d[1001], s, max, k, temp;
	while(scanf("%d %d", &cash, &N) == 2) {
		s = 0;
		for(i = 0; i < N; ++i)
			scanf("%d %d", &n[i], &d[i]);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		max = 0;
		for(i = 0; i < N; ++i)
			for(j = max; j >= 0; --j)
				if(dp[j])
					for(k = 1; k <= n[i]; ++k) {
						temp = j + k*d[i];
						if(temp > cash)
							break;
						if(temp > max)
							max = temp;
						dp[temp] = 1;
					}
		printf("%d\n", max);		
	}
	return 0;
}