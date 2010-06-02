#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j;
	char num[2000], tot, len, k, flag;
	scanf("%d\n", &N);
	for(i = 0; i < N; ++i) {
		memset(num, 0, sizeof(num));
		scanf("%s", num);
		len = strlen(num);
		tot = num[len - 1] - '0';
		flag = 0;
		for(j = (len - 2); j >= 0; --j) {
			tot += num[j] - '0';
			if(num[j] != '9') {
				if(tot - num[j] + '0' - 1< 0)
					continue;
				flag = 1;
				num[j] += 1;
				tot = tot - num[j] + '0';
				for(k = len - 1; k > j; --k) {
					if(tot >= 10) {
						num[k] = '9';
						tot -= 9;
					}
					else {
						num[k] = tot + '0';
						tot = 0;
 					}
				}
				break;
			}
		}
		if(!flag) {
			num[0] = '1';
			--tot;
			for(k = len; k > 0; --k) {
				if(tot >= 10) {
					num[k] = '9';
					tot -= 9;
				}
				else {
					num[k] = tot + '0';
					tot = 0;
 				}
			}
		}
		printf("%s\n", num);
	}
}