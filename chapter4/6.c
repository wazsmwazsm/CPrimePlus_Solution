#include <stdio.h>
#include <float.h>

int main(void)
{
	double a = 1.0/3.0;
	float b = 1.0/3.0;
		
	printf("double a=1.0/3.0:\n");
	printf("%.4e\n",a);
	printf(".12e\n",a);
	printf(".16e\n",a);
	
	printf("float b=1.0/3.0:\n");
	printf("%.4f\n",b);
	printf(".12f\n",b);
	printf(".16f\n",b);
	
	printf("FLT_DIG:%d\n",FLT_DIG);
	printf("DBL_DIG:%d\n",DBL_DIG);

	return 0;
	
}