/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
double power(double n, int p);
int main(void)
{
		double x;
		int exp_exp;
		printf("input the base number and the exponent:");
		while(scanf("%lf %d",&x,&exp_exp)== 2)
		{
			while(getchar() != '\n');
			printf("%.3g to the power %d is %.5g.\n",x,exp_exp,power(x,exp_exp));
			printf("input the base number and the exponent:");
		}
return 0;
}

double power(double n, int p)
{
	int i;
	double pow_pow = 1;
	if(n == 0)
		{
			pow_pow = 1/n;
			return pow_pow;	
		}
	if(p > 0)
		for(i=1; i<=p;i++)
			pow_pow *= n;
	else if(p < 0)
		for(i=-1; i>=p;i--)
			pow_pow /= n;
	else 
		pow_pow = 1;

		
	return pow_pow;	
}



