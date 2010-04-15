#include <stdio.h>
#include <stdlib.h>

struct stick
{
	int w, l;
};
typedef struct stick stick;
stick s[5001];
int flag[5001];

int cmp(const void *, const void *);

int main()
{
	int M, N, i, j, nw, nl, tot, p;
	scanf("%d", &M);
	for(i = 0; i < M; ++i) {
		scanf("%d", &N);
		for(j = 0; j < N; ++j)
			scanf("%d %d", &s[j].l, &s[j].w);
		qsort(s, N, sizeof(stick), cmp);
		for(j = 0; j < N; ++j)
			flag[j] = 0;
		tot = p = 0;	
		while(tot < N) {
			for(j = 0; (j < N) && flag[j]; ++j)
				;
			nw = s[j].w; nl = s[j].l;
			flag[j] = 1;
			++tot;
			for(j += 1; j < N; ++j) 
				if ((!flag[j]) && (nw <= s[j].w) && (nl <= s[j].l)) {
					nw = s[j].w;
					nl = s[j].l;
					flag[j] = 1;
					++tot;
				}
			++p;
		}
		printf("%d\n", p);	
	}
}

int cmp(const void *a, const void *b)
{
	if (((stick *) a)->w != ((stick *) b)->w)
		return ((stick *) a)->w - ((stick *) b)->w;
	return ((stick *) a)->l - ((stick *) b)->l;	
}