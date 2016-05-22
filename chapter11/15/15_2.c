#include <stdio.h>
#include <ctype.h>
#include <string.h>
char *strupr(char * str);
char *strlwr(char * str);

int main(int argc, char *argv[])
{
	
	char ch;
	
	if(argc > 3)
		{
			printf("Usage: %s need only 1 argument.\n",argv[0]);
			
		}
	else if (argc == 1)		
			puts(argv[2]);	
	else if (argc == 2)
		{
			if(argv[1][0] == '-')
				printf("Usage: %s need at least 1 argument.\n",argv[0]);
			else
				puts(argv[1]);	
			
		}					
	else if (argc == 3)		
		{
			if(argv[1][0] != '-')
				{
					printf("Usage: %s [ -p | -u | -l ]\n",argv[0]);
								
				}
			else
				switch(argv[1][1])
				{
					case 'p': puts(argv[2]);
										break;
					case 'u': puts(strupr(argv[2]));
										break;
					case 'l': puts(strlwr(argv[2]));
										break;
					default: 	printf("Usage: %s [ -p | -u | -l ]\n",argv[0]);									
										break;
					
				}
		}
		
	return 0;
}

char *strupr(char * str)
{
	char * orign = str;
	while(*str)
		{	
			*str = toupper(*str);
			*str++;
		}
	return orign;
}

char *strlwr(char * str)
{
	char * orign = str;
	while(*str)
		{	
			*str = tolower(*str);
			*str++;
		}
	return orign;
}