/*
function : input you name ,and Print out 
*/

#include <stdio.h>
void Temperatures(double temp);
int main(void)
{
	double Fahrenheit;
	printf("Please input the Fahrenheit:");
	while(scanf(" %lf",&Fahrenheit) == 1)
	{
		Temperatures(Fahrenheit);
		printf("Please input the Fahrenheit:");	
	}
	printf("end \n");
	
return 0;
	
}
void Temperatures(double temp)
{
	const double F_C1=1.8,F_C2=32.0,Kelvin_Celsius=273;
	printf("Fahrenheit = %.1f\n",temp);	
	printf("Celsius = %.1f\n",(temp - F_C2)/F_C1);	
	printf("Kelvin = %.lf\n",(temp - F_C2)/F_C1 + Kelvin_Celsius);	
}