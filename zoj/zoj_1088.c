#include <stdio.h>

int count(int);

int main()
{
	int N;
	while(scanf("%d", &N) != EOF) {
		if(!N)
			break;
		printf("%d\n", count(N));
	}
	return 0;
}

int count(int x)
{
	int i, p, s, q, flag[200], k;
	q = 2;
	for(;;) {
		for(i = 0; i < x; ++i)
			flag[i] = 1;
		flag[0] = 0;	
		p = 0;
		s = 1;
		for(;;) {
			k = 0;
			while(k < q) {
				++p;
				if(p >= x)
					p %= x;
				if(flag[p])
					++k;
			}
			flag[p] = 0;
			++s;
			if(s == x) {
				if(p == 1)
					return q;
				break;	
			}
			if(p == 1)
				break;
		}
		++q;
	}
}