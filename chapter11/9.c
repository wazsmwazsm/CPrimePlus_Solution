#include <stdio.h>
#define LEN	81
void delspace(char *str);

int main(void)
{
	char str[LEN];
	puts("Enter a string:");
	
	while(gets(str) && str[0] != '\0')
	{
		delspace(str);
		puts("Ok, I delete all space in string.");
		puts(str);
		
		puts("Enter a string:");
	}
	puts("Done.");
		
	return 0;
}
void delspace(char *str)
{
	char *pos;
	while(*str)	//判断不为'\0'
		{
			if(*str == ' ')
				{
					pos = str;
				while(*pos)	//把这个空格之后的所有内容向前移动一个指针
				{
					*pos = *(pos + 1);
					pos++;
				}
				}
			else
				str++;    //扫描字符串，看哪个是空格
		}
}


