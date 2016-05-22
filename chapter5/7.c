/*
function : input you name ,and Print out 
*/

#include <stdio.h>
float cube(float num);

int main(void)
{
	float number;
	printf("Please input the number:\n");
	scanf(" %f",&number);

	printf("the cube %.1f is %.1f\n",number,cube(number));
	
return 0;
	
}

float cube(float num)
{
	return (num*num*num);
}