/*
ID: chevalu2
LANG: C
TASK: camelot
*/
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)

int min[31][31][31][31], R, C, kc, kr, c[1000], r[1000], all[31][31], q[1000][3], flag[31][31];
int jump[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
int bfs(int x1, int y1);

int main()
{
	FILE *fi = fopen("camelot.in", "r");
	FILE *fo = fopen("camelot.out", "w");
	int cc = 0, tr, i, j, k, i1, i2, j1, ro, co, rst, m = 10000000;
	char kc, tc;
	fscanf(fi, "%d %d\n", &R, &C);
	fscanf(fi, "%c %d\n", &kc, &kr);
	kc = kc - 'A' + 1;
	while((tc = fgetc(fi)) != EOF) {
		if ((tc >= 'A') && (tc <= 'Z')) {
			fscanf(fi, "%d", &tr);
			c[cc] = tc - 'A' + 1;
			r[cc] = tr;
			++cc;
		}
	}
	for(i = 1; i <= R; ++i)
		for(j = 1; j <= C; ++j)
			for(i1 = 1; i1 <= R; ++i1)
				for(j1 = 1; j1 <= C; ++j1)
					min[i][j][i1][j1] = 10000;
	for(i = 1; i <= R; ++i)
		for(j = 1; j <= C; ++j)
			bfs(i,j);
	for(i = 1; i <= R; ++i)
		for(j = 1; j <= C; ++j)
			for(k = 0; k < cc; ++k)
				all[i][j] += min[i][j][r[k]][c[k]];
	for(ro = 1; ro <= R; ++ro)
		for(co = 1; co <= C; ++co) {
			if(all[ro][co] > m)
				continue;
			rst = max(abs(kc-co), abs(kr-ro));
			rst += all[ro][co];
			if(rst < m)
				m = rst;
			for(i1 = -1; i1 <= 1; ++i1)
				for(i2 = -1; i2 <= 1; ++i2)
					for(k = 0; (kr+i1 <= R)&&(kc+i2 <= C)&&(kr+i1 >= 1)&&(kc+i2 >= 1)&&(k < cc); ++k) {
						rst = max(abs(i1), abs(i2));
						rst += min[kr+i1][kc+i2][ro][co] + min[r[k]][c[k]][kr+i1][kc+i2];
						rst += all[ro][co] - min[r[k]][c[k]][ro][co];
						if(rst < m)
							m = rst;		
					}
		}
	fprintf(fo, "%d\n", m);					
	return 0;	
}

int bfs(int y1, int x1)
{
	int s = 0, t = 1, i, j;
	for(i = 1; i <= R; ++i)
		for(j = 1; j <= C; ++j)
			flag[i][j] = 0;
	q[s][0] = y1;
	q[s][1] = x1;
	q[s][2] = 0;
	min[y1][x1][y1][x1] = 0;
	flag[y1][x1] = 1;
	while(s < t) {
		for(i = 0; i < 8; ++i)
			if ((q[s][0] + jump[i][0] >= 1) && (q[s][0] + jump[i][0] <= R) && (q[s][1] + jump[i][1] >= 1) 
			&& (q[s][1] + jump[i][1] <= C) && !flag[q[s][0] + jump[i][0]][q[s][1] + jump[i][1]]) {
				q[t][0] = q[s][0] + jump[i][0];
				q[t][1] = q[s][1] + jump[i][1];
				q[t][2] = q[s][2] + 1;
				min[y1][x1][q[t][0]][q[t][1]] = q[t][2];
				flag[q[t][0]][q[t][1]] = 1;
				++t;
			}
		++s;	
	}
}