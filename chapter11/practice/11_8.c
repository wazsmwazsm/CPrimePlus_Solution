#include <stdio.h>
#define DEF "I am a #define string."
int main(void)
{
	char str1[90] = "An array was initialized to me.";
	const char * str2 = "A pointer was initalized to me.";
	
	puts("I'm an argument to puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2+4);
	
	return 0;
}
