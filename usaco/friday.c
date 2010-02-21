/*
ID: chevalu2
LANG: C
TASK: friday
*/
#include <stdio.h>

int c[7];
 
int main()
{
	FILE *fi = fopen("friday.in", "r");
	FILE *fo = fopen("friday.out", "w");
	int N, i, j, r, x = 3;

	fscanf(fi, "%d\n", &N);
	
	for (i = 1900; i < 1900+N; ++i) {
		r = (!(i % 4) && (i % 100)) || !(i % 400);
		for (j = 1; j <= 12; ++j) {
			switch(j) {
				case 1: case 2: case 4: case 6: case 8: case 9: case 11:
					x = (x + 31) % 7;
					break;
				case 3:
					if (r)
						x = (x + 29) % 7;
					else
						x = (x + 28) % 7;
					break;
				default:
					x = (x + 30) % 7;
					break;
			}
			++c[x];
		}
	}
	fprintf(fo, "%d %d %d %d %d %d %d\n", c[6], c[0], c[1], c[2], c[3], c[4], c[5]);
	return 0;	
}