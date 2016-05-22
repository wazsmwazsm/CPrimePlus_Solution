#include <stdio.h>
#include <ctype.h>
#define LEN 80
char * getword(char * str);

int main(void)
{
	char input[LEN];
	char *chk;
	
	puts("Enter a string and we will get the first word!");
	
	chk = getword(input);
	if(chk != NULL)
		puts(input);
	else
		puts("input failed");
	puts("Done.");
	return 0;
}

char * getword(char * str)
{
	int ch;
	
	while((ch = getchar()) != EOF && !isspace(ch))	
		*str++ = ch;
	*str = '\0';
	
	if (ch == EOF)
		return NULL;
	else
		{
			while(getchar() != '\n');
			return str;
		}
}
