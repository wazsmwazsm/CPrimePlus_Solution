#include <stdio.h>
#include <stdlib.h>
#define SIZE	100


int main(int argc, char *argv[])
{
	FILE *f1,*f2;
	char str1[SIZE], str2[SIZE];
	if(argc != 3)
		{
			printf("Usage: %s file1 file2\n",argv[0]);
			exit(EXIT_FAILURE);
		}
	if((f1 = fopen(argv[1],"r")) == NULL)
		{
			printf("Could not open file %s for input\n",argv[1]);
			exit(1);
		}
	if((f2 = fopen(argv[2],"r")) == NULL)
		{
			printf("Could not open file %s for input\n",argv[2]);
			exit(1);
		}
	
	while((fscanf(f1,"%s",str1) == 1) && (fscanf(f2,"%s",str2) == 1))
		{
			puts(str1);
			puts(str2);
		}
	if(fclose(f1) != 0)
		printf("Can not close file %s",argv[1]);
	if(fclose(f2) != 0)
		printf("Can not close file %s",argv[2]);
		
 return 0;
}