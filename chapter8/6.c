/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
#include <ctype.h>

char get_first(void);
int main(void)
{
	char ch;
	while((ch=get_first()) != EOF)
	{
		putchar(ch);
		
	}
	
return 0;
}

char get_first(void)
{
	char ch;
	while(isspace(ch = getchar()));
	while(getchar() != '\n');
	
	return ch;
	
}