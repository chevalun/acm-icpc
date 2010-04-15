#include <stdio.h>

int count(int);

int main()
{
	while(scanf("%d", &N) != EOF) {
		if(!N)
			break;
		printf("%d\n", count(N));
	}
	return 0;
}

int count(int x)
{
	
}