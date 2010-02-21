/*
ID: chevalu2
LANG: C
TASK: comehome
*/
#include <stdio.h>
#include <ctype.h>
#define MAXN 150

int map[MAXN][MAXN], flag[MAXN];
void floyd();

int main()
{
	FILE *fi = fopen("comehome.in", "r");
	FILE *fo = fopen("comehome.out", "w");
	int P, d, i, j, k, min = 1 << 21, r;
	char s, t;
	for(i = 0; i < MAXN; ++i)
		for(j = 0; j < MAXN; ++j)
			map[i][j] = 1 << 20;
	fscanf(fi, "%d\n", &P);
	for(i = 0; i < P; ++i) {
		fscanf(fi, "%c %c %d\n", &s, &t, &d);
		if (d < map[s][t]) {
			map[s][t] = d;
			map[t][s] = d;
		}
	}
	floyd();
	for(i = 'A'; i <= 'Y'; ++i)
		if (map['Z'][i] < min) {
			min = map['Z'][i];
			r = i;
		}
	fprintf(fo, "%c %d\n", r, min);	
	return 0;	
}

void floyd(int source)
{
	int i, j, k;
	for(k = 0; k < MAXN; ++k)
		for(i = 0; i < MAXN; ++i)
			for(j = 0; j < MAXN; ++j)
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
}