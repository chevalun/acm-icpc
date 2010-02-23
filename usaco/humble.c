/*
ID: chevalu2
LANG: C
TASK: humble
*/
#include <stdio.h>

int num[100100];

int main()
{
	FILE *fi = fopen("humble.in", "r");
	FILE *fo = fopen("humble.out", "w");
	int N, K, k[100], p[100], c, t, i;
	double min;
	fscanf(fi, "%d %d", &K, &N);
	for(i = 0; i < K; ++i) {
		fscanf(fi, "%d", &k[i]);
		p[i] = 0;
	}
	num[0] = 1;
	c = 1;
	while(c <= N) {
		min = 1e50;
		for(i = 0; i < K; ++i)
			if(num[p[i]] * k[i] < min) {
				min = num[p[i]] * k[i];
				t = i;
			}
		++p[t];
		if(num[c-1] != min)
			num[c++] = min;
	}
	fprintf(fo, "%d\n", num[N]);
	return 0;	
}