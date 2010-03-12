/*
ID: chevalu2
LANG: C
TASK: fence4
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 0.00000001

struct node{
	double x,y;
};
typedef struct node node;
node fence[201][2];
int rst[201], flag[201];
double x, y, xx[201], yy[201];
inline int fcmp(double);
inline double det(double, double, double, double);
inline double cross(node a, node b, node c);
inline int iscross(node, node, node, node);
inline node cp(node, node, node, node);
inline double dis(node a, node b);

int main()
{
	FILE *fi = fopen("fence4.in", "r");
	FILE *fo = fopen("fence4.out", "w");
	int i, N, j, k, f, c = 0, temp;
	node t, p, tt[2];
	double random, q, tx, ty, min;
	srand(777);
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
		tx = fence[i][0].x + (fence[i][0].x - fence[i][1].x) * 0.000001;	
		ty = fence[i][0].y + (fence[i][0].y - fence[i][1].y) * 0.000001;
		tx = tx + (tx - p.x) * 100000;
		ty = ty + (ty - p.y) * 100000;
		t = (node) {tx, ty};
		min = 1e10;
		for(j = 0; j < N; ++j)
			if ((fence[i][0].y == ty) && (fabs(fence[i][0].x - p.x) < min))
				min = fabs(fence[i][0].x - p.x);
		temp = -1;
		for(j = 0; j < N; ++j)
			if(iscross(t, p, fence[j][0], fence[j][1]) && dis(cp(t, p, fence[j][0], fence[j][1]), p) < min) {
				min = dis(cp(t, p, fence[j][0], fence[j][1]), p);
				temp = j;
			}
		if (temp < 0)
			continue;
		flag[temp] = 1;
		tx = fence[i][1].x - (fence[i][1].x - fence[i][0].x) * 0.000001;	
		ty = fence[i][1].y - (fence[i][1].y - fence[i][0].y) * 0.000001;
		tx = tx + (tx - p.x) * 100000;
		ty = ty + (ty - p.y) * 100000;
		t = (node) {tx, ty};
		min = 1e10;
		temp = -1;
		for(j = 0; j < N; ++j)
			if(iscross(t, p, fence[j][0], fence[j][1]) && dis(cp(t, p, fence[j][0], fence[j][1]), p) < min) {
				min = dis(cp(t, p, fence[j][0], fence[j][1]), p);
				temp = j;
			}
		if (temp < 0)
			continue;
		flag[temp] = 1;
	}
	for(i = 0; i < N; ++i)
		if(flag[i])
			++c;
	fprintf(fo, "%d\n", c);
	for(i = 0; i < N; ++i)
		if(flag[i])
			fprintf(fo, "%.0lf %.0lf %.0lf %.0lf\n", fence[i][0].x, fence[i][0].y, fence[i][1].x, fence[i][1].y);
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

inline int iscross(node a, node b, node c, node d)
{
	return (fcmp(cross(a,c,d))^fcmp(cross(b,c,d))) == -2 && (fcmp(cross(c,a,b))^fcmp(cross(d,a,b))) == -2;
}

inline node cp(node a, node b, node c, node d)
{
	double s1 = cross(a,b,c), s2 = cross(a,b,d);
	return (node) {(c.x*s2-d.x*s1)/(s2-s1), (c.y*s2-d.y*s1)/(s2-s1)};
}

inline double dis(node a, node b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}