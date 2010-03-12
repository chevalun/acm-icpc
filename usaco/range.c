/*
ID: chevalu2
LANG: C
TASK: range
*/

#include <stdio.h>
#define min (((x) < (y)) ? (x) : (y))
int dp[251][251], tot[251];
char map[251][251];

int main()
{
	FILE *fi = fopen("range.in", "r");
	FILE *fo = fopen("range.out", "w");	
	int N, i, j, k;
	fscanf(fi, "%d\n", &N);
	for(i = 1; i <= N; ++i) {
		for(j = 1; j <= N; ++j)
			fscanf(fi, "%c", &map[i][j]);
		fgetc(fi);
	}
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= N; ++j) {
			map[i][j] -= '0';
		}
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= N; ++j) {
			if (map[i][j]) {
				for(k = 2; (k <= dp[i-1][j-1] + 1) && ((i-k) >= 0) && ((j-k) >= 0) && map[i][j-k+1] && map[i-k+1][j]; ++k)
					;
				dp[i][j] = k-1;
			}	
		}
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= N; ++j)
			for(k = 2; k <= dp[i][j]; ++k)
				tot[k] += 1;
	for(i = 2; i <= N; ++i)
		if (tot[i])
			fprintf(fo, "%d %d\n", i, tot[i]);
	return 0;
}