#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}

int main()
{
	char a[1000], b[1000];
	int la, lb, i, j, rst, max, temp;
	while(scanf("%s %s", a, b) == 2) {
		la = strlen(a);
		lb = strlen(b);
		max = 0;
		for(i = 0; i < la; ++i) {
			rst = 0;
			for(j = 0; j < la; ++j)
				rst += (i + j < lb) && (a[j] == b[i+j]);
			if(max < rst)
				max = rst;
		}
		for(i = 0; i < lb; ++i) {
			rst = 0;
			for(j = 0; j < lb; ++j)
				rst += (i + j < la) && (b[j] == a[i+j]);
			if(max < rst)
				max = rst;
		}
		printf("appx(%s,%s) = ", a, b);
		if(!max)
			printf("0\n");
		else if(max * 2 == la + lb)
			printf("1\n");
		else {
			temp = gcd(2*max, la+lb);
			printf("%d/%d\n", 2*max/temp, (la+lb)/temp);
		}
	}
	return 0;
}