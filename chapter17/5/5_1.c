#include <stdio.h>
#include "stack.h"
#define SLEN 81

/* 共用了两种方法实现了栈，风别为stack和stack_2 */

int main(void)
{
	Stack stch;
	char temp[SLEN];
	int i;
	char ch;
	
	InitializeStack(&stch);
	puts("Enter a line (an empty line to quit):");
	while(gets(temp) && temp[0] != '\0')
	{
		for(i=0; temp[i] != '\0' && !StackIsFull(&stch);i++)
			PushStack(temp[i],&stch);
		
		while(!StackIsEmpty(&stch))
			{
				PopStack(&ch, &stch);
				putchar(ch);
			}
		putchar('\n');
		puts("Enter a line (an empty line to quit):");
	}
	
	puts("Done!");
	return 0;
}







