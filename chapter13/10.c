#include <stdio.h>
#include <stdlib.h>
#define MAX	81


int main(void)
{
	char name[MAX];
	char temp[MAX];
	long position = 0L;
	FILE *fp;
	
	printf("Enter the file name:\n");
	gets(name) ;
	
	if((fp = fopen(name,"r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n",name );
			exit(1);
		}
		
	puts("Enter teh position of the file:");	
	while(scanf(" %ld",&position) == 1)
	{
		fseek(fp,position,SEEK_SET);
		if(fgets(temp,MAX - 1,fp) != NULL)
			fputs(temp,stdout);
		
		fseek(fp,0L,SEEK_SET);
		puts("Enter teh position of the file:");	
	}	
	if(fclose(fp) != 0)	
		fprintf(stderr,"Error closing file\n");
	puts("Quit! Bye!");	
		
 return 0;
}