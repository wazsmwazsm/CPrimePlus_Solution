/*
function : Print out number to  number+10
*/

#include <stdio.h>

int main(void)
{
	int num,i=0;
	printf("Please input a number :\n");
	scanf(" %d",&num);
	
	while(i++ < 11)
		printf("%d\n",num++);
	
return 0;
	
}