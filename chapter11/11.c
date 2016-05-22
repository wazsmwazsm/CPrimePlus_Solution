#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(void)
{
	int word = 0;
	int upper = 0;
	int lower = 0;
	int punct = 0;
	int digit = 0;
	int begin = 0;
	bool inword = false;
	char ch;
	
	puts("Enter text to be analyzed (EOF to terminate):");
	while((ch = getchar()) != EOF)
		{
			if(islower(ch))
				lower++;
			else if(isupper(ch))
				upper++;
			else if(isdigit(ch))
				digit++;
			else if(ispunct(ch))	
				punct++;
				
			if(!isspace(ch) && !inword)
				{
					word++;
					inword = true;
				}
			if(isspace(ch) && inword)
				inword = false;
			
			
		}
		printf("\n word = %d, lower = %d, upper = %d, "
					 "digits = %d, punct = %d\n",
					 word, lower, upper, digit, punct);
	
	return 0;
}
