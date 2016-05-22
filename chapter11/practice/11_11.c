#include <stdio.h>

int main(void)
{
	
	
	return 0;
}
int put2(const char * string)
{
	int count = 0;
	
	while(*string )
		{
			putchar(*string++);
			count++;
		}
	putchar('\n')
	
	return count;
}


