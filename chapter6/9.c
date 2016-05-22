
#include <stdio.h>

int main(void)
{
	int min,max,i,sum;
	
	printf("Please input min and max limits:");
	scanf("%d %d",&min,&max);
	
	while(min < max)
	{
	for(i=min,sum=0;i<=max;i++) sum += i*i;
	printf("The sums of the squates from %d to %d is %d:",		\
	min*min,max*max,sum);
	printf("Please input min and max limits:");
	scanf("%d %d",&min,&max);
		
	}
return 0;
	
}