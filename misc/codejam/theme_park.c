#include <stdio.h>

int flag[1001];

int main()
{
	int T, i, j, R, k, N, g[1001], p, step, tot, r = 0, rst;
	scanf("%d\n", &T);
	for(i = 0; i < T; ++i) {
		scanf("%d %d %d", &R, &k, &N);
		for(j = 0; j < N; ++j)
			scanf("%d", g[j]);
		step = 1;
		p = 0;
		for(;;) {
			++r;
			if(r > R)
				break;
			tot = 0;
			flag[p] = step;
			for(; tot < k; ++p) {
				++step;
				tot += g[p];
				rst += g[p];
				if(p == k)
					p = 0;
			}
			++p;
			if(flag[p]) {
				break;
			}
		}
		
	}
	return 0;
}