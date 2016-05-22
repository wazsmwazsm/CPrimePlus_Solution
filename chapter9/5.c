/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
void larger_of(double *, double *);
int main(void)
{
	double a,b;
	printf("input two number:");
	scanf("%lf %lf",&a,&b);
	while(getchar()!='\n');
	larger_of(&a,&b);
	printf("the result is: a = %.3f,b = %.3f\n",a,b);
	return 0;
}

void larger_of(double *x, double *y)
{
	
	 *y = *x = *x>*y ? *x:*y;

}