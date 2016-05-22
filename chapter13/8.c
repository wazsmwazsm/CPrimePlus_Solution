#include <stdio.h>
#include <stdlib.h>
int count(char ch, FILE *fp);


int main(int argc, char * argv[])
{
	int i;
	char ch;
	FILE *fp;
	
	if(argc < 2)
		{
			printf("Usage: character %s\n",argv[0]);
			exit(EXIT_FAILURE);
		}
	
	ch = argv[1][0];
	if(argc == 2)	
		{
			printf("Input a article:");
			printf("In your input : %c has been appeard %d times.\n",ch,count(ch,stdin));
		}
	else
		{
			for(i=2; i<argc; i++)
				{
					if((fp = fopen(argv[i],"r")) == NULL)
						printf("Can't open %s\n",argv[i]);
					else 
						{
							printf("In %s : %c has been appeared %d times.\n",argv[i],ch,count(ch,fp));
							if(fclose(fp) != 0)
								printf("Can't close file %s",argv[i]);
						}
				}
		}

 return 0;
}

int count(char ch, FILE *fp)
{
	int n = 0;
	char ch_get;	
	while((ch_get = getc(fp)) != EOF)
		if(ch == ch_get)
			n++;
			
	return n;
	
}

