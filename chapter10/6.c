#include <stdio.h>
#define ROWS 2
#define COLS 3
void copy_1d(double [], double [], int );
void copy_2d(double [][COLS],  double [][COLS], int );

int main(void)
{
	int i,j;
	double source[ROWS][COLS] = {1,2,3,4,5,6};
	double target[ROWS][COLS] = {0};
	
	copy_2d(source,target,ROWS);
	
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
			printf("%g\t",target[i][j]);
		printf("\n");		
	}
	
	return 0;
}
// double (* source)[COLS]
void copy_2d(double source[][COLS], double target[][COLS], int n)
{
	int i;
	for(i=0; i<n; i++)
		copy_1d(source[i], target[i], COLS); // *(source + i)
}

void copy_1d(double ar[], double tr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		tr[i] = ar[i];	
}
