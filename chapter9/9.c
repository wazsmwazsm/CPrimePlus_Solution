/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
void to_base_n(unsigned long , unsigned int );
int main(void)
{
		unsigned long number;
		unsigned int base;
		printf("Enter an inreger and a base(q to quit):\n");
		while(scanf("%lu %u",&number,&base) == 2)
		{
			if(base < 2 || base > 10) 
				{
					printf("Please enter base range of 2 to 10!\n");
					printf("Enter an inreger and a base(q to quit):\n");
					continue;
				}
			printf("%lu's base %u equivalent:",number,base);
			to_base_n(number,base);
			while(getchar() != '\n');
			putchar('\n');
			printf("Enter an inreger and a base(q to quit):\n");

		}

return 0;
}

void to_base_n(unsigned long n, unsigned int base)
{
	int r =0;
	r = n % base;
	if(n >= base)
		to_base_n(n/base, base);
	putchar('0' + r);
	
	return;
}


