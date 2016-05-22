/*
function : Make a list, Show square and cube
*/

#include <stdio.h>

int main(void)
{
		int i,min,max;
		printf("Please input the min and max:");
		scanf("%d %d",&min,&max);
		printf("%10s%10s%10s\n","num","square","cube");
		
		for(i=min;i<=max;i++)
		{
			printf("%10d%10d%10d\n",i,i*i,i*i*i);

		}
	
return 0;
	
}