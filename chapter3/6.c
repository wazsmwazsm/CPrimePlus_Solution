/*this program can calculater how many water molecule in one quart water*/

#include <stdio.h>

//define some Constant for Calculation
#define water_molecule  3.156e-7
#define quart_to_gram   950

int main(void)
{	
	int quart;
	double gram_per_quart;
	
	printf("Please input water quart  :_____\b\b\b\b\b");
	scanf(" %d",&quart);
	
	gram_per_quart = ((double)quart * quart_to_gram) / water_molecule ;		/* Convert Formula */
	
	printf("\n %d quart contain %f gram water molecule !\n", quart, gram_per_quart);	
	printf("\n Or say %e gram water molecule !\n",gram_per_quart);
	
return 0;	
}