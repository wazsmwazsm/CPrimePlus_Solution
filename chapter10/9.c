#include <stdio.h>
#define WIDTH	5
void add(double *, double *, double *, int );

int main(void)
{
	int i;
	double source1[WIDTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double source2[WIDTH] = {6.6, 7.7, 8.8, 9.9, 10.10};
	double target[WIDTH] = {0};
	
	add(source1, source2, target, WIDTH);
	
	printf("target:\n");
	for(i=0;i<WIDTH;i++)
		printf("\t%g",target[i]);
		
	printf("\n");	
	
	return 0;
}

void add(double *source1, double *source2, double *target, int n)
{
	int i;
	for(i=0;i<n;i++)
		target[i] = source1[i] + source2[i];
		
}


