#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMITE 80
void ToUpper(char *str);
int PunctCount(const char *str);

int main(void)
{
	char line[LIMITE];
	puts("Please enter a line. ");
	gets(line);
	ToUpper(line);
	puts(line);
	printf("That line has %d punctuation characters.\n",
					PunctCount(line));

	return 0;
}
void ToUpper(char *str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}	
}

int PunctCount(const char *str)
{
		int ct = 0;
		while(*str)
		{
			if(ispunct(*str))
				ct ++;
			str++;
		}
	return ct;	
}

