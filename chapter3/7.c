/* This program just mock you baby , What's wrong?  */
#include <stdio.h>

int main(void)
{	
	float hight,inch;
	printf("\n Please input your hight  :_____cm\b\b\b\b\b\b\b");
	scanf(" %f",&hight);
	
	if( hight > 300 )
		{
			printf("\n Are you serious ?You are not human guys! \n\n");
		}
	else if( (0 < hight) && (hight <= 30) )
		{
				printf("\n come on! Babies are higher than you guys!! \n\n");
		}
	else if( hight <= 0)
		{
			printf("\n Hey! Please do not insult my intelligence! \n\n");
		}
	else
		{
			inch = hight / 2.54 ;
			printf("\n Your height %.2f cm or %.2f inch  \n\n",hight,inch);
		}
					
return 0;	
}	

