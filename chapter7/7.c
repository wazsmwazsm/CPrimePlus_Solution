/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>

#define BASEPAY    10      // $10 per hours
#define BASEHOURS  40			 // hours at basepay
#define OVERTIME   1.5		 // over basepay 1.5 time
#define LIMITE1  	 300		 // first 300 dollor
#define LIMITE2  	 150		 // the next 150 dollor
#define RATE1      0.15		 // first 300 dollor rate
#define RATE2      0.20		 // the next 150 dollor rate
#define RATE3      0.25    // others rate


int main(void)
{
	double hours;
  double gross;
  double net;
  double taxes;

	printf("Please enter the number of hours worked this week:");
	scanf("%lf",&hours);
	
	if(hours <= BASEHOURS)
				gross = BASEPAY * hours;
	else 
				gross = BASEPAY * BASEHOURS + (hours - BASEHOURS)*BASEPAY*OVERTIME;
	if(gross <= LIMITE1)
				taxes = gross * RATE1;
	else if(gross<= LIMITE1 + LIMITE2)
				taxes = LIMITE1 * RATE1 + (gross - LIMITE1)*RATE2;
  else 
  			taxes = LIMITE1 * RATE1 + LIMITE2 * RATE2 + (gross - LIMITE1 - LIMITE2) * RATE3;
	
	net = gross - taxes;
	
	printf("%.2f hours you can earn : \n gross: %.2f \n net: %.2f \n taxes: %.2f \n",hours,gross,net,taxes);		
				
				
return 0;
}