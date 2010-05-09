#include <stdio.h>

int main()
{
	int i, x[31], N, T, K;
	x[1] = 1;
	for(i = 2; i <= 30; ++i)
		x[i] = (x[i-1] << 1) + 1;
	scanf("%d", &T);
	for(i = 0; i < T; ++i) {
		scanf("%d %d", &N, &K);
		printf("Case #%d: ", i + 1);
		if( !( (K - x[N]) % (x[N] + 1)))
			printf("ON\n");
		else
			printf("OFF\n");
	}	
	return 0;
}