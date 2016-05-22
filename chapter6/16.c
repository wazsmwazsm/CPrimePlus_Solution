
#include <stdio.h>

int main(void)
{
		double investment = 1000000;
		int i=0;
		
		while(investment > 0)
		{
			investment += investment*0.08;
			investment -= 100000;
			i++ ;
		}
		printf("After %d years,Chuckie Lucky's investment is out\n",i);
		
return 0;
	
}