#include <stdio.h>
#include "stack_2.h"

/* ���������ַ���ʵ����ջ�����Ϊstack��stack_2 */

int main(void)
{
	Stack buff;
	Item str[30], *p;
	
	InitializeStack(&buff);
	
	printf("Enter a str:");
	gets(str);
	puts("In original order:");
	puts(str);
	
	for(p = str; *p != '\0'; p++) // push stack
		PushStack(*p,&buff);
	for(p = str; *p != '\0'; p++)	//pop stack
		PopStack(p,&buff);
	
	puts("In reverse order:");
	puts(str);
	
	return 0;
}







