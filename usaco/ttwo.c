/*
ID: chevalu2
LANG: C
TASK: ttwo
*/
#include <stdio.h>

int map[10][10];
int flag[10][10][4][10][10][4];
int di[4][2] = {{0, -1},{1, 0},{0 , 1},{-1, 0}};
int fit(int, int, int);

int main()
{
	FILE *fi = fopen("ttwo.in", "r");
	FILE *fo = fopen("ttwo.out", "w");
	int i, j, fx, fy, cx, cy, cd, fd, rst = 0;
	char temp[20];
	for(i = 0; i < 10; ++i) {
		fscanf(fi, "%s", temp);
		for(j = 0; j < 10; ++j) {
			if(temp[j] == '*')
				map[j][i] = 0;
			else map[j][i] = 1;
			if (temp[j] == 'F') {
				fx = j;
				fy = i;
			}
			else if (temp[j] == 'C') {
					cx = j;
					cy = i;
			}
		}
	}
	cd = fd = 0;
	while (!flag[fx][fy][fd][cx][cy][cd]) {
		flag[fx][fy][fd][cx][cy][cd] = 1;
		++rst;
		if(fit(fx, fy, fd)) {
			fx += di[fd][0];
			fy += di[fd][1];
		} else fd = (fd + 1) % 4;
		if(fit(cx, cy, cd)) {
			cx += di[cd][0];
			cy += di[cd][1];
		} else cd = (cd + 1) % 4;
		if ((cx == fx) && (cy == fy)) {
			fprintf(fo, "%d\n", rst);
			return 0;
		}
	}
	fprintf(fo, "%d\n", 0);
	return 0;	
}

int fit(int x, int y, int d)
{
	return (x + di[d][0] >= 0) && (x + di[d][0] < 10) && (y + di[d][1] >= 0) && (y + di[d][1] < 10) && map[x + di[d][0]][y + di[d][1]];
}