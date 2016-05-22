/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
#include <ctype.h>

#define DISCOUNT_RATE  0.05

int main(void)
{
	
	const double price_artichokes = 1.25 ;
	const double price_beets = 0.65 ;
	const double price_carrots = 0.89 ;
	
	char ch;
	
	double Pounds_artichokes ;
	double Pounds_beets ;
	double Pounds_carrots ;
	double Pounds_total ;
	
	double Cost_artichokes ;
	double Cost_beets ;
	double Cost_carrots ;
	double Cost_total ;
	
	double Final_total ;
	double discount;
	double shipping ;
	
	printf("Enter a to buy artichokes, b for beets , c for carrots, q to quit: ");
	while((ch = tolower(getchar()))!= 'q')
		{
			if(ch == '\n')					//first ch is '\n'
					continue;
			while(getchar()!= '\n') //expend a '\n'
					continue;
			
			switch(ch)
			{
				case 'a' :	printf("Enter pounds of artichokes:");
										scanf("%lf",&Pounds_artichokes);
										break;
				case 'b' :	printf("Enter pounds of beets:");
										scanf("%lf",&Pounds_beets);
										break;			
				case 'c' :	printf("Enter pounds of carrots:");
										scanf("%lf",&Pounds_carrots);
										break;			
				default:    printf("%c is not a valid choice.\n",ch);
					break;				
			}	
		printf("Enter a to buy artichokes, b for beets , c for carrots, q to quit: ");			
			
		}
		Cost_artichokes = price_artichokes * Pounds_artichokes;
		Cost_beets = price_beets * Pounds_beets;
  	Cost_carrots = price_carrots * Pounds_carrots;
  	Cost_total = Cost_artichokes + Cost_beets + Cost_carrots;
		Pounds_total = Pounds_artichokes + Pounds_beets + Pounds_carrots;
		
		if(Pounds_total <= 0)
				shipping = 1.0;
		else if(Pounds_total < 5.0)
				shipping = 3.50;
		else if(Pounds_total < 20)
				shipping = 10.0;
		else 
			  shipping = 8.0 + 0.1 * Pounds_total;
		
		if(Cost_total >= 100.0)
			discount = DISCOUNT_RATE * Cost_total;
			
		 Final_total = Cost_total + shipping - discount;
		  
	
		printf("Your order:\n");
	  printf("%.2f lbs of artichokes at $%.2f per pound:$ %.2f\n",
            Pounds_artichokes, price_artichokes, Cost_artichokes);  
	  printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
	            Pounds_beets, price_beets, Cost_beets);  
	  printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
	            Pounds_carrots, price_carrots, Cost_carrots);
	  printf("Total cost of vegetables: $%.2f\n", Cost_total);
		
		
		if(Cost_total >= 100.0)
			printf("Volume discount: $%.2f\n",discount);
		printf("Shipping: $%.2f\n",shipping);
		printf("Total charges: $%.2f\n",Final_total);
return 0;
}