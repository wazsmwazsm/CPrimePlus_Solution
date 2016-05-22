#include <stdio.h>
#include "2_a.h"

int main(void)
{
	int mode;
	
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d",&mode);
	while(getchar()!= '\n');
	while(mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1 for US mode: ");
		printf("(-1 to quit): ");
		scanf("%d",&mode);
		while(getchar()!= '\n');
	}
	printf("Done.\n");
	return 0;
}

