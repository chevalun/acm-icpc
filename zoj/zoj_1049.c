#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main()
{
	int i, N, k;
	double x, y, rs, d;
	scanf("%d\n", &N);
	
	for(i = 0; i < N; ++i){
		scanf("%lf %lf\n", &x, &y);
		d = x*x + y*y;
		rs = 0;
		k = 0;
		while (rs < d) {
			++k;
			rs = 50.0*k/PI*2;
		}
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, k);
	}
	printf("END OF OUTPUT.\n");
}