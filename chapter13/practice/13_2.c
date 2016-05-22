#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;
// check parameter	
	if(argc < 2)
		{
			fprintf(stderr,"Usage: %s filename.\n",argv[0]);
			exit(1);			
		}
// open source file , read mode
	if((in = fopen(argv[1],"r")) == NULL)	
		{
			fprintf(stderr,"I couldn't open the file \"%s\".\n",argv[1]);
			exit(2);
		}
// add file name	
	strcpy(name, argv[1]);	
	strcat(name, ".red");
// open target file , write mode	
	if((out = fopen(name,"w")) == NULL)
		{
			fprintf(stderr,"Can't create output file.\n");
			exit(3);			
		}
// copy data
	while((ch = getc(in)) != EOF)
		if(count ++ % 3 == 0)
			putc(ch,out);
// close file		
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr,"Error in closing files.\n");

	return 0;
}

