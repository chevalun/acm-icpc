/*
ID: chevalu2
LANG: C
TASK: packrec
*/
#include <stdio.h>
#define MAX(a, b) ((a > b) ? (a) : (b))

struct node
{
	int x,y;
};

void judge(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy);
int max(int a, int b, int c, int d);
void record(int, int);
void swap(int *, int *);
int r, min = 2<<20;
struct node rst[100]; 
int flag[4], t[4], arg[8];
struct node ss[4]; 
void per(int);

int main()
{
	FILE *fi = fopen("packrec.in", "r");
	FILE *fo = fopen("packrec.out", "w");
	int i;
	for (i = 0; i < 4; ++i)
		fscanf(fi, "%d %d", &ss[i].x, &ss[i].y);
	per(0);	
	fprintf(fo, "%d\n", rst[0].x * rst[0].y);
	for (i = 0; i < r; ++i)
		fprintf(fo, "%d %d\n", rst[i].x, rst[i].y);
	return 0;	
}

void per(int s)
{
	int i, j;
	if (s == 4) {
		for(i = 0; i < 4; ++i) {
			arg[i<<1] = ss[t[i]].x;
			arg[(i<<1)+1] = ss[t[i]].y;
		}
	//	printf("%d %d %d %d %d %d %d %d\n", ss[t[0]].x, ss[t[0]].y, ss[t[1]].x, ss[t[1]].y, ss[t[2]].x, ss[t[2]].y, ss[t[3]].x, ss[t[3]].y);
		for (i = 0; i < 16; ++i) {
			for (j = 0; j < 4; ++j)
				if (i & (1 << j))
					swap(&arg[j<<1], &arg[(j<<1)+1]);
			judge(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7]);
			for (j = 0; j < 4; ++j)
				if (i & (1 << j))
					swap(&arg[j<<1], &arg[(j<<1)+1]);		
		} 
		return;
	}
	for (i = 0; i < 4; ++i)
		if (!flag[i]) {
			t[s] = i;
			flag[i] = 1;
			per(s+1);
			flag[i] = 0;
		}
}

void judge(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
	int x, y;
//	printf("%d %d %d %d %d %d %d %d\n", ax, ay, bx, by, cx, cy, dx, dy);
	x = ax + bx + cx + dx;
	y = max(ay, by, cy, dy);
	record(x, y);
	x = max(ax+bx+cx, dx, 0, 0);
	y = dy + max(ay, by, cy, 0);
	record(x, y);
	x = max(ax+bx+cx, dx+cx, 0, 0);
	y = max(max(ay, by, 0, 0) + dy, cy, 0, 0);
	record(x, y);
	x = ax + dx + max(bx, cx, 0, 0);
	y = max(ay, by+cy, dy, 0);
	record(x, y);
	if (dy > cy) {
		if (cy+by <= dy) {
			x = max(ax, dx + bx, dx + cx, 0);
			y = dy + ay;
		}
		else {
			x = max(ax+bx, dx+ bx, dx+cx, 0);
			y = max(ay + dy, by + cy, 0, 0);
		}
	} else {
		if (ay+dy <= cy) {
			x = max(bx, dx + cx, ax + cx, 0);
			y = cy + by;
		}
		else {
			x = max(ax+bx, ax+ cx, dx+cx, 0);
			y = max(ay + dy, by + cy, 0, 0);
		}
	}
	record(x, y);
}

int max(int a, int b, int c, int d)
{
	return MAX(MAX(a,b), MAX(c, d));
}

void record(int x, int y)
{
	int i;
	if (x > y)
		swap(&x, &y);
	if (x*y > min)
		return;
	else if (x*y < min) {
		min = x*y;
		r = 1;
		rst[0].x = x;
		rst[0].y = y;
	} else {
		for (i = 0; i < r; ++i)
			if (rst[i].x == x)
				return;
		for(i = r-1; (rst[i].x > x) && (i >= 0); --i)
			rst[i+1] = rst[i];
		rst[i + 1].x = x;
		rst[i + 1].y = y;
		++r;	
	}
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}