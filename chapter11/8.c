#include <stdio.h>
#include <string.h>
#define LEN 80
char * reverse(char *str);

int main(void)
{
	char input[LEN];
	char *chk;
	
	puts("Enter a string:");
	while(gets(input) && input[0] != '\0')
		{
			chk = reverse(input);
			puts("Reversed:");			
			puts(chk);

		}
	puts("Done.");
	
	return 0;
}

char * reverse(char *str)
{
	char *temp = str;
	char tem = 0;
	int len = strlen(str);
	int i;
	
	for(i=0; i<(len/2); i++)
		{
			tem = str[i];
			str[i] = str[len-i-1];
			str[len-i-1] = tem;
		}
	
	return temp;
}
