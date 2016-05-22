/*
*	name:
*	function:
*	
*
*/
#include <stdio.h>
double min(double x,double y);

int main(void)
{
	double x,y;
	printf("Enter tow numbers:\n");
	scanf("%lf %lf",&x,&y);
	printf("%.2f is the Minimal.\n",min(x,y));
	return 0;
}

double min(double x,double y)
{
	double min;
	min = x>y ? y:x;
  return min;
}
