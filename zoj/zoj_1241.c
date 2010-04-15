#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,i = 0;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		++i;
		if((a==0)&&(b==0)&&(c==0))
			break;
		printf("Triangle #%d\n", i);	
		if(a == -1) {
			if(c*c-b*b>0)
				printf("a = %.3lf\n\n", sqrt(c*c-b*b));
			else
				printf("Impossible.\n\n");
		}
		if(b == -1) {
			if(c*c-a*a>0)
				printf("b = %.3lf\n\n", sqrt(c*c-a*a));
			else
				printf("Impossible.\n\n");
		}
		if(c == -1)
			printf("c = %.3lf\n\n", sqrt(b*b+a*a));		
	}
	return 0;
}