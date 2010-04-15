#include <stdio.h>

int main()
{
	int i, N, m, n;
	scanf("%d", &N);
	for(i = 0; i < N; ++i) {
		scanf("%d %d", &m, &n);
		if(m*n & 1)
			printf("Scenario #%d:\n%d.41\n\n", i+1, m*n);
		else
			printf("Scenario #%d:\n%d.00\n\n", i+1, m*n);
	}
	return 0;
}