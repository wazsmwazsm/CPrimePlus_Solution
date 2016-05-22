/*
function : Read floats ,and print out 
*/

#include <stdio.h>

int main(void)
{
	float a;
	printf("Please input a float:\n");
	scanf(" %f",&a);
	
	printf("The input is %.1f or %.1e \n",a,a);
	printf("The input is %+.3f or %.3E \n",a,a);
	
return 0;
	
}