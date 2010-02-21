/*
ID: chevalu2
LANG: C
TASK: ride
*/
#include <stdio.h>

int main()
{
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	char a[10], b[10];
	char *c;
	int ca = 1, cb = 1;
	fscanf(fin, "%s", a);
	fscanf(fin, "%s", b);
	for (c = a; *c; ++c) 
		ca *= (*c - 'A') + 1;
	for (c = b; *c; ++c) 
		cb *= (*c - 'A') + 1;
	if ((ca % 47) == (cb % 47))
		fprintf(fout, "GO\n");
	else
		fprintf(fout, "STAY\n");
	return 0;	
}