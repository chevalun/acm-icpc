#include <stdio.h>

short flag[1001001];
int sum(int);

int main()
{
	int i;
	for(i = 1; i <= 1000000; ++i)
		flag[i + sum(i)] = 1;
	for(i = 1; i <= 1000000; ++i)
		if(!flag[i])
			printf("%d\n", i);
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