/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>

int main(void)
{
	int guess,max=100,min=1;
	char respones;
	printf("Pick an integer from 1 to 100.I will try to guess it.\n");
	printf("Respond with 'a' or 'l' if my guess is big or little.\n");
	printf("Also,respond 'y' if it is right.\n");
	printf("Uh...is your number %d?\n",guess=(max+min)/2);
	while((respones=getchar())!= 'y')
	{
		if(respones == 'b')
		{
			max = guess-1;
			printf("Uh...is your number %d?\n",guess=(max+min)/2);
		}
		else if(respones == 'l')
		{
			min = guess+1;
			printf("Uh...is your number %d?\n",guess=(max+min)/2);
		}
		else
			printf("Sorry, i understand only 'y' or 'n'.\n");
		while(getchar()!='\n');
		
		if(max < min) 
			{
				printf("Oh!You must be lying to me.\n");
				break;
			}
	}
	if(max >= min)
		printf("I konw i could do it!\n");
	else
		printf("Bye!\n");
		
return 0;
}

