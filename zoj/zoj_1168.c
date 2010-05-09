#include <stdio.h>

int wd[21][21][21], flag[21][21][21];

int w(int a, int b, int c)
{
	if ((a <= 0) || (b <= 0) || (c <= 0))
		return 1;
	if ((a > 20) || (b > 20) || (c > 20))
		return w(20, 20, 20);
	if(flag[a][b][c])
		return wd[a][b][c];
	flag[a][b][c] = 1;	
	if ((a < b) && (b < c))
		return wd[a][b][c] = w(a, b, c-1) + w(a,b-1,c-1) - w(a,b-1,c);
	else
		return wd[a][b][c] = w(a - 1, b, c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
}


int main()
{
	int a, b,c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF) {
		if ((a == -1) && (b == -1) && (c == -1))
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}