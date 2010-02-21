/*
ID: chevalu2
LANG: C
TASK: clocks
*/
#include <stdio.h>
#include <string.h>

void dfs(int);
int c[9], rst[9], r[9];
char way[][7] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
char s[200];
double min = 1e50;

int main()
{
	FILE *fi = fopen("clocks.in", "r");
	FILE *fo = fopen("clocks.out", "w");
	int i, j, p = 0;
	
	for (i = 0; i < 9; ++i)
		fscanf(fi, "%d", &c[i]);
	dfs(0);
	for (i = 0; i < 9; ++i)
		for (j = 0; j < r[i]; ++j) {
			s[p++] = '1' + i;
			s[p++] = ' ';
		}
	for(i = 0; i < strlen(s)-1; ++i)
		fputc(s[i], fo);
	fputc('\n', fo);
	return 0;	
}

void dfs(int n)
{
	int i, j;
	double num = 0;
	if (n == 9) {
		for (i = 0; i < 9; ++i)
			if (c[i] % 12)
				return;
		for (i = 0; i < 9; ++i)
			for (j = 0; j < rst[i]; ++j)
				num = num*10 + i + 1;
		if (num < min) {
			for (i = 0; i < 9; ++i)
				r[i] = rst[i];
		}
		return;
	}
	for(j = 0; j <= 3; ++j) {
		for(i = 0; way[n][i]; ++i)
			c[way[n][i]-'A'] = (c[way[n][i]-'A'] + 3*j) % 12;
		rst[n] = j;	
		dfs(n+1);
		for(i = 0; way[n][i]; ++i)
			c[way[n][i]-'A'] = (c[way[n][i]-'A'] - 3*j + 12) % 12;
	}
}