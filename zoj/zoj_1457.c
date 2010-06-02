#include <stdio.h>

int N;
int num[21], flag[21], prime[50], nn[21];
int table[21][21];
void dfs(int x);

int main()
{
	int i, s = 0, j;
	prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] =  prime[31] = prime[37] = 1;
 	while(scanf("%d", &N) != EOF) {
		printf("Case %d:\n", ++s);
		if(N & 1) {
			putchar('\n');
			continue;
		}
		for(i = 0; i <= N; ++i) {
			flag[i] = 1;
			nn[i] = 0;
		}
		for(i = 1; i <= N; ++i)
			for(j = i + 1; j <= i + N; ++j)
				if(prime[j]) {
					table[i][nn[i]++] = j - i;
				}
		num[0] = 1;
		flag[1] = 0;
		dfs(1);
		putchar('\n');
	}
	return 0;
}

void dfs(int x)
{
	int i;
	if (x == N) {
		if(prime[num[N-1] + 1]) {
			for(i = 0; i < N - 1; ++i)
				printf("%d ", num[i]);
			printf("%d\n", num[N-1]);	
		}
		return;
	}
	
	for(i = 0; i < nn[num[x - 1]]; ++i)
		if(flag[table[num[x-1]][i]]) {
			flag[table[num[x-1]][i]] = 0;
			num[x] = table[num[x-1]][i];
			dfs(x+1);
			flag[table[num[x-1]][i]] = 1;
		}
}