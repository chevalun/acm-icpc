#include <stdio.h>

int main()
{
	int N, num, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; ++i) {
		scanf("%d", &num);
		for(j = 0; num > 1; ++j) {
			if(num & 1)
				printf("%d ", j);
			num >>= 1;	
		}
		if (num)
			printf("%d\n", j);
	}
}