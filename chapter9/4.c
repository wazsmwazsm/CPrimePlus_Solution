/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
double calculate(double x, double y);

int main(void)
{
	double x,y;
	printf("input two number:");
	scanf("%lf %lf",&x,&y);
	while(getchar()!='\n');
	printf("1/((1/%.2f+1/%.2f)/2) = %.3f\n",x,y,calculate(x,y));
	return 0;
}
double calculate(double x, double y)
{
	return 	1/((1/x+1/y)/2); 
}
