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
	int N, i, S, c = 0, j, k, cc, temp, rst[20];
	while(scanf("%d", &temp) != EOF) {
		if(!temp)
			break;
		cc = 0;
		for (j = 2; j <= 16; ++j)
			if (check(temp, j))
				rst[cc++] = j;
		if(!cc) {
			printf("Number %d is not a palindrom\n", temp);
			continue;
		}
		printf("Number %d is palindrom in basis", temp);
		for(i = 0; i < cc; ++i)
			printf(" %d", rst[i]);
		putchar('\n');
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
	char tmp[5000];
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