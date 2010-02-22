/*
ID: chevalu2
LANG: C
TASK: maze1
*/
#include <stdio.h>

int W, H, max = 0;
int map[101][40][4], d[101][40];
void bfs(int h, int w);

int main()
{
	FILE *fi = fopen("maze1.in", "r");
	FILE *fo = fopen("maze1.out", "w");
	int i, j, st[2][2], s = 0;
	char c;
	fscanf(fi, "%d %d\n", &W, &H);
	for(i = 1; i <= H; ++i)	
		for(j = 1; j <= W; ++j)	
			d[i][j] = 1 << 20;
	for(i = 1; i <= 2*H+1; ++i) {
		for(j = 1; j <= 2*W+1; ++j) {
			c = fgetc(fi);
			if (c == '-') {
				map[i/2][j/2][0] = 1;
				map[i/2+1][j/2][1] = 1;
			}
			else if (c == '|') {
				map[i/2][j/2][2] = 1;
				map[i/2][j/2 + 1][3] = 1;
			}
			else if ((c == ' ') && ((i == 1) || (i == 2*H+1) || (j == 1) || (j == 2*W+1))) {
				st[s][0] = i/2;
				st[s][1] = j/2;
				if(st[s][0] == 0)
					++st[s][0];
				if(st[s][1] == 0)
					++st[s][1];					
				++s;
			}
		}
		c = fgetc(fi);
	}
	bfs(st[0][0], st[0][1]);
	bfs(st[1][0], st[1][1]);
	for(i = 1; i <= H; ++i)	
		for(j = 1; j <= W; ++j)	
			if (d[i][j] > max)
				max = d[i][j];
	fprintf(fo, "%d\n", max+1);
	return 0;	
}

void bfs(int h, int w)
{
	int q[4000][2], dis[4000], s = 0, t = 1, flag[101][40], i, j;
	for(i = 0; i < 4000; ++i)
		dis[i] = 0;
	for(i = 1; i <= H; ++i)	
		for(j = 1; j <= W; ++j)	
			flag[i][j] = 0;
	q[0][0] = h; q[0][1] = w;
	flag[h][w] = 1;
	while(s < t) {
		if ((!map[q[s][0]][q[s][1]][0]) && (q[s][0] != H) && (!flag[q[s][0] + 1][q[s][1]])) {
			q[t][0] = q[s][0] + 1;
			q[t][1] = q[s][1];
			flag[q[t][0]][q[t][1]] = 1;
			dis[t] = dis[s] + 1;
			++t;
		}
		if ((!map[q[s][0]][q[s][1]][1]) && (q[s][0] != 1) && (!flag[q[s][0] - 1][q[s][1]])) {
			q[t][0] = q[s][0] - 1;
			q[t][1] = q[s][1];
			flag[q[t][0]][q[t][1]] = 1;
			dis[t] = dis[s] + 1;
			++t;
		}
		if ((!map[q[s][0]][q[s][1]][2]) && (q[s][1] != W) && (!flag[q[s][0]][q[s][1] + 1])) {
			q[t][0] = q[s][0];
			q[t][1] = q[s][1] + 1;
			flag[q[t][0]][q[t][1]] = 1;
			dis[t] = dis[s] + 1;
			++t;
		}
		if ((!map[q[s][0]][q[s][1]][3]) && (q[s][1] != 1) && (!flag[q[s][0]][q[s][1] - 1])) {
			q[t][0] = q[s][0];
			q[t][1] = q[s][1] - 1;
			flag[q[t][0]][q[t][1]] = 1;
			dis[t] = dis[s] + 1;
			++t;
		}
		++s;
	}
	for(i = 0; i < s; ++i)
		if (dis[i] < d[q[i][0]][q[i][1]])
			d[q[i][0]][q[i][1]] = dis[i];
}