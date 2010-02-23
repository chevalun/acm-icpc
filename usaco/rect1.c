/*
ID: chevalu2
LANG: C
TASK: rect1
*/
#include <stdio.h>

int N, y1[1010], y2[1010], x1[1010], x2[1010], cc[2501], c[1010];
void cal(int xa, int ya, int xb, int yb, int color, int z);

int main()
{
	FILE *fi = fopen("rect1.in", "r");
	FILE *fo = fopen("rect1.out", "w");
	int i, j, A, B;
	fscanf(fi, "%d %d %d", &A, &B, &N);
	x1[0] = 0; y1[0] = 0; x2[0] = A; y2[0] = B; c[0] = 1;
	for(i = 1; i <= N; ++i)
		fscanf(fi, "%d %d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i], &c[i]);
	for(i = N; i >= 0; --i)
		cal(x1[i], y1[i], x2[i], y2[i], c[i], i+1);
	for(i = 0; i <= 2500; ++i)
		if(cc[i])
			fprintf(fo, "%d %d\n", i, cc[i]);
	return 0;	
}

void cal(int xa, int ya, int xb, int yb, int color, int z)
{
	while ((z <= N) && ((xa >= x2[z]) || (ya >= y2[z]) || (xb <= x1[z]) || (yb <= y1[z])))
		++z;
	if(z > N) {
		cc[color] += (xb-xa) * (yb - ya);
		return;
	}
	if(xb > x2[z]) {
		cal(x2[z], ya, xb, yb, color, z+1);
		xb = x2[z];
	}
	if(yb > y2[z]) {
		cal(xa, y2[z], xb, yb, color, z+1);
		yb = y2[z];
	}
	if(xa < x1[z]) {
		cal(xa, ya, x1[z], yb, color, z+1);
		xa = x1[z];
	}
	if(ya < y1[z])
		cal(xa, ya, xb, y1[z], color, z+1);	
}