
#include <stdio.h>

int main(void)
{
	float a,b;
	
	printf("Please input two floats:");
	 
	while(scanf("%f %f",&a,&b) == 2)
	{
		printf("(%.2f-%.2f)/(%.2f*%.2f) = %.2f\n",		\
		a,b,a,b,(a-b)/(a*b));
	}
	printf("end\n");
	
return 0;
	
}

/*  or
int s;

do 
{
	printf("Please input two floats:");
	s = scanf("%f %f",&a,&b);
	printf("(%.2f-%.2f)/(%.2f*%.2f) = %.2f\n",		\
		a,b,a,b,(a-b)/(a*b));
}
while(s == 2);

*/