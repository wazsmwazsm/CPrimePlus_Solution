/*
*	name:
*	function: '.' replace by '!' , '!' replace by '!!' ,and count the times when replaced
*	
*
*/

#include <stdio.h>

int main(void)
{
	char ch=0;
	int i=0,j=0;
	
	printf("Please input a string end by #\n");
	
	while((ch = getchar())!= '#')
	{
		if(ch == '.')
			{
				putchar('!');
				i++;
			}
		else if(ch == '!')
			{
				putchar('!');
				putchar('!');
				j++;
			}
		else
			putchar(ch); 
	}
	printf("\n the times of '.' replaced by '!':%d \n",i);
	printf("\n the times of '!' replaced by '!!':%d \n",j);
	
	
return 0;
}