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
	while(*str)	//�жϲ�Ϊ'\0'
		{
			if(*str == ' ')
				{
					pos = str;
				while(*pos)	//������ո�֮�������������ǰ�ƶ�һ��ָ��
				{
					*pos = *(pos + 1);
					pos++;
				}
				}
			else
				str++;    //ɨ���ַ��������ĸ��ǿո�
		}
}


