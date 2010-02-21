/*
ID: chevalu2
LANG: C
TASK: runround
*/
#include <stdio.h>

int judge(int);

int main()
{
	FILE *fi = fopen("runround.in", "r");
	FILE *fo = fopen("runround.out", "w");
	int N, i;
	fscanf(fi, "%d", &N);
	for(i = N + 1;;) {
		if (judge(i))
			break;
		++i;
	}
	fprintf(fo, "%d\n", i);
	return 0;
}

int judge(int num)
{
	int n[10], len = 0, i, flag[10], try = 0, k, nn[10];
	while(num){
		n[len++] = num % 10;
		if (!n[len-1])
			return 0;
		for(i = 0; i < len -1; ++i) 
			if (n[i] == n[len-1])
				return 0;
		num /= 10;		
	}
	for(i = 0; i < len; ++i)
		nn[i] = n[len-i-1];
	for(i = 1; i < 10; ++i)
		flag[i] = 0;
	flag[nn[0]] = 1;
	k = 0;	
	while (try < len) {
		if ((try == len -1) && ((k+nn[k]) % len == 0))
			return 1;
		if(flag[nn[(k+nn[k]) % len]])
			return 0;
		flag[nn[(k+nn[k]) % len]] = 1;
		k = (k+nn[k]) % len;
		++try;
	}	
}