/*
ID: chevalu2
LANG: C
TASK: contact
*/
#include <stdio.h>

int count[4096][13];
char s[200000];
int cmp(void *, void *);
struct node {
	int c, v, l;
};
typedef struct node str;
str ss[100000];
void output(int val, int len);
FILE *fo;

int main()
{
	FILE *fi = fopen("contact.in", "r");
	fo = fopen("contact.out", "w");
	int A, B, N, l = 0, i, j, temp, k, n = 0, t = 0, fk;
	char c;
	fscanf(fi, "%d %d %d\n", &A, &B, &N);
	while ((c = fgetc(fi)) != EOF) {
		if ((c == '0') || (c == '1'))
			s[l++] = c - '0';
	}
	for(i = 0; i < l; ++i)
		for(j = A; j <= B; ++j) {
			if (i+j > l)
				break;
			temp = 0;
			for (k = 0; k < j; ++k)
				temp = (temp << 1) | s[i+k];
			++count[temp][j];
		}
	for(i = 0; i < 4096; ++i)
		for(j = A; j <= B; ++j) 
			if(count[i][j] > 0) {
				ss[n].c = count[i][j];
				ss[n].v = i;
				ss[n].l = j;
				++n;
			}
	qsort(ss, n, sizeof(str), cmp);	
	for(i = 0; i < N; ++i) {
		fprintf(fo, "%d\n", ss[t].c);
		fk = 0;
		while (ss[t].c == ss[t+1].c) {
			output(ss[t].v, ss[t].l);
			++t;
			if(t >= n)
				break;
			++fk;
			if(fk % 6 == 0)
				fputc('\n', fo);
			else
				fputc(' ', fo);
		}
		output(ss[t].v, ss[t].l);
		fputc('\n', fo);
		++t;
		if(t >= n)
			break;
	}		
	return 0;	
}

int cmp(void *a, void *b)
{
	if ((((str *) a)->c == ((str *) b)->c) && (((str *) a)->l == ((str *) b)->l))
		return ((str *) a)->v - ((str *) b)->v;
	if (((str *) a)->c == ((str *) b)->c)
		return ((str *) a)->l - ((str *) b)->l;
	return ((str *) b)->c - ((str *) a)->c;	
}

void output(int val, int len)
{
	char s[13];
	int i, t = len - 1;
	for(i = 0; i < 13; ++i)
		s[i] = '0';
	while(val) {
		s[t--] = (val & 1) + '0';
		val >>= 1;
	}
	s[len] = '\0';
	fprintf(fo, "%s", s);	
}