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
		int i;
		
		for(i=1;(ch = getchar()) != EOF;i++)
			{
				// Character is '\n' or '\t'
				if(ch >= ' ' || ch == '\n' || ch == '\t')
					printf(" %-5c",ch);
				else  // Character Less than ' '(32 in ascii)
					printf(" ^%-4c",ch+64);
				printf(" %-5d",ch);		// print Character ASCII value 
				
				if(i%10 == 0)  //10 couple per line
					printf("\n");
			}
			printf("\n");
return 0;
}