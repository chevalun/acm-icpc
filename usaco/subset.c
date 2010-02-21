/*
ID: chevalu2
LANG: C
TASK: subset
*/
#include <stdio.h>

unsigned int dp[500];

int main()
{
	FILE *fi = fopen("subset.in", "r");
	FILE *fo = fopen("subset.out", "w");
	int N, i, j, V;
	fscanf(fi, "%d", &N);
	if (N*(N+1)/2 & 1) {
		fprintf(fo, "%d\n", 0);
		return 0;			
	}
	V = N*(N+1)/4;
	dp[0] = 1;
	for (i = 0; i < N; ++i)
		for (j = V; j >= 0; --j)
			if (j >= i)
				dp[j] += dp[j-i];
	fprintf(fo, "%d\n", dp[V]/2);			
	return 0;
}