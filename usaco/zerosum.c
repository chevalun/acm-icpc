/*
ID: chevalu2
LANG: C
TASK: zerosum
*/
#include <stdio.h>

void dfs(int s);
int check();
int N;
char rst[20];
FILE *fo;

int main()
{
	FILE *fi = fopen("zerosum.in", "r");
	fo = fopen("zerosum.out", "w");
	int i;
	fscanf(fi, "%d", &N);
	for(i = 0; i < N; ++i)
		rst[i << 1] = i + '1';
	dfs(0);
	return 0;	
}

void dfs(int s)
{
	if (s == N - 1) {
		if (!check())
			fprintf(fo, "%s\n", rst);
		return;
	}
	rst[(s << 1) + 1] = ' '; dfs(s+1);
	rst[(s << 1) + 1] = '+'; dfs(s+1);
	rst[(s << 1) + 1] = '-'; dfs(s+1);
}

int check()
{
	int i, r = 0, M = (N << 1) - 2, tmp = rst[0] - '0', flag = 1;
	for(i = 1; i < M; i += 2) {
		if (rst[i] == ' ')
			tmp = tmp * 10 + flag * (rst[i+1] - '0');
		else if (rst[i] == '+') {
			flag = 1;
			r += tmp;
			tmp = rst[i+1] - '0';
		} else {
			flag = -1;
			r += tmp;
			tmp = -(rst[i+1] - '0');
		}
	}
	r += tmp;
	return r;
}
