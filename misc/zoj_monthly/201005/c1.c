#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, len;
	char num[2000];
	scanf("%d\n", &N);
	for(i = 0; i < N; ++i) {
		scanf("%s", &num);
		len = strlen(num);
		--num[len - 1];
		++num[len - 2];
		if(num[len - 1] < 0) {
			flag = -1;
			num[len - 1] = 0;
		}
		if(num[len - 2] > 10) {
			flag = 1;
			num[len - 1] = 9;
		}
		for()
		printf("%s\n", num);
	}
}