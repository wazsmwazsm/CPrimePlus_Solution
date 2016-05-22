/*
function : day to week and day 
*/

#include <stdio.h>
#define WEEK 7

int main(void)
{
	int day;
	printf("Please input day :\n");
	scanf(" %d",&day);
	while(day > 0)
	{
	printf("%d week %d day\n",day/WEEK,day%WEEK);
	printf("Please input day :\n");
	scanf(" %d",&day);	
	}
return 0;
	
}