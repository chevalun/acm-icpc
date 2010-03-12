/*
ID: chevalu2
LANG: C
TASK: shopping
*/

#include <stdio.h>
#define min(x,y) (((x) < (y)) ? (x) : (y))

int dict[1000];
int offer[100][10], dp[10][10][10][10][10], price[100], p[10], goal[10], num[100], tt[100][10][2];

int main()
{
	FILE *fi = fopen("shopping.in", "r");
	FILE *fo = fopen("shopping.out", "w");
	int i0, i1, i2, i3, i4, j, s, i, n, temp, b, c;
	fscanf(fi, "%d", &s);
	for(i = 0; i < s; ++i) {
		fscanf(fi, "%d", &num[i]);
		for(j = 0; j < num[i]; ++j) {
			fscanf(fi, "%d", &tt[i][j][0]);
			fscanf(fi, "%d", &tt[i][j][1]);
		}
		fscanf(fi, "%d", &price[i]);
	}
	fscanf(fi, "%d", &b);
	for(i = 0; i < b; ++i) {
		fscanf(fi, "%d", &c);
		dict[c] = i;
		fscanf(fi, "%d %d", &goal[i], &p[i]);
	}
	for(i = 0; i < s; ++i)
		for(j = 0; j < num[i]; ++j)
			offer[i][dict[tt[i][j][0]]] = tt[i][j][1];
	for(i0 = 0; i0 <= goal[0]; ++i0)
		for(i1 = 0; i1 <= goal[1]; ++i1)
			for(i2 = 0; i2 <= goal[2]; ++i2)
				for(i3 = 0; i3 <= goal[3]; ++i3)
					for(i4 = 0; i4 <= goal[4]; ++i4)
						dp[i0][i1][i2][i3][i4] = i0*p[0] + i1*p[1] + i2*p[2] + i3*p[3] + i4*p[4];
	for(j = 0; j < s; ++j)
		for(i0 = offer[j][0]; i0 <= goal[0]; ++i0)
			for(i1 = offer[j][1]; i1 <= goal[1]; ++i1)
				for(i2 = offer[j][2]; i2 <= goal[2]; ++i2)
					for(i3 = offer[j][3]; i3 <= goal[3]; ++i3)
						for(i4 = offer[j][4]; i4 <= goal[4]; ++i4)
							dp[i0][i1][i2][i3][i4] = min(dp[i0][i1][i2][i3][i4], dp[i0-offer[j][0]][i1-offer[j][1]][i2-offer[j][2]][i3-offer[j][3]][i4- offer[j][4]] + price[j]);
	fprintf(fo, "%d\n", dp[goal[0]][goal[1]][goal[2]][goal[3]][goal[4]]);					
	return 0;	
}