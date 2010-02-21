/*
ID: chevalu2
LANG: C
TASK: lamps
*/
#include <stdio.h>

void check(int, int, int, int);
int lamp[110], ON[100], OFF[100];
int n1, n2, N, flag;
FILE *fo;

int main()
{
	FILE *fi = fopen("lamps.in", "r");
	fo = fopen("lamps.out", "w");
	int temp, c;
	fscanf(fi, "%d\n%d", &N, &c);
	for(n1 = 0, fscanf(fi, "%d", &temp); temp > 0; ++n1) {
		ON[n1] = temp;
		fscanf(fi, "%d", &temp);
	}
	for(n2 = 0, fscanf(fi, "%d", &temp); temp > 0; ++n2) {
		OFF[n2] = temp;
		fscanf(fi, "%d", &temp);
	}
	if (c == 0) {
		check(0,0,0,0);
	}
	else if (c == 1) {
		check(1,0,0,0);	check(0,1,0,0);  check(0,0,0,1); check(0,0,1,0); 
	}
	else if (c == 2) {
		check(1,0,0,0);  check(0,0,1,1);  check(0,1,0,0); check(0,0,1,0); check(1,0,0,1);  check(0,1,0,1); check(0,0,0,0); 
	} else {
		check(1,0,0,0);  check(0,0,1,1);  check(0,1,0,0);  check(0,0,0,1); check(1,0,0,1); check(0,0,1,0);  check(0,1,0,1); check(0,0,0,0); 
	}
	if (!flag)
		fprintf(fo, "IMPOSSIBLE\n");
	return 0;
}

void check(int i1, int i2, int i3, int i4)
{
	int i;
	for(i = 1; i <= N; ++i)
		lamp[i] = 1;
	if (i1)
		for(i = 1; i <= N; ++i)
			lamp[i] = !lamp[i];
	if (i2)
		for(i = 1; i <= N; i+=2)
			lamp[i] = !lamp[i];	
	if (i3)
		for(i = 1; i < N; i+=2)
			lamp[i+1] = !lamp[i+1];	
	if (i4)
		for(i = 1; i <= N; i+=3)
			lamp[i] = !lamp[i];
	for(i = 0; i < n1; ++i)
		if(!lamp[ON[i]])
			return;
	for(i = 0; i < n2; ++i)
		if(lamp[OFF[i]])
			return;
	for(i = 1; i <= N; ++i)
		fprintf(fo, "%d", lamp[i]);
	fputc('\n', fo);
	flag = 1;
}
