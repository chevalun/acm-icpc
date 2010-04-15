#include <stdio.h>

int jump[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

int main()
{
	char t1[5], t2[5];
	int q[100][3], flag[10][10], x, y, len, a, b, i, j, t, s, f;
	while(scanf("%s %s", t1, t2) == 2) {
		t = s = 0;
		for(i = 1; i <= 8; ++i)
			for(j = 0; j <= 8; ++j)
				flag[i][j] = 0;
		a = t2[0] - 'a' + 1;
		b = t2[1] - '0';
		q[s][0] = t1[0] - 'a' + 1;
		q[s][1] = t1[1] - '0';
		q[s][2] = 0;
		flag[q[s][0]][q[s][1]] = 1;
		f = 0;
		if ((q[s][0] == a) && (q[s][1] == b)) {
			printf("To get from %s to %s takes %d knight moves.\n", t1, t2, 0);
			continue;
		}
		while(!f) {
			for(i = 0; i < 8; ++i) {
				x = q[s][0] + jump[i][0];
				y = q[s][1] + jump[i][1];
				if ((x >= 1) && (x <= 8) && (y >= 1) && (y <= 8) && (!flag[x][y])) {
					++t;
					q[t][0] = x;
					q[t][1] = y;
					q[t][2] = q[s][2] + 1;
					flag[x][y] = 1;
					if ((x == a) && (y == b)) {
						f = 1;
						printf("To get from %s to %s takes %d knight moves.\n", t1, t2, q[t][2]);
						break;
					}
				}
			}
			++s;
		}
	}
	return 0;
}