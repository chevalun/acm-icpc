/*
ID: chevalu2
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <string.h>

char buf[5000];
int check(int, int);
char* base(int, int, char *);

int main()
{
	FILE *fi = fopen("dualpal.in", "r");
	FILE *fo = fopen("dualpal.out", "w");
	int N, i, S, c = 0, j, k, cc;
	fscanf(fi, "%d %d\n", &N, &S);
	for (i = S+1; c < N; ++i) {
		cc = 0;
		for (j = 2; j <= 10; ++j) {
			if (check(i, j))
				++cc;
			if (cc == 2) {
				fprintf(fo, "%d\n", i);
				++c;
				break;
			}
		}
	}
	return 0;	
}

int check(int num, int B)
{
	int i;
	char *str = base(num, B, buf);
	int n = strlen(str);
	for(i = 0; i < (n/2); ++i) {
		if (str[i] != str[n-i-1])
			return 0;
	}
	return 1;
}

char* base(int num, int B, char *buf)
{
	char tmp[50];
	int len = 0, i;
	while (num) {
		tmp[len] = num % B + '0';
		++len;
		num /= B; 
	}
	for (i = 0; i < len; ++i) {
		buf[i] = tmp[len-i-1];
	}
	buf[len] = '\0';
	return buf;
}