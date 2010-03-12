/*
ID: chevalu2
LANG: C
TASK: game1
*/

#include <stdio.h>
#define range(a, b) (sum[b] - sum[a-1])
#define max(a, b) ((a>b) ? (a) : (b))

int N, data[101], sum[101], m[101][101];
int dp(int x, int y);

int main()
{
	FILE *fi = fopen("game1.in", "r");
	FILE *fo = fopen("game1.out", "w");
	int i, rst;
	fscanf(fi, "%d", &N);
	for(i = 1; i <= N; ++i) {
		fscanf(fi, "%d", &data[i]);
		sum[i] = data[i];
	}
	for(i = 2; i <= N; ++i)
		sum[i] += sum[i-1];
	rst = dp(1, N);
	fprintf(fo, "%d %d\n", rst, range(1, N) - rst);
	return 0;	
}

int dp(int x, int y)
{
	if(m[x][y])
		return m[x][y];
	if (x == y)
		return m[x][y] = data[x];
	return m[x][y] = max(data[x] + range(x+1,y) - dp(x+1,y), data[y] + range(x, y-1) - dp(x,y-1));
}