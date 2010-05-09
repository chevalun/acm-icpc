#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

double det(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	return a11*a22*a33 + a12*a23+a31 + a13*a21*a32 - a13*a22*a31 - a12*a21*a33 - a11*a23*a32;
}

int main()
{
	double x1, x2, x3, y1, y2, y3, d1, d2, d3, p, s;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
		d1 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		d2 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
		d3 = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
		p = (d1+d2+d3)/2;
		s = sqrt(p*(p-d1)*(p-d2)*(p-d3));
		printf("%.2lf\n", (d1*d2*d3/s/4)*2*PI);
	}
}