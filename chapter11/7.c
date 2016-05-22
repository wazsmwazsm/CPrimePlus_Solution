#include <stdio.h>
#include <string.h>
#define LEN 80
char * string_in(const char * , const char * );

int main(void)
{
	char orig[LEN];
	char target[LEN];
	char *find;
	puts("Enter a string:");
	gets(orig);
	puts("Enter the target string:");
	gets(target);
	
	find = string_in(orig, target);
	if(find)
		{
			puts("I find it :");
			puts(find);
		}
	else
		puts("Not find.");
		
	puts("Done.");
	return 0;
}
char * string_in(const char * s1, const char * s2)
{
	int l2 = strlen(s2);
	int tries;
	int nomatch = 1;
	tries = strlen(s1) + 1 - l2;
	if(tries > 0)
		while((nomatch = strncmp(s1,s2,l2)) && tries--)
			s1++;
	if(nomatch)		
			return NULL;
	else
			return (char *) s1;
}

