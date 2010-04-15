#include <stdio.h>

int main()
{
	int N, a[100],sum,rst,x=0,i;
	while(scanf("%d",&N)!=EOF){
		++x;
		if(!N)
			break;
		sum=0;	
		for(i=0;i<N;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sum/=N;
		rst=0;
		for(i=0;i<N;++i)
			if(a[i]<sum)
				rst += sum-a[i];
		printf("Set #%d\nThe minimum number of moves is %d.\n",x,rst);
			putchar('\n');
	}
}