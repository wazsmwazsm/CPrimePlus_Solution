#include <stdio.h>
#include "16_6.h"

int main(void)
{
	names candidate;
	
	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	puts(" to this program!\n");
	
	
	return 0;
}
