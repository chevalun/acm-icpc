/*
ID: chevalu2
LANG: C
TASK: castle
*/
#include <stdio.h>

int M, N;
int map[50][50], flag[50][50], count[50*50];
void dfs(int x, int y, int mark);

int main()
{
	FILE *fi = fopen("castle.in", "r");
	FILE *fo = fopen("castle.out", "w");
	int i, j, mark = 0, max = 0, a, b, o;
	fscanf(fi, "%d %d", &M, &N);
	for(i = 0; i < N; ++i)
		for(j = 0; j < M; ++j) {
			fscanf(fi, "%d", &map[i][j]);
		}
	for(i = 0; i < N; ++i)
		for(j = 0; j < M; ++j)
			if (!flag[i][j]) {
				++mark;
				dfs(i, j, mark);
				if (count[mark] > max)
					max = count[mark];
			}
	fprintf(fo, "%d\n", mark);
	fprintf(fo, "%d\n", max);
	max = 0;
	for(j = 0; j < M; ++j)
		for(i = N-1; i >= 0; --i)	{
			if ((i > 0) && (flag[i-1][j] != flag[i][j]) && (count[flag[i-1][j]] + count[flag[i][j]] > max)) {
				max = count[flag[i-1][j]] + count[flag[i][j]];
				a = i;
				b = j;
				o = 'N';
			}
			if ((j < M-1) && (flag[i][j+1] != flag[i][j]) && (count[flag[i][j+1]] + count[flag[i][j]] > max)) {
				max = count[flag[i][j+1]] + count[flag[i][j]];
				a = i;
				b = j;
				o = 'E';
			}
		}
	fprintf(fo, "%d\n%d %d %c\n", max, a+1, b+1, o);	
	return 0;
}

void dfs(int a, int b, int mark)
{
	if ((a < 0) || (b >= M) || (b < 0) || (a >= N))
		return;
	if (flag[a][b])
		return;
	flag[a][b] = mark;
	++count[mark];
	if (!(map[a][b] & 1))
		dfs(a, b-1, mark);
	if (!(map[a][b] & 2))
		dfs(a-1, b , mark);
	if (!(map[a][b] & 4))
		dfs(a, b+1 , mark);
	if (!(map[a][b] & 8))
		dfs(a+1, b , mark);			
}