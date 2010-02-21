/*
ID: chevalu2
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
int find(char *, int N);
char name[10][80];
int old[10];
int gain[10];

int main()
{
	FILE *fi = fopen("gift1.in", "r");
	FILE *fo = fopen("gift1.out", "w");
	char temp[80];

	int N, i, q, j, p;
	
	fscanf(fi, "%d", &N);
	for (i = 0; i < N; ++i)
		fscanf(fi, "%s", name[i]);
	for (i = 0; i < N; ++i) {
		fscanf(fi, "%s", temp);
		p = find(temp, N);
		fscanf(fi, "%d %d\n", &old[p], &q);
		if (!q)
			continue;
		gain[p] += old[p] - (old[p] / q) * q;
		for (j = 0; j < q; ++j) {
			fscanf(fi, "%s", temp);
			gain[find(temp, N)] += old[p] / q;
		}
	}
	for (i = 0; i < N; ++i) {
		fprintf(fo, "%s %d\n", name[i], gain[i] - old[i]);
	}
	return 0;	
}

int find(char *str, int N)
{
	int i;
	for (i = 0; i < N; ++i) {
		if (strcmp(str, name[i]) == 0)
			return i;
	}
}