
/*the Program conversion your age into second*/
#include <stdio.h>

int main(void)
{	
	int ageyear;
	double age;
	printf("Please input you age :__\b\b");
	scanf(" %d",&ageyear);
	age = (double)ageyear * 3.156E7 ;														//Conversion years and seconds
	printf("\n Oh! You on earth live for %f seconds !\n",age);
	printf("\n Or say %e seconds !\n",age);

return 0;	
}