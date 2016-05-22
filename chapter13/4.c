#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
	int ch;
	FILE *source;
	int i;
	
	if(argc == 1)	
		{
			printf("Usage: %s filename\n",argv[0]);
			exit(EXIT_FAILURE);
		}
	
	for(i=1; i<argc; i++)
		{
			if((source = fopen(argv[i],"r")) == NULL)
				{
					fprintf(stderr,"Can't open file %s",argv[i]);
					continue;
				}
			while((ch = getc(source)) != EOF)
				putc(ch,stdout);
			
			if(fclose(source) != 0)
				printf("Can't close file %s",argv[i]);
				
		}
	
 return 0;
}