#include <stdio.h>

int main()
{
	int N, a, b;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &a, &b);
		if ((a + b) % 2 == 0) {
			if(a == b) {
				if (a % 2 == 0)
					printf("%d\n", a * 2);
				else
					printf("%d\n", a * 2 - 1);
			} else if(a == b + 2) {
				if(a % 2 == 0)
					printf("%d\n", a * 2 - 2);
				else
					printf("%d\n", a * 2 - 3);
			} else {
				printf("No Number\n");
			}
		} else {
			printf("No Number\n");
		}
	}
}