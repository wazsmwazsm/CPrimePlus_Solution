#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	unsigned int num = 0;
	srand((unsigned int)time(0));
	
	printf("Now I build a number ( 0 ~ 5 ), you can guess it.\n");
	while(scanf("%u",&num) == 1 )
		{
			if(num > 5 || num < 1)
				printf("Please enter ( 0 ~ 5 )\n");
			else	
				{
					if(num == cai())
					{
						printf("Oh~~ you did it!\n");
						break;
					}
				else
					printf("Oh, it is wrong. Try again and q to quit!\n");
				}
			
		}
		printf("Bye~\n");
		
	return 0;
}


int cai(void)
{
	int roll ;
	roll = rand() % 5 + 1;
	
	return roll;

}

