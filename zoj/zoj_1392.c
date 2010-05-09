#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[300];
	int i;
	while(gets(str) != NULL) {
		if(str[0] == 'E')
			break;
		gets(str);
		for(i = 0; str[i]; ++i)
			if(isalpha(str[i]))
				str[i] = (str[i] + 21 - 'A') % 26 + 'A'; 
		puts(str);		
		gets(str);
	}
	return 0;
}