#include <stdio.h>
#include <string.h>

int main()
{
	int N, tot, i, j, flag[101], m, k;
	scanf("%d", &N);
	for(k = 0; k < N; ++k) {
		scanf("%d", &m);
		tot = 0;
		memset(flag, 0, sizeof(flag));
		for(i = 1; i <= m; ++i)
			for(j = 1; j <= m; ++j)
				if (j % i == 0)
					flag[j] = !flag[j];
		for(i = 1; i <= m; ++i)
			if (flag[i])
				++tot;
		printf("%d\n", tot);		
	}
	return 0;
}