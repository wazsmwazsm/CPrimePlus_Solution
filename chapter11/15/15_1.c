#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	
	char ch;
	
	if(argc > 2)
		{
			printf("Usage: %s [ -p | -u | -l ]\n",argv[0]);
			
		}
	else if (argc == 2)
		{
			if(argv[1][0] != '-')
				{
					printf("Usage: %s [ -p | -u | -l ]\n",argv[0]);
								
				}
			else
				switch(argv[1][1])
				{
					case 'p': while((ch = getchar()) != EOF) putchar(ch);
										break;
					case 'u': while((ch = getchar()) != EOF) putchar(toupper(ch));
										break;
					case 'l': while((ch = getchar()) != EOF) putchar(tolower(ch));
										break;
					default: 	printf("%s is an invalid flag;",argv[1]);
										printf("using default flag (-p).\n");
										while((ch = getchar()) != EOF) putchar(ch);
										break;
					
				}
		}
	else
		printf("Usage: %s [ -p | -u | -l ]\n",argv[0]);
	return 0;
}
