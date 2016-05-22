/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>

#define  SINGLE  					17850
#define  HOST    					23900
#define  MARRIED_SHARE    29750
#define  MARRIED_DIVORCE  23900
#define  RATE1    				0.15
#define  RATE2    				0.28
#define STARS      "****************************************"
#define QUIT       5

int menu(void);
double get_num(void);

int main(void)
{
	int num;
	double type,pay,tax;
	
	while((num = menu()) != QUIT )
	{
		switch (num)
		{
			case 1: type = SINGLE;
				break;
			case 2: type = HOST;
				break;
			case 3: type = MARRIED_SHARE;
				break;			
			case 4: type = MARRIED_DIVORCE;
				break;			
			default:
				break;
		}
		pay = get_num();
		
		if(pay <= type)
				tax = pay * RATE1;
		else 
				tax = (pay - type)*RATE2 +  type * RATE1 ;
		
		printf("wax is %.2lf\n",tax);
		
	}
	
	
	
return 0;
}

int menu(void)
{
	int num,status;
	
	printf("\n%s%s\n",STARS,STARS);
	printf("Select the type of marriage:\n");
	printf("1) Single\t\t\t2)Host\n");
	printf("3) Married share\t\t4)Married divorce\n");
	printf("5) quit \n");
	printf("\n%s%s\n",STARS,STARS);
	
	while((status = scanf("%d",&num)) != 1 ||  \
	                (num < 1 || num > 5))
	{
		if(status != 1)
			scanf("%*s");
		printf("Please enter an integer from 1 to 5!\n");
	}
	return num ;
	
}

double get_num(void)
{
	double num;
	
	printf("input the pay:");
	while(scanf("%lf",&num) != 1)
		{
			scanf("%*s");
			printf("Please enter an valid numbler !\n");
		}
	while(getchar()!='\n');
	return num ;
}