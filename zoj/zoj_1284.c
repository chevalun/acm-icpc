#include <stdio.h>

int main()
{
	int temp, i, sum;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &temp) != EOF) {
		sum = 0;
		if (!temp)
			break;
		for(i = 1; i < temp; ++i)
			if (!(temp % i))
				sum += i;
		printf("%5d  ", temp);		
		if(sum == temp)
			printf("PERFECT\n");
		else if (sum < temp)
			printf("DEFICIENT\n");
		else
			printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
}