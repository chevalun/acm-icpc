/*
ID: chevalu2
LANG: C
TASK: sort3
*/
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x < y) ? (x) : (y))

int num[1000], count[4], num[1000], pos[4][4];

int main()
{
	FILE *fi = fopen("sort3.in", "r");
	FILE *fo = fopen("sort3.out", "w");
	int i, N;
	fscanf(fi, "%d", &N);
	for (i = 0; i < N; ++i) {
		fscanf(fi, "%d", &num[i]);
		++count[num[i]];
	}
	for(i = 0; i < N; ++i) {
		if (i < count[1]) {
			++pos[1][num[i]];
		} else if (i < (count[1] + count[2])) {
			++pos[2][num[i]];
		} else {
			++pos[3][num[i]];
		}
	}
	fprintf(fo, "%d\n", MIN(pos[1][2], pos[2][1]) + MIN(pos[1][3], pos[3][1]) + MIN(pos[2][3], pos[3][2])
				  + (abs(pos[1][2] - pos[2][1]) + abs(pos[1][3] - pos[3][1]) + abs(pos[2][3] - pos[3][2]))/3*2);
	return 0;
}