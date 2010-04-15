#include <stdio.h>

int main()
{
	int a, b, temp;
	while(scanf("%d %d", &a, &b) == 2) {
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		
	}
	return 0;
}