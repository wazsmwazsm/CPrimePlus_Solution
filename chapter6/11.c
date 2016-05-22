
#include <stdio.h>

int main(void)
{
		double i,sum1,sum2;
		int sign,count;
		
		printf("Please input the count:");
		scanf("%d",&count);
		
		for(i=1.0,sign=1,sum1=0,sum2=0;i<=count;i++,sign = -sign)
		{
			sum1 += 1.0/i;
			sum2 += sign*1.0/i;
		}
		printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 ...(%d terms) = %lf\n",count,sum1);
	  printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 ...(%d terms) = %lf\n",count,sum2);

return 0;
	
}