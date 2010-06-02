#include <stdio.h>
#include <string.h>

int main()
{
	int N, b, sum, tot, i, t;
	char x[1000];
	scanf("%d", &N);
	while(N--) {
		while(scanf("%d", &b) && b) {
			scanf("%s", x);
			tot = sum = 0;
			t = 1;
			for(i = strlen(x) - 1; i >= 0; --i) {
				tot += (x[i] - '0') * t;
				t *= b;
				sum += x[i]- '0';
			}
			if(tot % sum == 0)
				printf("yes\n");
		 	else
				printf("no\n");
		}
		if(N)
			putchar('\n');
	}
	return 0;
}