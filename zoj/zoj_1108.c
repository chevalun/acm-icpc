#include <stdio.h>

struct mouse {
	int speed, weight, index;
};
typedef struct mouse mouse;
int cmp(const void *, const void *);
int dp[1500], trace[1500];
mouse m[1500];
void output(int);

int main()
{
	int n = 0, i, j, max = 0, pos;
	while(scanf("%d %d", &m[n].weight, &m[n].speed) == 2) {
		m[n].index = n + 1;
		++n;
	}
	for(i = 0; i < n; ++i)
		trace[i] = -1;
	qsort(m, n, sizeof(mouse), cmp);
	for(i = 0; i < n; ++i)
		for(j = 0; j < i; ++j)
			if ((m[j].speed > m[i].speed) && (m[j].weight < m[i].weight) &&(dp[j] + 1 > dp[i])) {
				dp[i] = dp[j] + 1;
				trace[i] = j;
			}
	for(i = 0; i < n; ++i)
		if(dp[i] > max) {
			max = dp[i];
			pos = i;
		}
	printf("%d\n", max + 1);
	output(pos);	
	return 0;		
}

int cmp(const void *x, const void *y)
{
	mouse *a = (mouse *) x, *b = (mouse *) y;
	if ((*a).weight != (*b).weight)
		return (*a).weight - (*b).weight;
	return (*b).speed - (*a).speed;
}

void output(int x)
{
	if(trace[x] > 0)
		output(trace[x]);
	printf("%d\n", m[x].index);
}