/*
function : input you name tall ,and Print out 
*/

#include <stdio.h>

int main(void)
{
	
	float hight;
	char name[20];
	printf("Please input your name :\n");
	scanf(" %s",name);
	printf("Please input your hight :\n");
	scanf(" %f",&hight);

	printf(" %s ,You are %.2f feet tall,right? \n",name,hight/12);
	
return 0;
	
}