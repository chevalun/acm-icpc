/*
ID: chevalu2
LANG: C
TASK: agrinet
*/
#include <stdio.h>

int f[10];
int union(int x, int y);
int find(int x);

int main()
{
	FILE *fi = fopen("agrinet.in", "r");
	FILE *fo = fopen("agrinet.out", "w");
	return 0;	
}

int find(int x)
{
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

void union(int x, int y)
{
	f[find(x)] = find(y);
}