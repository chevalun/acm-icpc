/*
ID: chevalu2
LANG: C
TASK: spin
*/
#include <stdio.h>

int check(int t);
int speed[5], num[5], angel[5][5], extent[5][5];

int main()
{
	FILE *fi = fopen("spin.in", "r");
	FILE *fo = fopen("spin.out", "w");
	int i, j, t;
	for(i = 0; i < 5; ++i) {
		fscanf(fi, "%d %d", &speed[i], &num[i]);
		for(j = 0; j < num[i]; ++j)
			fscanf(fi, "%d %d", &angel[i][j], &extent[i][j]);
	}
	t = 0;
	for(;;) {
		if (check(t)) {
			fprintf(fo, "%d\n", t);
			return 0;
		}
		++t;
		if (t > 360) {
			fprintf(fo, "none\n", t);
			return 0;
		}
	}
	return 0;	
}

int check(int t)
{
	int x, i, flag = 1, j, f, s;
	for(x = 0; x <= 359; ++x) {
		flag = 1;
		for(i = 0; (i < 5) && flag; ++i) {
			f = 0;
			for(j = 0; j < num[i]; ++j) {
				s = (t*speed[i] + angel[i][j]) % 360;
				if(s + extent[i][j] < 360)
					f = (x >= s) && (x <= s + extent[i][j]);
				else
					f = ((x >= s) && (x <= 359)) || ((x >= 0) && (x <= (s + extent[i][j]) % 360));
				if (f)
					break;
			}
			flag = flag && f;
		}
		if (flag)
			return 1;
	}
	return 0;
}