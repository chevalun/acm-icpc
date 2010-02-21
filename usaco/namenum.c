/*
ID: chevalu2
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <math.h>

double to_num(char *);

int main()
{
	FILE *fi = fopen("namenum.in", "r");
	FILE *fo = fopen("namenum.out", "w");
	FILE *fd = fopen("dict.txt", "r");
	int flag = 0;
	double num;
	char temp[20];
	fscanf(fi, "%lf", &num);
	while(fscanf(fd, "%s", temp) > 0) {
		if (to_num(temp) == num) {
			fprintf(fo, "%s\n", temp);
			flag = 1;
		}
	}
	if (!flag)
		fprintf(fo, "NONE\n");
	return 0;	
}

double to_num(char *str)
{
	double rst = 0.0;
	while(*str) {
		rst = rst * 10 + ((*str < 'S') ? ((*str - 'A')/3 + 2.0) : ((*str - 'Q')/3 + 7.0));
		++str;
	}
	return rst;
}