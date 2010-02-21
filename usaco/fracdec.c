/*
ID: chevalu2
LANG: C
TASK: fracdec
*/
#include <stdio.h>
#include <string.h>


int pos[100000], r[200000];
char rst[200000];

int main()
{
	FILE *fi = fopen("fracdec.in", "r");
	FILE *fo = fopen("fracdec.out", "w");
	int N, D, temp, len, o, i;
	fscanf(fi, "%d %d", &N, &D);
	sprintf(rst, "%d.", N/D);
	N = N % D;
	if (!N) {
		fprintf(fo, "%s0\n", rst);
		return 0;
	}
	len = o = strlen(rst);
	pos[0] = 1;
	while(!pos[N]) {
		pos[N] = len;
		r[len++] = N * 10 / D;
		N = N * 10 % D;
	}
	if (!N) {
		for(i = o; i < len; ++i)
			rst[i] = r[i] + '0';
	} else {
		for(i = o; i < pos[N]; ++i)
			rst[i] = r[i] + '0';
		rst[i++] = '(';
		for(; i - 1 < len; ++i)
			rst[i] = r[i - 1] + '0';
		rst[i++] = ')';
	}
	for(i = 0; rst[i]; ++i) {
		fputc(rst[i], fo);
		if(i % 76 == 75)
			fputc('\n', fo);
	}
	fputc('\n', fo);
	return 0;	
}