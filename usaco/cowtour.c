/*
ID: chevalu2
LANG: C
TASK: cowtour
*/
#include <stdio.h>
#include <math.h>

int map[151][2], N, matrix[151][151], flag[151], count[151], part[151][151];
double dis[151][151], m[151][151];
void dfs(int node, int mark);

int main()
{
	FILE *fi = fopen("cowtour.in", "r");
	FILE *fo = fopen("cowtour.out", "w");
	int i, j, cc = 0, k, p, q, a, b;
	double min = 1e60, temp;
	char c;
	fscanf(fi, "%d\n", &N);
	for(i = 1; i <= N; ++i)
		fscanf(fi, "%d %d\n", &map[i][0], &map[i][1]);
	for(i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			dis[i][j] = sqrt((map[i][0]-map[j][0])*(map[i][0]-map[j][0]) + (map[i][1]-map[j][1])*(map[i][1]-map[j][1]));
	for(i = 1; i <= N; ++i) {
		for(j = 1; j <= N; ++j) {
			c = fgetc(fi);
			matrix[i][j] = c - '0';
			if ((matrix[i][j]) || (i == j))
				m[i][j] = dis[i][j];
			else
				m[i][j] = 1e55;
		}
		fgetc(fi);
	}
	for(k = 1; k <= N; ++k)
		for(i = 1; i <= N; ++i)
			for(j = 1; j <= N; ++j)
				if (m[i][j] > m[i][k] + m[k][j])
					m[i][j] = m[i][k] + m[k][j];
	for(i = 1; i <= N; ++i)
		if (!flag[i]) {
			dfs(i, ++cc);
		}
	for(i = 1; i <= cc; ++i)
		for(j = i+1; j <= cc; ++j)
			for(p = 0; p < count[i]; ++p)
				for(q = 0; q < count[j]; ++q) {
					temp = 0;
					if (p == 2)
						temp = 0;
					for(a = 0; a < count[i]; ++a)
						for(b = 0; b < count[j]; ++b)
							if (m[part[i][a]][part[i][p]] + m[part[j][b]][part[j][q]] + dis[part[i][p]][part[j][q]] > temp)
								temp = m[part[i][a]][part[i][p]] + m[part[j][b]][part[j][q]] + dis[part[i][p]][part[j][q]];	
					if (temp < min)
						min = temp;
				}
	for(i = 1; i <= cc; ++i) {
		temp = 0;
		for(p = 0; p < count[i]; ++p)
			for(q = 0; q < count[i]; ++q)
				if (m[part[i][p]][part[i][q]] > temp)
					temp = m[part[i][p]][part[i][q]];
		if (temp > min)
			min = temp;
	}			
	fprintf(fo, "%lf\n", min);			
	return 0;	
}

void dfs(int node, int mark)
{
	int i;
	flag[node] = mark;
	part[mark][count[mark]++] = node;
	for(i = 1; i <= N; ++i)
		if (matrix[node][i] && !flag[i])
			dfs(i, mark);
}