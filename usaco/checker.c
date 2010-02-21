/*
ID: chevalu2
LANG: C
TASK: checker
*/
#include <stdio.h>
#include <stdlib.h>

int N, r;
void dfs(int row, int ld, int rd);
void dfs_show(int row, int col, int ld, int rd);
int rst[13];
FILE *fo;
int upper;

int main()
{
	FILE *fi = fopen("checker.in", "r");
	int i;
	fo = fopen("checker.out", "w");
	fscanf(fi, "%d", &N);
	dfs_show(0, 0, 0, 0);
	r = 0;
	upper = (1 << N) -1;
	dfs(0, 0, 0);
	fprintf(fo, "%d\n", r);
	return 0;	
}

void dfs(int row, int ld, int rd)
{
	int p, pos;
	if (row != upper) {
		pos = upper & ~(row | ld | rd);
		while(pos) {
			p = pos & (~pos + 1);
			pos -= p;
			dfs(row | p, (ld | p) >> 1, (rd | p) << 1);
		}
	}
	else
		++r;
}

void dfs_show(int row, int col, int ld, int rd)
{
	int y;
	if (r == 3)
		return;
	if (row == N) {
		++r;
		for (y = 0; y < N-1; ++y)
			fprintf(fo, "%d ", rst[y]+1);
		fprintf(fo, "%d\n", rst[N-1]+1);
		return;
	}
	
	for (y = 0; y < N; ++y)
		if (!(col & (1 << y)) && !(ld & (1 << (row-y+N-1))) && !(rd & (1 << (row+y)))) {
			rst[row] = y;
			dfs_show(row+1, col | (1 << y), ld | (1 << (row-y+N-1)), rd | (1 << (row+y)));
		}
}