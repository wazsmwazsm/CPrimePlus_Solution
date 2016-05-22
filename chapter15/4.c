#include <stdio.h>

unsigned int check_bit(unsigned int  , unsigned int );

int main(void)
{
	unsigned int number, bit;
	puts("Enter number and bit position (q to quit):");
	while(scanf("%d %d", &number, &bit) == 2 )
		{
			printf("bit %d of %d is %d\n", bit, number,
						 check_bit(number, bit));
			puts("Enter next numbr (q to quit):");	
		}
		
	puts("Done!");
	
	return 0;
}

unsigned int check_bit(unsigned int number , unsigned int bit)
{
	return (number>>bit) & 01;
}
