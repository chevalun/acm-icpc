#include <stdio.h>

int main()
{
	long max, temp;
	scanf("%ld", &max);
	while (scanf("%ld", &temp) > 0) {
		if (temp > max)
			max = temp;
	}
	printf("%ld\n", max);
}