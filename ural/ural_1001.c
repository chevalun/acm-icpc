#include <stdio.h>
#include <math.h>

double num[300000];
int main()
{
	int n = 0, i;
	while (scanf("%lf", &num[n]) > 0)
		++n;
	for (i = n-1; i >= 0; --i)
		printf("%.4lf\n", sqrt(num[i]));
	return 0;
}