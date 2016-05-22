
#include <stdio.h>
#include <math.h>
int main(void)
{
	int num[8],i;
	for(i=0;i<8;i++)
		num[i] = pow(2,i);
	i=0;	
	do 
		printf("%d\t",num[i]);
	while(++i<8);
	
	printf("\n");
	
return 0;
	
}