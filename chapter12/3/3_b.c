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
			mode = persent_mode;	//�������ģʽ����US��METRIC��ʹ��Ĭ��ֵ
		persent_mode = 	mode; //��ס�ϴε�ֵ����ΪĬ��ֵ
		
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

