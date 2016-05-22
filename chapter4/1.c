/*
function : input you name ,and Print out 
*/

#include <stdio.h>

int main(void)
{
	char surname[20],firstname[20];
	printf("Please input your firstname and surname :\n");
	scanf(" %s",firstname);
	scanf(" %s",surname);
	printf("Hi,You are %s %s ,right? \n",firstname,surname);
	
return 0;
	
}