#include <stdio.h>

int main()
{
	int N, i, a, b, rst, n, m, o;
	scanf("%d\n", &N);
	for(i = 0; i < N; ++i) {
		o = 0;
		while(scanf("%d %d", &n, &m) != EOF) {
			++o;
			if (!n)
				break;
			rst = 0;	
			for(a = 1; a < n; ++a)
				for(b = a + 1; b < n; ++b)
					if ((a*a + b*b +m) % (a*b) == 0)
						++rst;
			printf("Case %d: %d\n", o, rst);			
		}
		if(i != N-1)
			printf("\n");
	}
	return 0;
}