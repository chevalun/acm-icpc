/*
ID: chevalu2
LANG: C
TASK: beads
*/
#include <stdio.h>

char str[400];
int temp[400];
char t[] = "rb"; 
int main()
{
	FILE *fi = fopen("beads.in", "r");
	FILE *fo = fopen("beads.out", "w");
	int i, N, j, max = 0, c, q;
	
	fscanf(fi, "%d\n", &N);
	fscanf(fi, "%s", str);
	for (i = 0; i < N; ++i) {
		for (q = 0; q < 4; ++q) {
			c = 0;
			for (j = 0; j < N; ++j) 
				temp[j] = (str[(i+j) % N] == t[q&1]);
			for (j = 0; ((temp[j] == temp[0]) && (j < N)); ++j) 
				++c;
			for (j = 0; j < N; ++j) 
				temp[j] = (str[(i-1-j+N) % N] == t[q>>1]);	
			for (j = 0; ((temp[j] == temp[0]) && (j < N)); ++j) 
				++c;	
			if (c > max)
				max = c;
		}				
	}
	if (max > N)
		max = N;
	fprintf(fo, "%d\n", max);
	return 0;	
}