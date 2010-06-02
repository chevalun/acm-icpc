#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *, const void *);

int main()
{
	int N, i, m, n;
	char dna[101][51];
	
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d\n", &n, &m);
		for(i = 0; i < m; ++i)
			scanf("%s", dna[i]);
		qsort(dna, m, sizeof(char) * 51, cmp);	
		for(i = 0; i < m; ++i)
			printf("%s\n", dna[i]);
		if(N)
			putchar('\n');
	}
}

int cmp(const void *a, const void *b)
{
	char *sa = (char *) a, *sb = (char *) b;
	int ma = 0, mb = 0, i, j;
	for(i = strlen(sa); i >= 0; --i)
		for(j = i - 1; j >= 0; --j) {
			if (sa[j] > sa[i])
				++ma;
			if (sb[j] > sb[i])
				++mb;	
		}
		return ma - mb;	
}