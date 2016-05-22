#include <stdio.h>
#include <math.h>
#define LEN	10

void transform(double *source, double *target, int n , double (*fp)(double));
double reciprocal(double x);
double negative(double x);

int main(void)
{
	double source[LEN], target[LEN];
	int i;
	for(i=0; i<LEN; i++)
		source[i] = i;
		
	puts("sin:");	
	transform(source,target,LEN,sin);	
	for(i=0; i<LEN; i++)
		printf("%g -> %g\n",source[i], target[i]);
		
	puts("\nexp:");	
	transform(source,target,LEN,exp);	
	for(i=0; i<LEN; i++)
		printf("%g -> %g\n",source[i], target[i]);	
		
	puts("\nreciprocal:");	
	transform(source,target,LEN,reciprocal);	
	for(i=0; i<LEN; i++)
		printf("%g -> %g\n",source[i], target[i]);
		
	puts("\nnegative:");	
	transform(source,target,LEN,negative);	
	for(i=0; i<LEN; i++)
		printf("%g -> %g\n",source[i], target[i]);	
	return 0;
}

void transform(double *source, double *target, int n , double (*fp)(double))
{
	int i;
	for(i = 0; i < n; i++)
		target[i] = (*fp)(source[i]);
}

double reciprocal(double x)
{
	
	return 1/x;
}
double negative(double x)
{
return -x;	
}
