/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
#include <ctype.h>

#define BASEHOURS  40			 // hours at basepay
#define OVERTIME   1.5		 // over basepay 1.5 time
#define LIMITE1  	 300		 // first 300 dollor
#define LIMITE2  	 150		 // the next 150 dollor
#define RATE1      0.15		 // first 300 dollor rate
#define RATE2      0.20		 // the next 150 dollor rate
#define RATE3      0.25    // others rate
#define STARS      "****************************************"
#define QUIT       'q'

char menu(void);
double get_hours(void);
char get_first(void);

int main(void)
{
	double basepay;
	double hours;
  double gross;
  double net;
  double taxes;
	
	char choice;

	
	while((choice = menu()) != QUIT )
	{
		switch (choice)
		{
			case 'a': basepay = 8.75;
				break;
			case 'b': basepay = 9.33;
				break;
			case 'c': basepay = 10.00;
				break;			
			case 'd': basepay = 11.20;
				break;			
			default:
				printf("Please enter a, b, c, d, or q.\n");
				continue;
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
char menu(void)
{
	
	char ch;
	printf("\n%s%s\n",STARS,STARS);
	printf("Enter the number corresponding to the desired pay rate pr action:\n");
	printf("a) $8.75/hr\t\t\tb)$9.33/hr\n");
	printf("c) $10.00/hr\t\t\td)$11.20/hr\n");
	printf("q) quit \n");
	printf("\n%s%s\n",STARS,STARS);
	
	ch = get_first();
	
	return ch ;
	
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
		
	return hours ;
}

char get_first(void)
{
	char ch;
	
	while(isspace(ch = getchar()));
	while(getchar() != '\n');
	return ch;
}
