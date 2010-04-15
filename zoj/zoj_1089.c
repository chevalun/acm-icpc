#include <stdio.h>

int num[20], rst[20], N;
void try(int , int);

int main()
{
	int i, flag = 0;
	while (scanf("%d", &N) != EOF) {
		if (!N)
			break;
		if(flag)
			putchar('\n');	
		++flag;
		for(i = 0; i < N; ++i)
			scanf("%d", &num[i]);
		try(0, 0);
	}
	return 0;
}

void try(int x, int p)
{
	int i;
	if (x == 6) {
		for(i = 0; i < 5; ++i)
			printf("%d ", rst[i]);
		printf("%d\n", rst[5]);
		return;
	}
	for(i = p; i < N; ++i) {
		rst[x] = num[i];
		try(x+1, i+1);
	}
}
