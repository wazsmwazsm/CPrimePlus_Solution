#include <stdio.h>

int main(void)
{
	char over;
	int i;
	over = 1;
	while(1)
	{
		over = over + 1 ;
		
		for(i=0;i<40000000;i++);
		
		printf("over =  %d\n",over);
	}
	
	
return 0;	
}