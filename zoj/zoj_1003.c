#include <stdio.h>

int flag, rst, used[200], fb;
void dfs(int n, int p, int a);
void fact_a(int n, int p);

int main()
{
	int a, b, temp;
	while(scanf("%d %d", &a, &b) == 2) {
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		rst = b;
		fb = 0;
		dfs(b, 1, a);
		if(!fb)
			rst = a;
		printf("%d\n", rst);
	}
	return 0;
}

void dfs(int n, int p, int a)
{
	int i;
	if(n == 1) {
		fb = 1;
		flag = 0;
		fact_a(a, 1);
		if(flag == 1)
			rst = a;
		return;
	}	
	for(i = p; i <= 100; ++i) 
		if(n % i == 0) {
			used[i] = 1;
			dfs(n/i, i + 1, a);
			used[i] = 0;	
		}
}

void fact_a(int n, int p)
{
	int i;
	if(flag)
		return;
	if(n == 1) {
		flag = 1;
		return;
	}	
	for(i = p; i <= 100; ++i) 
		if(!used[i] && (n % i == 0))
			fact_a(n/i, i + 1);
}