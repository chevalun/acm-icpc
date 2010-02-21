/*
ID: chevalu2
LANG: C
TASK: crypt1
*/
#include <stdio.h>

int match(int n, int);
int digit[10];
int main()
{
	FILE *fi = fopen("crypt1.in", "r");
	FILE *fo = fopen("crypt1.out", "w");
	int i1, i2, i3, i4, i5, N, rst = 0, n1, n2;
	fscanf(fi, "%d", &N);
	for (i1 = 0; i1 < N; ++i1)
		fscanf(fi, "%d", &digit[i1]);
	for (i1 = 0; i1 < N; ++i1)
		for (i2 = 0; i2 < N; ++i2)
			for (i3 = 0; i3 < N; ++i3)
				for (i4 = 0; i4 < N; ++i4)
					for (i5 = 0; i5 < N; ++i5) {
						n1 = digit[i1] * 100 + digit[i2] * 10 + digit[i3];
						n2 = digit[i4] * 10 + digit[i5];
						if ((n1*digit[i4] < 1000) && (n1*digit[i5]<1000) && (n1*n2 < 10000) && match(n1*digit[i4], N) && match(n1*digit[i5], N) && match(n1*n2, N))
							++rst;
					}
	fprintf(fo, "%d\n", rst);						
	return 0;	
}

int match(int n, int NN)
{
	int i, r;
	while (n) {
		r = 0;
		for (i = 0; i < NN; ++i)
			if (n % 10 == digit[i])
				r = 1;
		if (!r)
			return 0;	
		n /= 10;		
	}
	return 1;
}