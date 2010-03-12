/*
ID: chevalu2
LANG: C
TASK: heritage
*/
#include <stdio.h>
#include <string.h>

char in[40], pre[40]; 
void solve(int ,int ,int);
FILE *fo;

int main()
{
	FILE *fi = fopen("heritage.in", "r");
	fo = fopen("heritage.out", "w");
	int len;
	fscanf(fi, "%s\n%s", in, pre);
	len = strlen(in) - 1;
	solve(0, 0, len);
	fputc('\n', fo);
	return 0;	
}

void solve(int i, int p, int l)
{
	int pos, len;
	if (l < 0)
		return;
	if (l == 0)
		fputc(in[i], fo);
	else {
		pos = strchr(in, pre[p]) - in;
		len = pos - i - 1;
		solve(i, p + 1, len);
		solve(i + len + 2, p + len + 2, l - len - 2);
		fputc(pre[p], fo);
	}
}