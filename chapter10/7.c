#include <stdio.h>

void copy_ptr(double *, double *, int );

int main(void)
{
	double source[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double target[3] = {0};
	
	printf("Before operation:\n");
	printf("source:\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n",
				source[0],source[1],source[2],source[3],
				source[4],source[5],source[6]);
	printf("target:\t%g\t%g\t%g\n",
				target[0],target[1],target[2]);
					
	copy_ptr(source+2, target, 3);
	
	printf("After operation:\n");
	printf("source:\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n",
				source[0],source[1],source[2],source[3],
				source[4],source[5],source[6]);
	printf("target:\t%g\t%g\t%g\n",
				target[0],target[1],target[2]);		
	
	
	return 0;
}

void copy_ptr(double *pa, double *pt, int n)
{
	int i;
	for(i=0;i<n;i++)
		*(pt+i) = *(pa+i);	
}


