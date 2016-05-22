
#include <stdio.h>

int main(void)
{
		double Daphne=100,Deirdre=100;		
		int i=0;
		
		while(Daphne >= Deirdre)
		{
			Daphne += 100*0.1;
			Deirdre += Deirdre*0.05;
			i++;
		}
		
		printf("After %d years,Deirdre's investment is %lf,Deirdre's investment is %lf\n",i,Deirdre,Daphne);
		
return 0;
	
}