#include <stdio.h>

int main()
{
	int s, d, flag[70], rst, i;
	while(scanf("%d %d", &s, &d) && s && d) {
		for(i = 0; i < 60; ++i)
			flag[i] = 0;
		rst = 0;	
		while(s) {
			if(flag[s])
				break;
			flag[s] = 1;
			s = (s + (s * d)) % 60;
			++rst;
		}
		if(s)
			printf("Impossible\n");
		else
			printf("%d\n", rst);
	}
	return 0;
}