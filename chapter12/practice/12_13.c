#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int dice, roll;
	int side;
	
	srand((unsigned int ) time(0));
	
	printf("Enter the number of sides per die, 0 to stop.\n");
	
	while(scanf("%d",&side) ==1 && side>0)
	{
		printf("How many dice?\n");
		scanf("%d",&dice);
		roll = roll_n_dice(dice, side);
		printf("You have rolled a %d using %d %d-side dice",
						roll, dice, side);
		printf("How many sides? 0 to stop.\n");
	}
	
	printf("The rollem() function was called %d times.\n",roll_count);
	printf("GOOD FORTUNR TO YOU!\n");
	
	return 0;
}
