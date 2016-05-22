#include <stdio.h>
#define ROWS 3
#define COLS 5
void copy(int rows, int cols, double source[rows][cols], double target[rows][cols]);
void display(int rows, int cols, double ar[rows][cols]);
int main(void)
{
	int rows=3;
	int cols=5;
	double source[ROWS][COLS] = { 
		 {1.1, 2.2, 3.3, 4.4, 5.5},
     {6.6, 7.7, 8.8, 9.9, 10.10},
     {11.11, 12.12, 13.13, 14.14, 15.15} };			// 这里要注意一个点，变长数组不可以赋值
	double target[ROWS][COLS] = {0};							//不过可以作为函数参数和目标参数来声明

    	
	double target_vla[rows][cols];
	
	copy(ROWS,COLS,source,target);
	printf("source\n");
	display(ROWS,COLS,source);
	printf("target\n");
	display(ROWS,COLS,target);

	copy(rows,cols,source,target_vla);
	printf("source\n");
	display(rows,cols,source);
	printf("target_vla\n");
	display(rows,cols,target_vla);
		
	return 0;
}

void copy(int rows, int cols, double source[rows][cols], double target[rows][cols])
{
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			target[i][j] = source[i][j];
			
}
void display(int rows, int cols, double ar[rows][cols])
{
		int i,j;
	for(i=0;i<rows;i++)
		{
			for(j=0;j<cols;j++)
			   printf("%g\t",ar[i][j]);
			printf("\n");
		}
}
