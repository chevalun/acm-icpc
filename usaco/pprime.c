/*
ID: chevalu2
LANG: C
TASK: pprime
*/
#include <stdio.h>
#include <stdlib.h>

int is_prime(int);
int rst[100000];
int cmp(const void *a, const void *b);

int main()
{
	FILE *fi = fopen("pprime.in", "r");
	FILE *fo = fopen("pprime.out", "w");
	int a, b, d1, d2, d3, d, p, r;
	fscanf(fi, "%d %d", &a, &b);
	for (d1 = 1; d1 <= 11; d1++)
		if (is_prime(p = d1))
	    	if ((p >= a) && (p <= b))
				rst[r++] = p;
	for (d1 = 1; d1 <= 9; d1+=2) 
		for(d = 0; d <= 9; d++)
		    if (is_prime(p = 100*d1 + 10*d + d1))
	    		if ((p >= a) && (p <= b))
					rst[r++] = p;
	for (d1 = 1; d1 <= 9; d1+=2) 
	    for (d2 = 0; d2 <= 9; d2++) 
			for(d = 0; d <= 9; d++)
		    	if (is_prime(p =10000*d1 + 1000*d2 + 100*d + 10*d2 + d1))
		    		if ((p >= a) && (p <= b))
						rst[r++] = p;
	for (d1 = 1; d1 <= 9; d1+=2) 
	    for (d2 = 0; d2 <= 9; d2++) 
	        for (d3 = 0; d3 <= 9; d3++)
				for(d = 0; d <= 9; d++)
		    		if (is_prime(p = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d +100*d3 + 10*d2 + d1))
			    		if ((p >= a) && (p <= b))
							rst[r++] = p;
	qsort(rst, r, sizeof(int), cmp);
	for (d = 0; d < r; ++d) 
		fprintf(fo, "%d\n", rst[d]);
	return 0;	
}

int is_prime(int n) {
	int i;
	if (n == 2)
		return 1;
	for (i = 2; i*i <= n; ++i)
		if (n % i == 0)
			return 0;
	return 1;		
}

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}