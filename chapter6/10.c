
#include <stdio.h>


int main(void)
{
	int num[8];
	int i;
	
	printf("Please input 8 numbers:");
	
	for(i=0;i<8;i++)
		scanf(" %d",&num[i]);
	for(i=7;i>0;i--)
		printf("%d",num[i]);
	
	printf("\n");
return 0;
	
}