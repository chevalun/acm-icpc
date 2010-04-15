#include <stdio.h>

int main()
{
	int N, i, j;
	char temp[100];
	scanf("%d\n", &N);
	for(j = 1; j <=N; ++j) {
		printf("String #%d\n", j);
		scanf("%s", temp);
		for(i = 0; temp[i]; ++i) {
			++temp[i];
			if(temp[i] > 'Z')
				temp[i] = 'A';
		}
		printf("%s\n", temp);
		putchar('\n');
	}
	return 0;
}