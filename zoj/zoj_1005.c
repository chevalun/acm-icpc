#include <stdio.h>
#include <string.h>

struct node{
	int a, b, key, f;
};
typedef struct node node;
char flag[1011][1011];
node q[300000];
char message[][20] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};
void output(int);

int main()
{
	int ca, cb, N, s, t;
	while(scanf("%d %d %d", &ca, &cb, &N) == 3) {
		memset(flag, 0, sizeof(char) * 1011 * 1011);
		memset(q, 0, sizeof(q));
		flag[0][0] = 1;
		q[0] = (node){0, 0, 0, 0};
		s = 0;
		t = 1;
		while(s < t){
			if((q[s].a < ca) && !flag[ca][q[s].b]) {
				q[t].b = q[s].b;
				q[t].a = ca;
				q[t].key = 0;
				q[t].f = s;
				flag[q[t].a][q[t].b] = 1;
				++t;
			}
			if((q[s].b < cb) && !flag[q[s].a][cb]) {
				q[t].b = cb;
				q[t].a = q[s].a;
				flag[q[t].a][q[t].b] = 1;
				q[t].key = 1;
				q[t].f = s;
				if(cb == N) 
					break;
				++t;
			}
			if((q[s].a > 0) && !flag[0][q[s].b]) {
				q[t].b = q[s].b;
				q[t].a = 0;
				flag[q[t].a][q[t].b] = 1;
				q[t].key = 2;
				q[t].f = s;
				++t;
			}
			if((q[s].b > 0) && !flag[q[s].a][0]) {
				q[t].b = 0;
				q[t].a = q[s].a;
				q[t].f = s;
				flag[q[t].a][q[t].b] = 1;
				q[t].key = 3;
				++t;
			}
			if(q[s].a > 0) {
				if(q[s].b + q[s].a <= cb) {
					q[t].b = q[s].b + q[s].a;
					q[t].a = 0;
				} else {
					q[t].b = cb;
					q[t].a = q[s].a - (cb - q[s].b);
				}
				q[t].f = s;
				q[t].key = 4;
				if(q[t].b == N)
					break;
				if(!flag[q[t].a][q[t].b]) {
					flag[q[t].a][q[t].b] = 1;
					++t;
				}
			}
			if(q[s].b > 0) {
				if(q[s].b + q[s].a <= ca) {
					q[t].a = q[s].b + q[s].a;
					q[t].b = 0;
				} else {
					q[t].a = ca;
					q[t].b = q[s].b - (ca - q[s].a);
				}
				q[t].f = s;
				q[t].key = 5;
				if(q[t].b == N)
					break;
				if(!flag[q[t].a][q[t].b]) {
					flag[q[t].a][q[t].b] = 1;
					++t;
				}
			}
			++s;
		}
		output(t);
		printf("success\n");
	}
}

void output(int x)
{
	if(q[x].f) 
		output(q[x].f);
	printf("%s\n", message[q[x].key]);
}