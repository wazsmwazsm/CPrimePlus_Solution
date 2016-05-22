#include <stdio.h>
#define LEN 90
int is_within(const char * str, char ch);

int main(void)
{
	char input[LEN];
	char ch;
	int found;
	
	puts("Enter a strings:");
	while(gets(input) && input[0] != '\0')
	{
		puts("Enter a character: ");
		ch = getchar();
		while(getchar() != '\n');
		
		found = is_within(input, ch);
		if(found == 0)
			printf("%c not found in string.\n",ch);
		else
			printf("%c found in string.\n",ch);	
			
		puts("Enter a strings:");
	}
	puts("Done.");
	
	return 0;
}
int is_within(const char * str, char ch)
{
	while(*str != ch && *str != '\0')
		str++;
	return *str;	
}
/* orther way...

int is_within(const char * str, char ch)
{
	while(*str++ != '\0' )
		if(*str == ch)
			return *str;
	return 0;	
}
*/