/*
* function£ºprint out 
*
*										F
*										FE
*										FED
*										FEDC
*										FEDCB
*										FEDCBA
*
*/
#include <stdio.h>
#define ONE
int main(void)
{
	int col,row;
#ifdef 	ONE
	for(row=0; row<6; row++)
		{
			for(col=0; col<=row; col++)
			{
				printf("%c",'F'-col);
			}
			printf("\n");
		}
#else 

	char lets[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(row=0; row<6; row++)
		{
			for(col=0; col<=row; col++)
			{
				printf("%c",lets[5-col]);
			}
			printf("\n");
		}
#endif
	
return 0;
	
}

