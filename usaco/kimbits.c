/*
ID: chevalu2
LANG: C
TASK: kimbits
*/
#include <stdio.h>

unsigned long c[32][32];

int main()
{
	FILE *fi = fopen("kimbits.in", "r");
	FILE *fo = fopen("kimbits.out", "w");
	int N, L, i, j, t;
	unsigned long I;
	fscanf(fi, "%d %d %lud", &N, &L, &I);
	for(i = 0; i <= N; ++i)
		c[i][0] = 1;
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= L; ++j)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	for(i = 0; i <= N; ++i)
		for(j = 1; j <= L; ++j)
			c[i][j] += c[i][j-1];
	t = L;		
	for(i = N-1; i >= 0; --i) {
		if(c[i][t] < I) {
			fputc('1', fo);
			I -= c[i][t--];
		} else
			fputc('0', fo);
	}
	fputc('\n', fo);
	return 0;	
}