
#include <stdio.h>

float calculate(float x,float y);

int main(void)
{
	float a,b;
	
	printf("Please input two floats:");
	 
	while(scanf("%f %f",&a,&b) == 2)
	{
		printf("(%.2f-%.2f)/(%.2f*%.2f) = %.2f\n",		\
		a,b,a,b,calculate(a,b));
	}
	printf("end\n");
	
return 0;
	
}

float calculate(float x,float y)
{
	return ((x-y)/(x*y));
}
