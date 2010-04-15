#include <stdio.h>
#include <string.h>

int main()
{
	int N,i,j;
	char temp[100];
	scanf("%d\n", &N);
	for(i = 0; i < N; ++i) {
		gets(temp);
		for(j = strlen(temp) - 1; j >= 0; --j)
			putchar(temp[j]);
		putchar('\n');
	}
}