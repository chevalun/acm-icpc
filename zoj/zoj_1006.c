/*
Level C.
Math.
Jan 30, 2010.

(P + X) mod Y = Q, then
P = (Q - X) mod Y
*/
#include <stdio.h>
#include <string.h>

int c_to_n(char);
char n_to_c(int);

int main()
{
	int key, i, len, temp;
	char c;
	char str[80];
	int rst[80];
	for (;;) {
		scanf("%d", &key);
		if (!key)
			break;
		scanf("%s", str);
		len = strlen(str);
		for (i = 0; i < len; ++i) {
			temp = (c_to_n(str[i]) + i) % 28;
			rst[key*i % len] = temp;
		}
		for (i = 0; i < len; ++i)
			putchar(n_to_c(rst[i]));
		putchar('\n');
	}
	return 0;
}

char n_to_c(int n)
{
	if (n == 0)
		return '_';
	if (n == 27)
		return '.';
	return n+'a'-1;
}

int c_to_n(char c)
{
	if (c == '_')
		return 0;
	if (c == '.')
		return 27;
	return c-'a'+1;
}