#include <stdio.h>
#define MONTHS 12
int main(void)
{
	int day[MONTHS] = {31,28,[4]=31,30,31,[1]=31};
	int index;
	
	for(index = 0; index < MONTHS; index++)
		printf("Month %d has %d days.\n",index+1,
			day[index]);
	
	return 0;
}
