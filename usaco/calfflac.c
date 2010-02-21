/*
ID: chevalu2
LANG: C
TASK: calfflac
*/
#include <stdio.h>
#include <ctype.h>

char buf[21000];
void search(int, int);
int max, ss, tt, flag;
int N = 0;
int main()
{
	FILE *fi = fopen("calfflac.in", "r");
	FILE *fo = fopen("calfflac.out", "w");
	int i, j, c;
	while ((c = fgetc(fi)) != EOF)
		buf[N++] = c;
	for(i = 0; i < N; ++i) {
		if (!isalpha(buf[i]))
			continue;
		search(i, i);
		for (j = i+1; j < N; ++j) {
			if (toupper(buf[j]) == toupper(buf[i])) {
				search(i, j);
				break;
			}
			if (isalpha(buf[j]))
				break;
		}
	}
	fprintf(fo, "%d\n", max*2 + 1 + flag);
	for (i = ss; i <= tt; ++i)
		fputc(buf[i], fo);
	fputc('\n', fo);
	return 0;
}

void search(int s, int t)
{
	int len = 0, tmp = !(s==t);
	for(;;) {
		while ((s > 0) && (!isalpha(buf[--s])))
			;
		while ((t < N) && (!isalpha(buf[++t])))
			;
		if (toupper(buf[s]) == toupper(buf[t])) {
			++len;
			if (len > max) {
				max = len;
				ss = s;
				tt = t;
				flag = tmp;
			}
		} else {
			break;
		}
		
	}
}