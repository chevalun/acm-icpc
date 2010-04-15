#include <stdio.h>
#include <string.h>

int sum(int);
char buf[2000];

int main()
{
	int num, i;
	while (scanf("%s", buf) != EOF) {
		num = 0;
		for(i = 0; i < strlen(buf); ++i)
			num += buf[i] - '0';
		if (!num)
			break;
		while(num > 9)
			num = sum(num);
		printf("%d\n", num);
	}
	return 0;
}

int sum(int x)
{
	int rst = 0;
	while(x) {
		rst += x % 10;
		x /= 10;
	}
	return rst;
}