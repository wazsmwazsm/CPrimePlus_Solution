#include <stdio.h>
#include <string.h>
#define ROWS  3
#define COLS  5
void twice(int (*ar)[COLS], int n);
void display(int (*ar)[COLS], int n);

int main(void)
{
	int array[ROWS][COLS] = {
	{1,2,3,4,5},	
	{7,8,9,0,5},	
	{5,7,3,9,3}		
	};
	puts("Before");
	display(array,ROWS);
	
	twice(array,ROWS);
	
	puts("\nAfter");
	display(array,ROWS);
	
	
	return 0;
}
void twice(int (*ar)[COLS], int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<COLS;j++)
				ar[i][j] *= 2;
}
void display(int (*ar)[COLS], int n)
{
	int i,j;
	for(i=0;i<n;i++)
		{
			for(j=0;j<COLS;j++)
				printf("%d\t",ar[i][j]) ;
			printf("\n");
		}
}

