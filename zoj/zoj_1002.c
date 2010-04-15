#include <stdio.h>

int map[5][5], max, num, N;
void try(int);
int legal(int , int);

int main()
{
	int i, j;
	char c;
	while (scanf("%d\n", &N) != EOF) {
		if (!N)
			break;
		for(i = 1; i <= N; ++i) {
			for(j = 1; j <= N; ++j) {
				c = getchar();
				if (c == '.')
					map[i][j] = 0;
				else
					map[i][j] = 1;
			}
			getchar();
		}
		max = num = 0;
		try(0);
		printf("%d\n", max);
	}
	return 0;
}

void try(int x)
{
	int i, j;
	if (x > max) {
		max = x;
		num = 1;
	} else if (max == x)
		++num;
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= N; ++j)
			if (legal(i, j)) {
				map[i][j] = -1;
				try(x+1);
				map[i][j] = 0;
			}
}

int legal(int a, int b)
{
	int i, temp;
	if ((a < 1) || (a > N) || (b < 1) || (b > N))
		return 0;
	if(map[a][b] != 0)
		return 0;
	for(i = a + 1, temp = 0; i <= N; ++i) {
		temp += map[i][b];
		if (temp < 0)
			return 0;
	}
	for(i = a - 1, temp = 0; i >= 1; --i) {
		temp += map[i][b];
		if (temp < 0)
			return 0;
	}
	for(i = b + 1, temp = 0; i <= N; ++i) {
		temp += map[a][i];
		if (temp < 0)
			return 0;
	}
	for(i = b - 1, temp = 0; i >= 1; --i) {
		temp += map[a][i];
		if (temp < 0)
			return 0;
	}
	return 1;
}