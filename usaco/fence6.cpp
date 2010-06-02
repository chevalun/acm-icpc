/*
ID: chevalu2
LANG: C++
TASK: fence6
*/

#include <cstdio>

int visit[101], len[101], flag[101][101], l[101][101], r[101][101], ln[101], rn[101], min = 9999999;

void dfs(int s, int f, int length)
{
	visit[s] = 1;
	if(flag[s][f]) {
		for(int i = 0; i < ln[s]; ++i)
			if(!visit[l[s][i]])
				dfs(l[s][i], s, length + len[s]);
			else if (length + len[s] < min)
				min = length + len[s];
	}
	else {
		for(int i = 0; i < rn[s]; ++i)
			if(!visit[r[s][i]])
				dfs(r[s][i], s, length + len[s]);
			else if (length + len[s] < min)
				min = length + len[s];
	}
	visit[s] = 0;
}

int main()
{
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int s;
		scanf("%d", &s);
		scanf("%d %d %d", &len[s], &ln[s], &rn[s]);
		for(int j = 0; j < ln[s]; ++j) {
			scanf("%d", &l[s][j]);
			flag[s][l[s][j]] = 0;
		}
		for(int j = 0; j < rn[s]; ++j) {
			scanf("%d", &r[s][j]);
			flag[s][r[s][j]] = 1;
		}
	}
	for(int i = 1; i < N; ++i)
		dfs(i, 0, 0);
	printf("%d\n", min);	
	return 0;	
}	