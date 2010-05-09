#include <stdio.h>

int main()
{
	int a, b, N = 0;
	while(scanf("%d %d", &a, &b) != EOF) {
		if (a == 0)
			break;
		printf("Hole #%d\n", ++N);	
		if (b == 1)
			printf("Hole-in-one.\n");
		else if (a == b)
			printf("Par.\n");
		else if (a == b + 1)
			printf("Birdie.\n");
		else if (a == b + 2)
			printf("Eagle.\n");
		else if (a == b+3)
			printf("Double Eagle.\n");
		else if (a == b-1 )
			printf("Bogey.\n");
		else
			printf("Double Bogey.\n");
		putchar('\n');	
	}
	return 0;
}