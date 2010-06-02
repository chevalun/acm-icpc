#include <stdio.h>

int judge(int x);
int sum(int x);

int main()
{
	int x;
	while(scanf("%d", &x) && x) {
		while(!judge(++x))
			;
	}
	return 0;
}

int judge(int x)
{
	int p = 2, s = 0, t = x, ss = sum(x);
	while(x > 1) {
		if(s > ss)
			break;
		if(p * p > x) {
			if(s)
				s += sum(x);
			break;
		}
		while(x % p == 0) {
			s += sum(p);
			x /= p;
		}
		++p;	
	}
	if(ss == s) {
		printf("%d\n", t);
		return 1;
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