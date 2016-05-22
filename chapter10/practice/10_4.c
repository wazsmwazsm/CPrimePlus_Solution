#include <stdio.h>

int main(void)
{
	int day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;
	
	for(index = 0; index < sizeof day / sizeof day[0]; index++)
		printf("Month %d has %d days.\n",index+1,
			day[index]);
	
	return 0;
}
