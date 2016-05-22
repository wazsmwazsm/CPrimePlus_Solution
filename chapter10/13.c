#include <stdio.h>
#define ROWS  3
#define COLS  5
void store(int row,int col,double ar[row][col]);
void average_row(int row,int col,double ar[row][col] ,double *pa1, double *pa2,double *pa3);
double f_average_total(int row,int col,double ar[row][col]);
double f_max(int row,int col,double ar[row][col]);
void display(int row,int col,double ar[row][col]);

int main(void)
{
	int rows = 3;
	int cols = 5;
	
	double array[ROWS][COLS];
	double average1,average2,average3,average_total,max;
//enter an array
	store(rows,cols,array);
	
// calculate result	
	average_row(rows,cols,array,&average1,&average2,&average3);
	average_total = f_average_total(ROWS,COLS,array);
	max = f_max(ROWS,COLS,array);
	
// print result	
	printf("a.\nArray = \n");
	display(rows,cols,array);
	printf("b.\naverage1 = %g\n",average1);
 	printf("average2 = %g\n",average2);
 	printf("average3 = %g\n",average3);
	printf("c.\ntotal average = %g\n",average_total);
	printf("max = %g\n",max);
	
	return 0;
}


/*  
	name: store 
	function: Enter an array
*/
void store(int row,int col,double ar[row][col])
{
	int i,j;
	printf("Please input 3 rows numbers, 5 number per rows:");
	printf("(Only one input at a time)\n");
	for(i=0; i<row; i++)
		{
			printf("No %d line:\n",i+1);
			for(j=0; j<col; j++)
					{
						while(!scanf("%lf",&ar[i][j]))
								{
									printf("Please input a float not a char\n");
									continue;
								}
					
						while(getchar()!='\n');
					}
		}
}


/*  
	name: average_row 
	function: Find the average of each row
*/
void average_row(int row,int col,double ar[row][col] , double *pa1, double *pa2,double *pa3)
{
	  int j;
	  for(j=0,*pa1=0;j<col;j++)
				*pa1 += ar[0][j] ;
		*pa1 /= col;
		
	  for(j=0,*pa2=0;j<col;j++)
				*pa2 += ar[1][j] ;
		*pa2 /= col;
			
	  for(j=0,*pa3=0;j<col;j++)
				*pa3 += ar[2][j] ;
		*pa3 /= col;
}


/*  
	name: f_average_total 
	function: calculate the total average of an array
*/
double f_average_total(int row,int col,double ar[row][col])
{
	int i,j;
	double average = 0;
	for(i=0;i<row;i++)		
			for(j=0;j<col;j++)
				average += ar[i][j];
		
	average /= row * COLS;
	
	return  average;
}


/*  
	name: f_max 
	function: find the max of an array
*/
double f_max(int row,int col,double ar[row][col])
{
	int i,j;
	double max = ar[0][0];
	for(i=0;i<row;i++)		
			for(j=0;j<col;j++)
					if(max < ar[i][j])
						max = ar[i][j];	
	return  max;	
}


/*  
	name: display 
	function: display an array
*/
void display(int row,int col,double ar[row][col])
{
	int i,j;
	 
	for(i=0;i<row;i++)		
		{
			for(j=0;j<col;j++)
				printf("%g\t",ar[i][j]) ;	
			printf("\n");
		}
}

