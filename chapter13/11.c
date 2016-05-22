#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX	100



int main(int argc, char *argv[])
{
	char str[MAX];
	FILE *fp;
	
	if(argc != 3)
		{
			printf("Usage: %s string file\n",argv[0]);
			exit(EXIT_FAILURE);
		}
	if((fp = fopen(argv[2],"r")) == NULL)
		{
			printf("Can't open file %s", argv[2]);
			exit(1);
		}
	
	while(fgets(str,MAX - 1,fp) != NULL)
		if(strstr(str, argv[1]) != NULL)
			puts(str);

	if(fclose(fp) != 0)	
		fprintf(stderr,"Error closing file\n");

 return 0;
}