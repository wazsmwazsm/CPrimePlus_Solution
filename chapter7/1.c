/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>

int main(void)
{
	char ch;
	int space = 0,newline = 0,others = 0;
	
	while((ch = getchar())!= '#')
	{
		if(ch == ' ')
			space++;
		else if (ch == '\n')
			newline++;
		else
			others++;
	}
	printf("spaces: %d \n newlines: %d \n others %d\n", \
	space,newline,others);
	
	
	
return 0;
}