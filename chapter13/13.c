#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS	20
#define COLS 	30
#define LEVELS 	30
const char trans[LEVELS + 1] = " .':~*=&%@";
void init(char arr[][COLS], char ch);
void show_file(FILE *fp);
void Eliminate(int  data[][COLS]);
void MakePic(int data[][COLS],
 						 char pic[][COLS], 
 						 int rows, FILE *fp);



int main(void)
{
	int row,col;
	int pic_IN[ROWS][COLS];
	char pic_OUT[ROWS][COLS];
	char FileName[40];
	FILE *fp_in;
	FILE *fp_out;
	
//init pic_OUT	
	init(pic_OUT, 'S');
	
	printf("Enter name of file:\n");
	gets(FileName);
// open file 
	if((fp_in = fopen(FileName,"r")) == NULL)
		{
			printf("Can't open file %s",FileName);
			exit(1);
		}
// read data from file to pic_IN		
	for(row=0; row<ROWS; row++)	
		for(col=0; col<COLS; col++)	
			fscanf(fp_in,"%d",&pic_IN[row][col]);
			
	if(ferror(fp_in))
		{
			printf("Error getting data from file %s",FileName);
			exit(2);
		}
		
// Eliminate pulse
	Eliminate(pic_IN);
	
	
// open (create) picture file	
	strcat(FileName,".Cpic");	
	if((fp_out = fopen(FileName,"w")) == NULL)
		{
			printf("Can't open file %s",FileName);
			exit(1);
		}
		
// Character conversion	
	MakePic(pic_IN, pic_OUT, ROWS, fp_out);		
	if(ferror(fp_out))
		{
			printf("Error writing data to file %s",FileName);
			exit(2);
		}	
		
// close file and open with read mode 		
	fclose(fp_out);
	if((fp_out = fopen(FileName,"r")) == NULL)
		{
			printf("Can't open file %s",FileName);
			exit(1);
		}
				
//show picture file 
	printf("The picture from file %s as follows:\n",FileName);	
	show_file(fp_out);
	
// close file 
	if(fclose(fp_in) != 0 || fclose(fp_out) != 0)	
		fprintf(stderr,"Error closing file\n");	
		
 return 0;
}

void init(char arr[][COLS], char ch)
{
	int r,c;
	for(r=0; r<ROWS; r++)
		for(c=0; c<COLS; c++)
			arr[r][c] = ch;
}			

void MakePic(int data[][COLS], 
						 char pic[][COLS], 
						 int rows, FILE *fp)
{
	int row, col;
	for(row=0; row<rows; row++)
		{
			for(col=0 ;col<COLS; col++)
			{
				pic[row][col] = trans[data[row][col]];	
				putc(pic[row][col], fp);	
			}	
			putc('\n', fp);
		}	
}

void show_file(FILE *fp)
{
	char ch;
	while((ch = getc(fp)) != EOF)
		putc(ch, stdout);
	
}

void Eliminate(int  data[][COLS])
{
	int row, col;
	for(row=0; row<ROWS; row++)
		{
			for(col=0 ;col<COLS; col++)
			{
					if(row==0&&col==0)
			   {
			    if(   (data[row][col] - data[row][col+1])>1 && (data[row][col] - data[row+1][col])>1  )
			     data[row][col] = ( data[row][col+1] + data[row+1][col] ) / 2 + 0.5;//加0.5是为了四舍五入
			   }
			   else if(row==0&&col==29)
			   {
			    if(   (data[row][col] - data[row][col-1])>1 && (data[row][col] - data[row+1][col])>1  )
			     data[row][col] = ( data[row][col-1] + data[row+1][col] ) / 2 + 0.5;
			   }
			   else if(row==19&&col==0)
			   {
			    if(   (data[row][col] - data[row-1][col])>1 && (data[row][col] - data[row][col+1])>1  )
			     data[row][col] = ( data[row-1][col] + data[row][col+1] ) / 2 + 0.5;
			   }
			   else if(row==19&&col==29)
			   {
			    if(   (data[row][col] - data[row-1][col])>1 && (data[row][col] - data[row][col-1])>1  )
			     data[row][col] = ( data[row-1][col] + data[row][col-1] ) / 2 + 0.5;
			   }
			   else if(row==0)
			   {
			    if(   (data[row][col] - data[row][col-1])>1 && (data[row][col] - data[row+1][col])>1  && (data[row][col] - data[row][col+1])>1  )
			     data[row][col] = ( data[row][col-1] + data[row+1][col] + data[row][col+1]) / 3 + 0.5;
			   }
			   else if(col==0)
			   {
			    if(   (data[row][col] - data[row-1][col])>1 && (data[row][col] - data[row+1][col])>1  && (data[row][col] - data[row][col+1])>1  )
			     data[row][col] = ( data[row-1][col] + data[row+1][col] + data[row][col+1]) / 3 + 0.5;
			   }
			   else if(row==19)
			   {
			    if(   (data[row][col] - data[row-1][col])>1 && (data[row][col] - data[row][col-1])>1  && (data[row][col] - data[row][col+1])>1  )
			     data[row][col] = ( data[row-1][col] + data[row][col-1] + data[row][col+1]) / 3 + 0.5;
			   }
			   else if(col==29)
			   {
			    if(   (data[row][col] - data[row-1][col])>1 && (data[row][col] - data[row+1][col])>1  && (data[row][col] - data[row][col-1])>1  )
			     data[row][col] = ( data[row-1][col] + data[row+1][col] + data[row][col-1]) / 3 + 0.5;
			   }
			   else
			   {
			    if(   (data[row][col] - data[row-1][col])>1 && (data[row][col] - data[row+1][col])>1  && (data[row][col] - data[row][col-1])>1  && (data[row][col] - data[row][col+1])>1  )
			     data[row][col] = ( data[row-1][col] + data[row+1][col] + data[row][col-1]) + data[row][col+1]/ 4 + 0.5;
			   }

					
			}	
			
		}	
	
	
	
}
