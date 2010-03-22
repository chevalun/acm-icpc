/*
ID: chevalu2
LANG: C
TASK: fence4
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 0.000001

struct node{
	double x,y;
};
typedef struct node node;
node fence[201][2];
int rst[201];
double x, y, xx[201], yy[201];
inline int fcmp(double);
inline double det(double, double, double, double);
inline double cross(node a, node b, node c);
inline iscross(node, node, node, node);

int main()
{
	FILE *fi = fopen("fence4.in", "r");
	FILE *fo = fopen("fence4.out", "w");
	int i, N, j, flag, k, f, c = 0;
	node t, p, tt[2];
	double random;
	srand(7777);
	fscanf(fi, "%d", &N);
	fscanf(fi, "%lf %lf", &p.x, &p.y);
	for(i = 0; i < N; ++i)
		fscanf(fi, "%lf %lf", &xx[i], &yy[i]);
	for(i = 0; i < N-1; ++i) {
		fence[i][0] = (node) {xx[i], yy[i]};
		fence[i][1] = (node) {xx[i+1], yy[i+1]};
	}
	fence[N-1][1] = fence[N-2][1];
	fence[N-1][0] = fence[0][0];
	tt[0] = fence[N-1][0]; tt[1] = fence[N-1][1]; fence[N-1][0] = fence[N-2][0]; fence[N-1][1] = fence[N-2][1]; fence[N-2][0] = tt[0]; fence[N-2][1] = tt[1];
	for(i = 0; i < N; ++i)
		for(j = i+1; j < N; ++j)
			if (iscross(fence[i][0], fence[i][1], fence[j][0], fence[j][1])) {
				fprintf(stdout, "NOFENCE\n");
				return 0;
			}
	for(i = 0; i < N; ++i) {
		f = 0;
		for(k = 0; k < 500; ++k) {
			flag = 1;
			random = ((double)rand())/RAND_MAX;
			t = (node) {fence[i][0].x - (fence[i][0].x - fence[i][1].x)* random, fence[i][0].y - (fence[i][0].y - fence[i][1].y)* random};
			for(j = 0; j < N; ++j) {
				if (j == i)
					continue;
				if(iscross(t, p, fence[j][0], fence[j][1])) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				f = 1;
				break;
			}
		}
		if (f)
			rst[c++] = i;
	}
	fprintf(fo, "%d\n", c);
	for(i = 0; i < c; ++i)
		fprintf(fo, "%.0lf %.0lf %.0lf %.0lf\n", fence[rst[i]][0].x, fence[rst[i]][0].y, fence[rst[i]][1].x, fence[rst[i]][1].y);
	return 0;	
}

inline int fcmp(double p)
{
	if(fabs(p) < EPS)
		return 0;
	return (p > 0) ? 1 : -1;
}

inline double det(double a, double b, double c, double d)
{
	return a*d - b*c;
}

inline double cross(node a, node b, node c)
{
	return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

inline iscross(node a, node b, node c, node d)
{
	return (fcmp(cross(a,c,d))^fcmp(cross(b,c,d))) == -2 && (fcmp(cross(c,a,b))^fcmp(cross(d,a,b))) == -2;
}

