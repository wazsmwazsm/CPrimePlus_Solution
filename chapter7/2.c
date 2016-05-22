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
	printf("Please input a string end by #\n");
	
	for(i=0;(ch=getchar())!='#';i++)
	{
		if(ch == '\n') 										/* filter the last '\n' */
			{
				printf("\n");
				continue;
			}
		printf("%-3d %-3c",ch,ch);				/* Align left, Spacing is 3 */
		if(i%8 == 0)
			printf("\n");
	}
	printf("\n Bye! \n");
	
	
return 0;
}
/*



*/