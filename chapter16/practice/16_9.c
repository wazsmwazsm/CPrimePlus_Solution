#include <stdio.h>
#define LIMIT	4
#define JUST_CHECKING

int main(void)
{
	int i;
	int total = 0;
	
	for(i = 1; i <= LIMIT; i++)
		{
			total += 2*i*i +1;
#ifdef JUST_CHECKING	
			printf("i=%d, running total = %d\n",i,total);
#endif			
		}
	printf("Grand total = %d\n",total);
		
	return 0;
}
