#include <stdio.h>

int main()
{
	int i, f = 2;
	double rst = 2.5;
	printf("n e\n");
	printf("- -----------\n0 1\n1 2\n2 2.5\n");
	for(i = 3; i < 10; ++i) {
		f *= i;
		printf("%d %.9lf\n", i, rst += (double) 1 / f);
	}
	return 0;
}