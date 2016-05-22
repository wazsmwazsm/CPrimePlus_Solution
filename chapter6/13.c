
#include <stdio.h>

int main(void)
{

	double num[8],sum[8];
	int i,j;
	printf("Enter 8 numbers:");
	
	for(i=0;i<8;i++)
	{
		scanf("%lf",&num[i]);
		for(j=0;j<=i;j++)
			sum[i] += num[j];
		
	}
	
	printf("%-10s %-10s\n","mun","sum");
	for(i=0;i<8;i++)
		printf("%10lf %10lf\n",num[i],sum[i]);
		
		
return 0;
	
}