/*
ID: chevalu2
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <string.h>

char buf[50];
int check(int, int);
char* base(int, int, char *);

int main()
{
	FILE *fi = fopen("palsquare.in", "r");
	FILE *fo = fopen("palsquare.out", "w");
	int B, i;
	fscanf(stdin, "%d\n", &B);
	for (i = 1; i <= 300; ++i) {
		if (check(i*i, B)) {
			fprintf(stdout, "%s %s\n", base(i, B, buf), base(i*i, B, buf));
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
		tmp[len] = ((num % B) <= 9) ? ((num % B) + '0') : ((num % B) - 10 + 'A');
		++len;
		num /= B; 
	}
	for (i = 0; i < len; ++i) {
		buf[i] = tmp[len-i-1];
	}
	buf[len] = '\0';
	return buf;
}