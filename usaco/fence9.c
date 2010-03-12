/*
ID: chevalu2
LANG: C
TASK: fence9
*/
#include <stdio.h>
#include <math.h>
#define EPS 0.000001

struct node{
	double x,y;
};
typedef struct node node;
inline int fcmp(double);
inline double det(double, double, double, double);
inline double cross(node a, node b, node c);
inline node cp(node, node, node, node);

int main()
{
	FILE *fi = fopen("fence9.in", "r");
	FILE *fo = fopen("fence9.out", "w");
	int n, m, p, i, sum = 0;
	node t1, t2, a, b, c, r1, r2;
	fscanf(fi, "%d %d %d", &n, &m, &p);
	a = (node) {0, 0}; b = (node) {p, 0}; c = (node) {n, m};
	for(i = 1; i < m; ++i) {
		t1 = (node) {-50000 ,i};
		t2 = (node) {50000 ,i};
		r1 = cp(t1, t2, a, c);
		r2 = cp(t1, t2, b, c);
		sum += - ceil(r1.x + 0.000001) + trunc(r2.x - 0.000001) + 1;
	}
	fprintf(fo, "%d\n", sum);
	return 0;	
}

inline node cp(node a, node b, node c, node d)
{
	double s1 = cross(a,b,c), s2 = cross(a,b,d);
	return (node) {(c.x*s2-d.x*s1)/(s2-s1), (c.y*s2-d.y*s1)/(s2-s1)};
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