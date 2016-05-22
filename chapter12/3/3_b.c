#include <stdio.h>
#include "3_a.h"

int main(void)
{
	int mode;
	int persent_mode = METRIC;
	double distance, fuel;
	
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d",&mode);
	while(getchar()!= '\n');
	while(mode >= 0)
	{
		set_mode(&mode);
		if(mode == USE_RECENT)
			mode = persent_mode;	//如果输入模式不是US和METRIC，使用默认值
		persent_mode = 	mode; //记住上次的值，作为默认值
		
		get_info(mode,&distance,&fuel);
		show_info(mode,distance,fuel);
		printf("Enter 0 for metric mode, 1 for US mode: ");
		printf("(-1 to quit): ");
		scanf("%d",&mode);
		while(getchar()!= '\n');
	
	}
	printf("Done.\n");
	return 0;
}

