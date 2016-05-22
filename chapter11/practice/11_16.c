#include <stdio.h>
#define ANSWER "Grant"
int main(void)
{
	char try[40];
	
	puts("Who is buried in Grant's tomb?");
	
	gets(try);
	while(try != ANSWER)			// try 和 ANSWER 是指针， 不能用来判断字符串是不是相等, 要用strcmp
	{
		puts("No, that's wrong. Try again.");
		gets(try);
		
	}
	puts("That's right!");
	
	
	return 0;
}
