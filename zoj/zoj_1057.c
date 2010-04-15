#include <stdio.h>

int main()
{
	int N, i, a[20], temp, as, bs, k = 0;
	while(scanf("%d", &N) != EOF) {
		++k;
		if(!N)
			break;
		if(k > 1)
			putchar('\n');	
		as = bs = 0;	
		for(i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		for(i = 0; i < N; ++i) {
			scanf("%d", &temp);
			if (temp == a[i])
				continue;
			if (a[i] - temp > 1)
				as += a[i];
			else if (temp - a[i] > 1)
				bs += temp;
			else if (temp == 1)
				bs += 6;
			else if (a[i] == 1)
				as += 6;
			else if (a[i] < temp)
				as += a[i] + temp;
			else
				bs += a[i] + temp;
		}
		printf("A has %d points. B has %d points.\n", as, bs);
	}
	return 0;
}