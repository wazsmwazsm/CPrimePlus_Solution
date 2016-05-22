#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN	80

int main(void)
{
	FILE	*in, *out;
	int ch;
	char name[LEN];
	int count = 0;
	
	puts("Enter the file name to be reduce:");
	gets(name);
	if((in = fopen(name,"r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n",name);
			exit(2);
		}
		
	strcat(name,".red");
	
	if((out = fopen(name,"w")) == NULL)
		{
			fprintf(stderr, "Can't create output file %s\n",name);
			exit(3);
		}
	
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch,out);
			
	if(fclose(in) != 0 || fclose(out) != 0)		
		printf("Error in closing files.\n");
		
		
		
 return 0;
}