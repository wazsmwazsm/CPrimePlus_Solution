/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>

int main(void)
{
	int num=0;
	int ct_even=0,ct_odd=0;
	double sumeven=0,sumodd=0;
//only accept int and the num = 0	
	while((scanf("%d",&num) == 1) && num != 0)
		{
			if(num % 2 == 1)
				{
					sumodd += num;		//add the odd
					ct_odd++;					//count the number of odd
				}
			else
				{
					sumeven += num;		//add the even
					ct_even++;				//count the number of even
					
				}
		}
	printf("Number of evens: %d \n",ct_even);
	if(ct_even > 0)
		printf(" average: %g\n",sumeven/ct_even);
		
	printf("Number of odds: %d \n",ct_odd);
	if(ct_odd > 0)
		printf(" average: %g\n",sumodd/ct_odd);	
		
	printf("\n Done! \n");
	
return 0;
}