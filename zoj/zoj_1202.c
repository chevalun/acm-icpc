#include <stdio.h>
#include <string.h>

double c[50][50], f[50];

int main()
{
	int i, j, num[50], sum = 0, count[20], N;
	double rst = 1;
	for(i = 0; i <= 50; ++i)
		c[i][0] = 1;
	for(i = 1; i <= 50; ++i)
		for(j = 1; j <= i; ++j)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	f[0] = 1;		
	for(i = 1; i <= 50; ++i)
		f[i] = f[i-1] * i;
	while(scanf("%d", &N) != EOF) {
		sum = 0;
		rst = 1;
		memset(count, 0, sizeof(count));
		for(i = 1; i <= 12; ++i)
			count[i] = 0;
		for(i = 0; i < N; ++i) {
			scanf("%d", &num[i]);
			sum += num[i];
			++count[num[i]];
		}
		for(i = 0; i < N; ++i) {
			rst *= c[sum][num[i]];
			sum -= num[i];
		}
		for(i = 1; i < 12; ++i)
			rst /= f[count[i]];
		printf("%.0lf\n", rst);	
	}	
	return 0;
}