/*
ID: chevalu2
LANG: C
TASK: concom
*/
#include <stdio.h>

int s[101][101], flag[101][101];
int intr();

int main()
{
	FILE *fi = fopen("concom.in", "r");
	FILE *fo = fopen("concom.out", "w");
	int a, b, p, i, j, N;
	fscanf(fi, "%d", &N);
	for(i = 0; i < N; ++i) {
		fscanf(fi, "%d %d %d", &a, &b, &p);
		s[a][b] = p;
	}
	while (intr())
		;
	for(i = 1; i <= 100; ++i)
		for (j = 1; j <= 100; ++j)
			if ((i != j) && (s[i][j] > 50))
				fprintf(fo, "%d %d\n", i, j);
	return 0;	
}

int intr()
{
	int i, j, k, rst = 0;
	for(i = 1; i <= 100; ++i)
		for (j = 1; j <= 100; ++j)
			if ((i != j) && (s[i][j] > 50) && (!flag[i][j])) {
				flag[i][j] = 1;
				for(k = 1; k <= 100; ++k) {
					s[i][k] += s[j][k];
					if (s[i][k] > 50)
						rst = 1;
					if (s[i][k] > 50)
						s[i][k] = 100;	
				}
			}
	return rst;		
}