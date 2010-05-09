#include <stdio.h>
#include <math.h>

int has_common(int a, int b)
{
	int i;
	for(i = 2; i <= a; ++i)
		if ((a % i == 0) && (b % i == 0))
			return 1;
	return 0;		
}

int main()
{
	int N, i, tot, j, num[100];
	while(scanf("%d", &N) !=EOF ) {
		if(!N)
			break;
		for(i = 0; i < N; ++i)
			scanf("%d", &num[i]);
		tot = 0;	
		for(i = 0; i < N; ++i)
			for(j = i+1; j < N; ++j)
				if(!has_common(num[i], num[j]))
					++tot;
		if(tot)			
			printf("%lf\n", sqrt( 6.0/tot*(N*(N-1)/2)) );
		else
			printf("No estimate for this data set.\n");
	}
	return 0;
}