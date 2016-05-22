#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE	81

int main(void)
{
	FILE *source, *target;
	int ch;
	char source_name[SIZE], target_name[SIZE];
	
	printf("Enter source name:\n");
	
	if((source = fopen(gets(source_name),"r")) == NULL)
		{
			fprintf(stderr,"Can't open file %s\n",source_name);
			exit(1);
		}
	
	printf("Enter target name:\n");
	
	if((target = fopen(gets(target_name),"w")) == NULL)
		{
			fprintf(stderr,"Can't open file %s\n",target_name);
			exit(1);
		}
	
	while((ch = getc(source)) != EOF)
		putc(toupper(ch),target);
	
	if(fclose(source) != 0)
		printf("Can't close file %s",source_name);
	if(fclose(target) != 0)
		printf("Can't close file %s",target_name);	
		
		
 return 0;
}