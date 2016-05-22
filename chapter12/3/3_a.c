#include <stdio.h>
#include "3_a.h"


void	set_mode(int *mode)
{
	if(*mode != US && *mode != METRIC)
		{
		printf("Invalid mode specified.Previous mode will be used.\n");
		*mode = USE_RECENT;
	  }
}
void	get_info(int mode, double *distance, double *fuel)
{
	if(mode == METRIC)
		{
			printf("Enter distance traveled in kilometers:\n");
			scanf("%lf",distance);
			printf("Enter fuel consumed in liters:\n");
			scanf("%lf",fuel);
		}
	else
		{
			printf("Enter distance traveled in miles:\n");
			scanf("%lf",distance);
			printf("Enter fuel consumed in gallons:\n");
			scanf("%lf",fuel);
		
		}
}
void	show_info(int mode, double distance, double fuel)
{
	if(mode == METRIC)
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