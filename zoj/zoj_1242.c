#include <stdio.h>
#include <math.h>

int main()
{
	int w, d, t = 0;
	double x;
	while(scanf("%d %d", &w, &d) && w && d) {
		x = log2(810.0 / d * w) * 5730.0;
		if(x >= 10000)
			x = round(x/1000) * 1000;
		else
			x = round(x/100) * 100;
		printf("Sample #%d\nThe approximate age is %.0lf years.\n\n", ++t, x);	
	}
}