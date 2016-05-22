#include <stdio.h>
#define LEN 81
void * getnchar(char * str, int n);

int main(void)
{
	char input[LEN];
	char *chk;
	int n;
	
	puts("input the char number of your string:");
	scanf("%d",&n);
	while(getchar() != '\n');
	
	puts("input your string:");
	chk = getnchar(input, n);
	if (chk == NULL)
		puts("input failed.");
	else
		puts(input);
	
	puts("Done.");
	
	return 0;
}

void * getnchar(char * str, int n)
{
	int i;
	int ch;
	
	for(i=0; i<n; i++)
		{
			ch = getchar();
			if (ch != EOF)
				str[i] = ch;
			else
				break;
		}
	if(ch == EOF)
		return NULL;
	else
		{
			str[i] = '\0';
			return str;
		}

}

