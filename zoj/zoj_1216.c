#include <stdio.h>

int main()
{
	int N, i;
	double rst[100000];
	rst[0] = 0.0;
	for(i = 1; i < 100000; ++i)
		rst[i] = rst[i-1] + 1.0 / (2.0*i);
	printf("# Cards  Overhang\n");	
	while(scanf("%d", &N) != EOF) {
		printf("%5d     %.3lf\n", N, rst[N]);
	}        
	return 0;
}