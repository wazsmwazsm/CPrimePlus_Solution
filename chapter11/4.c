#include <stdio.h>
#define LEN 81
char * search_str(char *, char );

int main(void)
{
	char input[LEN];
	char ch;
	char * chk;
	
	puts("input string:");
	while(gets(input) && input[0] != '\0')
	{
		puts("input match char:");
		ch = getchar();
		while(getchar() != '\n');
		chk = search_str(input, ch);
		if(chk == NULL)
			puts("Can't find!");
		else
			{
				printf("Find it ,it is ");
				puts(chk);
			}
	puts("input string:");
	
	}
	return 0;
}

char * search_str(char *str, char ch)
{
	while( *str++ != '\0')
			if (*str == ch)
				return str;
					
	return NULL;

}