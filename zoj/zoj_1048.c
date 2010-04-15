#include <stdio.h>

int main()
{
	int i;
	double now, sum = 0;
	for(i = 0; i < 12; ++i) {
		scanf("%lf", &now);
		sum += now;
	}
	printf("$%.2lf\n", sum/12);
	return 0;
}