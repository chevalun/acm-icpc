/*
ID: chevalu2
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <stdlib.h>

void check(int, int);
void rot(int);
void ref(int);
void reset(int);
char s[20][20], tmp[20][20], rst[20][20];
FILE *fi, *fo;

int main()
{
	int N, i;
	fi = fopen("transform.in", "r");
	fo = fopen("transform.out", "w");
	fscanf(fi, "%d\n", &N);
	for (i = 0; i < N; ++i)
		fscanf(fi, "%s", s[i]);
	for (i = 0; i < N; ++i)
		fscanf(fi, "%s", rst[i]);	
	reset(N);
	rot(N);
	check(N, 1);
	rot(N);
	check(N, 2);
	rot(N);
	check(N, 3);
	reset(N);
	ref(N);
	check(N, 4);
	rot(N);
	check(N, 5);
	rot(N);
	check(N, 5);
	rot(N);
	check(N, 5);
	reset(N);
	check(N, 6);
	fprintf(fo, "7\n");			
	return 0;	
}

void check(int N, int w)
{
	int i, j;
	for (i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			if (tmp[i][j] != rst[i][j])
				return;
	fprintf(fo, "%d\n", w);
	exit(0);		
}

void reset(int N)
{
	int i, j;
	for (i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			tmp[i][j] = s[i][j];
}

void rot(int N)
{
	int i, j;
	char t[20][20];
	for (i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			t[i][j] = tmp[i][j];
	for (i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			tmp[i][j] = t[N-1-j][i];
}

void ref(int N)
{
	int i, j;
	char t[20][20];
	for (i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			t[i][j] = tmp[i][j];
	for (i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			tmp[i][j] = t[i][N-1-j];
}