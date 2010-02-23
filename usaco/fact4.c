/*
ID: chevalu2
LANG: C
TASK: fact4
*/
#include <stdio.h>

int main()
{
	FILE *fi = fopen("fact4.in", "r");
	FILE *fo = fopen("fact4.out", "w");
	int i, N, rst = 1, j, c = 0;
	int num[5000];
	fscanf(stdin, "%d", &N);
	for(i = 1; i <= N; ++i)
		num[i] = i;
	for(i = 5; i <= N; i+=5)
		while (num[i] % 5 == 0) {
			num[i] /= 5;
			++c;
		}
	for(i = 2; i <= N; i+=2)
		while ((num[i] % 2 == 0) && c) {
			num[i] /= 2;
			--c;
		}
	for(i = 1; i <= N; ++i)
		rst = num[i] * rst % 10;		
	fprintf(stdout, "%d\n", rst);
	return 0;	
}