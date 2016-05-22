#include <stdio.h>
#include <stdlib.h>
#define SIZE 80

int main(void)
{
	int ch;
	FILE *fp;
	long count = 0;
	char name[SIZE];
	
	printf("Enter the file name:\n");
	
	gets(name);
	
	if((fp = fopen(name,"r")) == NULL)
		{
			
			printf("Can't open %s\n",name);
			exit(1);
		}
		
	while((ch = getc(fp)) != EOF)
		{
			putc(ch,stdout);
			count ++;			
		}
	fclose(fp);
	printf("File %s has %ld characters\n",name,count);
	
	
	return 0;
}

