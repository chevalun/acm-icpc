/*
ID: chevalu2
LANG: C
TASK: nuggets
*/
#include <stdio.h>
int dp[90000];

int gcd(int a, int b)
{
	if(!b)
		return a;
	else	
		return gcd(b, a % b);
}

int main()
{
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	int N, w[20], d, i, j, max, temp;
	scanf("%d", &N);
	for(i = 0; i < N; ++i) 
		scanf("%d", &w[i]);
	d = w[0];	
	for(i = 1; i < N; ++i)
		d = gcd(d, w[i]);
	if(d != 1) {
		printf("0\n");
		return 0;
	}
	for(i = 0; i < N; ++i)
		for(j = i+1; j < N; ++j)
			if(w[i] > w[j]) {
				temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
	max = w[N-1] * w[N-2] / gcd(w[N-1], w[N-2]);	
	dp[0] = 1;
	for(i = 0; i < N; ++i)
		for(j = w[i]; j <= max; ++j)
			dp[j] |= dp[j-w[i]];
	dp[0] = 0;		
	for(i = max; dp[i]; --i)
		;
	printf("%d\n", i);	
	return 0;	
}