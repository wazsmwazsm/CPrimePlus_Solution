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
	int count=0;
	
	printf("Please input a string ,we will count the number of 'ei'\n");
	
	while((ch = getchar()) != '#')
	{
		if(ch == 'e')
			{
				if((ch = getchar()) == 'i') count++;
			}
	}	
	printf("the number of 'ei' is: %d \n",count);	
return 0;
}
/*  the other way:
		char former;
		while((ch = getchar()) != '#')
		{
			if(former == 'e' && ch == 'i') count++;
			former = ch ;
		}	
*/