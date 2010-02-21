/*
ID: chevalu2
LANG: C
TASK: preface
*/
#include <stdio.h>
int count[7];

int main()
{
	FILE *fi = fopen("preface.in", "r");
	FILE *fo = fopen("preface.out", "w");
	int temp, x, N, i;
	char cc[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int p[] = {0, 1, 2, 3, 1};
	fscanf(fi, "%d", &N);
	for(i = 1; i <= N; ++i) {
		temp = i;
		x = 0;
		while(temp) {
			count[x] += p[temp % 5];
			count[x+1] += (((temp % 10) > 3) && ((temp % 10) < 9));
			count[x+2] += ((temp % 10) == 9);
			temp /= 10;
			x += 2;
		}
	}
	for(i = 0; i < 7; ++i)
		if(count[i])
			fprintf(fo, "%c %d\n", cc[i], count[i]);
	return 0;
}