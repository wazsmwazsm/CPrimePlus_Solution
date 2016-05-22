/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
#define NO  0
#define YES 1
int main(void)
{
	long num;
	long div;
	long lim;
	int  prime;
	
	printf("Please enter limit to values to be checked:");
	printf("Enter q to quit. \n");
	
	while(scanf("%ld",&lim) == 1 && lim > 0)
	{
		for(num = 2; num <= lim ; num++)
			{
				for(div = 2,prime = YES;(div*div) <= num; div++)
						if(num % div == 0) prime = NO;
							
				if(prime == YES)	
					printf("%ld is prime.\n",num);		
							
			}
	printf("Please enter limit to values to be checked:");
	printf("Enter q to quit. \n");
	}

return 0;
}