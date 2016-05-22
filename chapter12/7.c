#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollem(int sides);


int main(void)
{
	int set,side,dice;
	int i,sum;
	
	puts("Enter the number of sets.Enter q to stop:");
	while(scanf("%d",&set) == 1)
	{
		srand((unsigned int)time(0));
		
		puts("How many sides and how many dice?");		
		while(scanf("%d%d", &side, &dice) != 2)
			{
				scanf("%*s");
				puts("Input error! Try again:");
			}
			
		printf("Here are %d sets of %d %d-siged throws.\n",
					 set, dice, side);
					 
		while(set--)
			{
				for(i=0,sum=0; i<dice; i++)
					sum += rollem(side);
					
				printf("\t%d",sum);
				
				if(set%15 == 14)
					putchar('\n');
			}
		if(!(set%15))
			putchar('\n');
			
		puts("\nHow many sets? Enter q to stop.");
	}
	
	
	return 0;
}

int rollem(int sides)
{
	int roll;
		
	roll = rand()%sides + 1;
	return roll;	
}

