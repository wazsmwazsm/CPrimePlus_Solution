/*
function : show time,minutes to hour 
*/

#include <stdio.h>
#define HOUR 60
int main(void)
{
	int minutes;
	printf("Please input the minutes :\n");
	scanf(" %d",&minutes);
	while(minutes > 0)
	{
		printf("%d hours and %d minutes.",minutes/HOUR,minutes%HOUR);
		printf("Please input the minutes :\n");
		scanf(" %d",&minutes);
	}
	
return 0;
	
}