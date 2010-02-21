/*
ID: chevalu2
LANG: C
TASK: numtri
*/
#include <stdio.h>
#define MAX(x, y) ((x) > (y)) ? x : y

int data[1000][1000];

int main()
{
	FILE *fi = fopen("numtri.in", "r");
	FILE *fo = fopen("numtri.out", "w");
	int i, j, N;
	fscanf(fi, "%d", &N);
	for(i = 0; i < N; ++i)
		for(j = 0; j <= i; ++j)
			fscanf(fi, "%d", &data[i][j]);
	for(i = N-2; i >= 0; --i)
		for(j = 0; j <= i; ++j)
			data[i][j] += MAX(data[i+1][j], data[i+1][j+1]);
	fprintf(fo, "%d\n", data[0][0]);
	return 0;	
}