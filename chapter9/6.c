/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
#include <ctype.h>

int ABC(char ch);

int main(void)
{
		char ch;
		
		printf("input a char:");
		scanf("%c",&ch);
		while(getchar()!='\n');
		printf("the position of the char in ABC is: %d\n",ABC(ch));
		return 0;
}
int ABC(char ch)
{
	if(isalpha(ch))
		return tolower(ch) - 'a' + 1;
	else 
		return -1;	
}
