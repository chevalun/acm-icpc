#include <stdio.h>
#include <string.h>

char a[500], b[500];

int main()
{
	char temp;
	int la, i, c, lb, na[200], nb[200], l;
	while(scanf("%s", a) != EOF) {
		scanf("%s", b);
		la = strlen(a);
		lb = strlen(b);
		for(i = 0; i < 150; ++i)
			na[i] = nb[i] = 0;
		for(i = 0; i < la; ++i)
			if(isdigit(a[la-i-1]))
				na[i] = a[la-i-1] - '0';
			else
				na[i] = a[la-i-1] - 'a' + 10;
		for(i = 0; i < lb; ++i)
			if(isdigit(b[lb-i-1]))
				nb[i] = b[lb-i-1] - '0';
			else
				nb[i] = b[lb-i-1] - 'a' + 10;
		l = (la > lb) ? la : lb;				
		c = 0;
		for(i = 0; i < l; ++i) {
			na[i] += nb[i] + c;
			c = na[i] / 20;
			na[i] %= 20;
		}
		if(c)
			putchar('1');
		for(i = l-1; i >= 0; --i) {
			if(na[i] < 10)
				putchar(na[i] + '0');
			else
				putchar(na[i] + 'a' - 10);
		}
		putchar('\n');	
	}
	return 0;
}