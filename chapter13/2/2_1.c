#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE	1024

int main(int argc, char *argv[])
{
	int byte;
	FILE *source;
	FILE *target;
	char temp[BUFSIZE];
	
	if(argc != 3)
		{
			printf("Usage: %s sourcefile targetfile\n",argv[0]);	
			exit(1);
		}
	if((source = fopen(argv[1],"rb")) == NULL)
		{
			printf("Could not open file %s for input\n",argv[1]);	
			exit(EXIT_FAILURE);
		}
	if((target = fopen(argv[2],"wb")) == NULL)
		{
			printf("Could not open file %s for output\n",argv[2]);	
			exit(EXIT_FAILURE);
		}

	while((byte = fread(temp, sizeof(char),1,source)) > 0)
		{
			fwrite(temp, sizeof(char),1,target);
			
		}
		
	if(ferror(source) != 0)	
		fprintf(stderr,"Error in reading file %s",argv[1]);
	if(ferror(target) != 0)	
		fprintf(stderr,"Error in writing file %s",argv[2]);	
		
	if(fclose(source) != 0)
		printf("Could not close file %s\n",argv[1]);
	if(fclose(target) != 0)
		printf("Could not close file %s\n",argv[2]);
				
				
	return 0;
}

