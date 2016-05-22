#include <stdio.h>
#include <stdlib.h>
double mypower(double base, int exp);		//也可以使用数学库的pow函数
int main(int argc, char *argv[])
{
		double base;
		int exp;	
		if(argc != 3)
			printf("Usage: %s number exponent\n",argv[0]);
		else
			{
				base = atof(argv[1]);
				exp = atoi(argv[2]);
				printf("%.3g to the power %d is %.5g.\n",base,exp,mypower(base,exp));
		
		  }
	return 0;
}
double mypower(double base, int exp)
{
	int i;
	double power = 1;
	if(base == 0)
		{
			power = 1/base;
			return power;	
		}
	if(exp > 0)
		for(i=1; i<=exp;i++)
			power *= base;
	else if(exp < 0)
		for(i=-1; i>=exp;i--)
			power /= base;
	else 
		power = 1;
	
	return power;	
		
}

