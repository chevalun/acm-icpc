/*
ID: chevalu2
LANG: C
TASK: milk3
*/
#include <stdio.h>

int r[30];
int rf[30];
int rst;
int flag[25][25][25];
void dfs(int, int, int);
int A, B, C;

int main()
{
	FILE *fi = fopen("milk3.in", "r");
	FILE *fo = fopen("milk3.out", "w");
	int i, j, tmp;
	fscanf(fi, "%d %d %d", &A, &B, &C);
	dfs(0, 0, C);
	for (i = 0; i < rst; ++i)
		for (j = i+1; j < rst; ++j)
			if(r[i]>r[j]) {
				tmp = r[i];
				r[i] = r[j];
				r[j] = tmp;
			}
	for(i = 0; i < rst - 1; ++i) 
		fprintf(fo, "%d ", r[i]);
	fprintf(fo, "%d\n", r[rst-1]);
	return 0;
}

void dfs(int a, int b, int c)
{
	if (flag[a][b][c])
		return;
	flag[a][b][c] = 1;
	if (!a && !rf[c]) {
		rf[c] = 1;
		r[rst++] = c; 
	}
	if (a) {
		if (b + a <= B)
			dfs(0, a+b, c);
		else
			dfs(a-B+b ,B,c);
		if (a + c <= C)
			dfs(0, b, a+c);
		else
			dfs(a-C+c ,b,C);	
	}
	if (b) {
		if (b + a <= A)
			dfs(a+b, 0, c);
		else
			dfs(A ,b-A+a,c);
		if (b + c <= C)
			dfs(a, 0, b+c);
		else
			dfs(a, b-C+c, C);	
	}
	if (c) {
		if (c + a <= A)
			dfs(a+c, b, 0);
		else
			dfs(A, b, c-A+a);
		if (c + b <= B)
			dfs(a, c+b, 0);
		else
			dfs(a, B, c-B+b);	
	}
}