/*
ID: chevalu2
LANG: C
TASK: msquare
*/
#include <stdio.h>
#include <stdlib.h>

FILE *fi, *fo;
struct node {
	int key, father;
	char trans;
};
int h[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
typedef struct node record;
record q[41000];
char flag[41000];
void output(int x);
int transform(int, int);

int main()
{
	int s = 0, t = 1, i, goal = 0, temp, p = 10000000;
	fi = fopen("msquare.in", "r");
	fo = fopen("msquare.out", "w");
	q[0] = (record) {12348765, -1, 0};
	for(i = 0; i < 8; ++i) {
		fscanf(fi, "%d", &temp);
		goal += temp*p;
		p /= 10;
	}
	goal = goal / 10000 * 10000 + goal % 10 * 1000 + goal / 10 % 10 * 100 + goal / 100 % 10 * 10 + goal / 1000 % 10;
	if(q[s].key == goal) {
		fprintf(fo, "%d\n\n", 0);
		exit(0);
	}
	while(s < t) {
		for(i = 0; i < 3; ++i) {
			q[t] = (record) {transform(q[s].key, i), s, i};
			if(q[s].key == 24517368)
				printf("%d %d\n", transform(q[s].key, i), i);
			if(q[t].key == goal)
				output(t);
			if(q[t].key == 12568743)
				printf("%d %d\n", transform(q[s].key, i), i);	
			temp = hash(q[t].key);
			if(temp == 35)
				printf("%d\n", q[t].key);
			if (!flag[temp]) {	
				flag[temp] = 1;
				++t;
			}
		}
		++s;	
	}
}

void output(int x)
{
	int y = 0, c = 0;
	while(q[x].father >= 0) {
		flag[y++] = q[x].trans + 'A';
		x = q[x].father;
	}
	fprintf(fo, "%d\n", y);
	for(x = y-1; x >= 0; --x){
		fputc(flag[x], fo);
		++c;
		if(c % 60 == 0)
			fputc('\n', fo);
	}
	if(c % 60)
		fputc('\n', fo);
	exit(0);
}

int transform(int x, int w)
{
	if(w == 0) {
		return (x % 10000)*10000 + x /10000;
	} else if (w == 1) {
		return (x / 10000) % 10 * 10000000 + (x / 100000)*10000 + x % 10 * 1000 + x / 10 % 1000;
	} else {
		return x / 10000000 * 10000000 + x / 100 % 10 * 1000000 + x / 1000000 % 10 * 100000 + x / 10000 % 10 * 10000 + x / 1000 % 10 * 1000 + x / 10 % 10 * 100 + x / 100000 % 10 * 10 + x % 10;
	}
}

int hash(int x)
{
	int i, j = 10, t, temp[10], ans = 0;
	for(i = 0; i < 8; ++i) {
		temp[7-i] = x % 10;
		x /= 10;
	}
	for(i = 0; i < 8; ++i) {
		t = 0;
		for(j = i+1; j < 8; ++j)
			if(temp[j] < temp[i])
				++t;
		ans += h[7-i] * t;		
	}
	return ans;
}