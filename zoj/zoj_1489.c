#include <stdio.h>

int main()
{
	int x, t, rst;
	while(scanf("%d", &x) != EOF) {
		if(x % 2 == 0 || x == 1)
			printf("2^? mod %d = 1\n", x);
		else {
			rst = 1;
			t = 2;
			while(t != 1) {
				++rst;
				t <<= 1;
				t %= x;
			}
			printf("2^%d mod %d = 1\n", rst, x);
		}
	}
	return 0;
}