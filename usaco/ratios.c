/*
ID: chevalu2
LANG: C
TASK: ratios
*/
#include <stdio.h>
#include <math.h>

int main()
{
	FILE *fi = fopen("ratios.in", "r");
	FILE *fo = fopen("ratios.out", "w");
	int i, j, k, flag = 0, w = 0, rst;
	double a, b, c, m[3][3], ta, tb, tc, eps = 0.000001, xa, xb, xc;
	fscanf(fi, "%lf %lf %lf", &a, &b, &c);
	for(i = 0; i < 3; ++i)
		fscanf(fi, "%lf %lf %lf", &m[i][0], &m[i][1], &m[i][2]);
	while(!flag) {
		++w;
		if(w > 301) {
			fprintf(fo, "NONE\n");
			return 0;
		}
		for(i = 0; (i <= w) && !flag; ++i)
			for(j = 0; j <= w-i; ++j) {
				k = w - i - j;
				ta = i*m[0][0] + j*m[1][0] + k*m[2][0];
				tb = i*m[0][1] + j*m[1][1] + k*m[2][1];
				tc = i*m[0][2] + j*m[1][2] + k*m[2][2];
				if ((tc < c) || (ta < a) || (tb < b))
					continue;
				if ((a < eps) && (b < eps) && (c < eps)) {
					flag = (ta < eps) && (tb < eps) && (tc < eps);
					rst = 0;
				}
				else if ((a < eps) && (b < eps) && (c > eps)) {
					flag = fabs((tc/c) - (int)(tc/c)) < eps;
					rst = tc/c;
				}
				else if ((a < eps) && (b > eps) && (c < eps)) {
					flag = fabs((tb/b) - (int)(tb/b)) < eps;
					rst = tb/b;
				}
				else if ((a > eps) && (b < eps) && (c < eps)) {
					flag = fabs((ta/a) - (int)(ta/a)) < eps;
					rst = ta/a;
				}
				else if ((a > eps) && (b > eps) && (c < eps)) {
					flag = (fabs((ta/a) - (tb/b)) < eps) && (tc < eps);
					rst = ta/a;
				}
				else if ((a > eps) && (b < eps) && (c > eps)) {
					flag = (fabs((ta/a) - (tc/c)) < eps) && (tb < eps);
					rst = tc/c;
				}
				else if ((a < eps) && (b > eps) && (c > eps)) {
					flag = (fabs((tc/c) - (tb/b)) < eps) && (ta < eps);
					rst = tb/b;
				}
				else if ((a > eps) && (b > eps) && (c > eps)) {
					flag = (fabs((tc/c) - (tb/b)) < eps) && (fabs((ta/a) - (tb/b)) < eps);
					rst = tb/b;
				}
				if (flag)
					break;
			}
	}	
	fprintf(fo, "%d %d %d %d\n", i-1, j, k, rst);
	return 0;	
}