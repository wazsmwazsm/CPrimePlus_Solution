#include <stdio.h>
#include "2_a.h"

static int persent_mode = METRIC;
static double distance;
static double fuel;


void	set_mode(int mode)
{
	if(mode == US || mode == METRIC)
		persent_mode = mode;
	else
		printf("Invalid mode specified. Mode %s used.\n",
		       persent_mode == METRIC ? "0(METRIC)":"1(US)");
}
void	get_info(void)
{
	if(persent_mode == METRIC)
		{
			printf("Enter distance traveled in kilometers:\n");
			scanf("%lf",&distance);
			printf("Enter fuel consumed in liters:\n");
			scanf("%lf",&fuel);
		}
	else
		{
			printf("Enter distance traveled in miles:\n");
			scanf("%lf",&distance);
			printf("Enter fuel consumed in gallons:\n");
			scanf("%lf",&fuel);
		
		}
}
void	show_info(void)
{
	if(persent_mode == METRIC)
		{
			printf("Fuel consumption is %g liters per 100km.\n",
						 fuel / (distance / 100));
		}
	else
		{
			printf("Fuel consumption is %g miles per gallon.\n",
			       distance / fuel);
		
		}
}