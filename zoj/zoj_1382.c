#include <stdio.h>

int main()
{
	int N, i, num, p;
	scanf("%d", &N);
	for(i = 0; i < N; ++i) {
		scanf("%d", &num);
		p = 0;
		while (!(num & 1)) {
			++p;
			num >>= 1;
		}
		printf("%d %d\n", num, p);
	}
}