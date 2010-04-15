#include <stdio.h>

int main()
{
	int i;
	double len = 0, rec[500];
	for(i = 1; i <= 500; ++i) {
		len += 1.0/(i+1);
		rec[i] = len;
	}
	while(scanf("%lf", &len) != EOF) {
		if (len == 0.0)
			break;
		i = 1;
		while(rec[i] < len)
			++i;
		printf("%d card(s)\n", i);
	}
	return 0;
}