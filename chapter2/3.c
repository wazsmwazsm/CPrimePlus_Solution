#include <stdio.h>

int main(void)
{
	int age = 0 , day = 0 ;
	printf("Please input your age: \n");
	scanf(" %d",&age);
	day = age * 365;
	printf("You live %d days : \n",day);	
return 0;

}
