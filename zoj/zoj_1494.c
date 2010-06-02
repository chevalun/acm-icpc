#include <stdio.h>

int main()
{
	int n, u, d, x, s;
	while(scanf("%d %d %d", &n, &u, &d) && n) {
		x = s = 0;
		while(x < n) {
			++s;
			if(s & 1)
				x += u;
			else
				x -= d;
		}
		printf("%d\n", s);
	}
	return 0;
}