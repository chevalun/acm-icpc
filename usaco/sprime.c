/*
ID: chevalu2
LANG: C
TASK: sprime
*/
#include <stdio.h>

void dfs(int, int);
int is_prime(int);
int N;
FILE *fo;

int main()
{
	FILE *fi = fopen("sprime.in", "r");
	fo = fopen("sprime.out", "w");
	fscanf(fi, "%d", &N);
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);
	return 0;	
}

void dfs(int num, int s)
{
	if (!is_prime(num))
		return;
	if (s == N) {
		fprintf(fo, "%d\n", num);
		return;
	}
	dfs(num*10+1,s+1);
	dfs(num*10+3,s+1);
	dfs(num*10+7,s+1);
	dfs(num*10+9,s+1);
}

int is_prime(int n) {
	int i;
	if (n == 2)
		return 1;
	for (i = 2; i*i < n; ++i)
		if (n % i == 0)
			return 0;
	return 1;		
}
