/*
function : input you name ,and Print out in diffrent way
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[20];
	int width;
	printf("Please input your name :\n");
	scanf(" %s",name);
	
	printf("\"%s\"\n",name);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	
	width = strlen(name) + 3;
	printf("\"%*s\"\n",width,name);
	
return 0;
	
}