#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

int main()
{
	int N, i, num[2000], temp, j, k, tot = 0, x[2000], M, flag;
	int *pos;	
	while(scanf("%d", &N) != EOF) {
		set<int> pool;
		if(!N)
			break;
		for(i = 0; i < N; ++i) {
			scanf("%d", &temp);
			pool.insert(temp);
		}
		set<int>::iterator i, j, k, s;
		flag = 0;
		i = pool.end();
		--i;
		for(; i != pool.begin(); --i) {
			for(j = pool.begin(); j != pool.end(); ++j) {
				if (j == i)
					continue;
				for(k = pool.begin(); k != pool.end(); ++k) {
					if(k == j || k == i)
						continue;
					temp = *i - *j - *k;
					s = pool.find(temp);
					if(s != pool.end() && s != i && s != j && s!= k) {
						printf("%d\n", *i);
						goto OUT;
					}
				}
			}
		}
		printf("no solution\n");
		OUT:;
	}
}