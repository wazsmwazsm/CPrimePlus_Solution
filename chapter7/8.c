/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>


#define BASEHOURS  40			 // hours at basepay
#define OVERTIME   1.5		 // over basepay 1.5 time
#define LIMITE1  	 300		 // first 300 dollor
#define LIMITE2  	 150		 // the next 150 dollor
#define RATE1      0.15		 // first 300 dollor rate
#define RATE2      0.20		 // the next 150 dollor rate
#define RATE3      0.25    // others rate
#define STARS      "****************************************"
#define QUIT       5

int menu(void);
double get_hours(void);

int main(void)
{
	double basepay;
	double hours;
  double gross;
  double net;
  double taxes;
	
	int num;

	
	while(num = menu() != QUIT )
	{
		switch (num)
		{
			case 1: basepay = 8.75;
				break;
			case 2: basepay = 9.33;
				break;
			case 3: basepay = 10.00;
				break;			
			case 4: basepay = 11.20;
				break;			
			default:
				break;
		}
		printf("you have select $%.2f/hr\n",basepay);
		
		hours = get_hours();
			
		if(hours <= BASEHOURS)
					gross = basepay * hours;
		else 
					gross = basepay * BASEHOURS + (hours - BASEHOURS)*basepay*OVERTIME;
		if(gross <= LIMITE1)
					taxes = gross * RATE1;
		else if(gross<= LIMITE1 + LIMITE2)
					taxes = LIMITE1 * RATE1 + (gross - LIMITE1)*RATE2;
	  else 
	  			taxes = LIMITE1 * RATE1 + LIMITE2 * RATE2 + (gross - LIMITE1 - LIMITE2) * RATE3;
		
		net = gross - taxes;
		
		printf("%.2f hours you can earn : \n gross: %.2f \n net: %.2f \n taxes: %.2f \n",hours,gross,net,taxes);		


	}
			
return 0;
}
int menu(void)
{
	int num,status;
	
	printf("\n%s%s\n",STARS,STARS);
	printf("Enter the number corresponding to the desired pay rate pr action:\n");
	printf("1) $8.75/hr\t\t\t2)$9.33/hr\n");
	printf("3) $10.00/hr\t\t\t4)$11.20/hr\n");
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

double get_hours(void)
{
	double hours;
	
	printf("input the work hours of a week:");
	while(scanf("%lf",&hours) != 1)
		{
			scanf("%*s");
			printf("Please enter an valid numbler !\n");
		}
	while(getchar()!= '\n');
	return hours ;
}