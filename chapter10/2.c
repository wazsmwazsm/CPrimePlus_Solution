#include <stdio.h>
void copy_arr(double const [], double [], int );
void copy_ptr(const double *, double *, int );

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5] = {0};
	double target2[5] = {0};
	int i;
	
	printf("Before operation:\n");
	printf("%12s%12s%12s\n","source","target1","target2");
	for(i=0;i<5;i++)
		{
			printf("%12g",source[i]);
			printf("%12g",target1[i]);
			printf("%12g",target2[i]);
			printf("\n");
		}
	copy_arr(source, target1, 5);
	copy_ptr(source, target2, 5);
	
	printf("\nAfter operation:\n");
	printf("%12s%12s%12s\n","source","target1","target2");
	for(i=0;i<5;i++)
		{
			printf("%12g",source[i]);
			printf("%12g",target1[i]);
			printf("%12g",target2[i]);
			printf("\n");
		}	
	
	return 0;
}

/*
	name: copy_arr
	function: Copy array data from ar[] to tr[]
*/
void copy_arr(double const ar[], double  tr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		tr[i] = ar[i];	
}

/*
	name: copy_arr
	function: Copy array data from pa to pt
*/
void copy_ptr(const double *pa, double *pt, int n)
{
	int i;
	for(i=0;i<n;i++)
		*(pt+i) = *(pa+i);	
}
