/*
function : cm,inch,feet 
*/

#include <stdio.h>
#define INCH 2.54

int main(void)
{
	float cm,inch;
	int feet;
	printf("Enter a height in centimeters: ");
	scanf(" %f",&cm);
	
	while(cm > 0)
	{
	feet = (int)(cm/INCH/12);
	inch = cm/INCH-(int)(cm/INCH/12)*12;
	printf("%.1f cm = %d feet, %.1f inches\n",cm,feet,inch);
	printf("Enter a height in centimeters(<=0 to quit):");
	scanf(" %f",&cm);
	}
	printf("bye\n");
	
	
return 0;
	
}
