#include <stdio.h>

int main()
{
	int i, a, b, c, p[16][3], r, dis;
	for(i = 0; i < 16; ++i)
		scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
	while(scanf("%d %d %d", &a, &b, &c) != EOF) {
		if (a < 0)
			break;
		dis = 1<<25;	
		for(i = 0; i < 16; ++i)
			if (((a-p[i][0])*(a-p[i][0]) + (b-p[i][1])*(b-p[i][1]) + (c-p[i][2])*(c-p[i][2])) < dis) {
				dis = ((a-p[i][0])*(a-p[i][0]) + (b-p[i][1])*(b-p[i][1]) + (c-p[i][2])*(c-p[i][2]));
				r = i;
			}
			printf("(%d,%d,%d) maps to (%d,%d,%d)\n", a, b, c, p[r][0], p[r][1], p[r][2]);	
	}
}