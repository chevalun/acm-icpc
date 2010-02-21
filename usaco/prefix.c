/*
ID: chevalu2
LANG: C
TASK: prefix
*/
#include <stdio.h>
#include <string.h>

char list[200][20], s[200010];
int dp[200010];

int main()
{
	FILE *fi = fopen("prefix.in", "r");
	FILE *fo = fopen("prefix.out", "w");
	int temp[20], c, L = 1, i, j, k, len, flag, r = 0;
	int N;
	while (fscanf(fi, "%s", list[N++]), list[N-1][0] != '.')
		;
	--N;
	while ((c = getc(fi)) != EOF) {
		if (c != '\n') 
			s[L++] = c;
	}
	dp[0] = 1;
	for(i = 1; i <= L; ++i)
		for (j = 0; j < N; ++j) {
			len = strlen(list[j]);
			if ((len <= i) && (dp[i-len])) {
				flag = 1;
				for(k = 0; k < len; ++k)
					if(list[j][k] != s[i-len+k+1]) {
						flag = 0;
						break;
					}
				dp[i] = flag;
				if(flag) {
					if (i > r)
						r = i;
					break;
				}
			}
		}
	fprintf(fo, "%d\n", r);	
	return 0;	
}