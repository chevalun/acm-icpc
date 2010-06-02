#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, M, a, b, num[200], max, temp;
	scanf("%d\n", &N);
	while(N--) {
		scanf("%d", &M);
		memset(num, 0, sizeof(num));
		for(i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b);
			if(a > b) {
				temp = a;
				a = b;
				b = temp;
			}
			a = (a - 1) >> 1;
			b = (b - 1) >> 1;
			for(j = a; j <= b; ++j)
				++num[j];
		}
		max = 0;
		for(i = 0; i < 200; ++i)
			if(num[i] > max)
				max = num[i];
		printf("%d\n", max * 10);		
	}
}