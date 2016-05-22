#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 81

char get_choice(void);
void origin_put(char **str, int n);
void ascii_put(char *str[], int n);
void length_put(char *str[], int n);
int first_word_length(char *str);
void first_word_length_put(char **str, int n);

int main(void)
{
	char input[LIM][SIZE];
	char *ptstr[LIM];
	char select;
	
	int ct = 0;

	printf("Input up to %d lines finished by EOF(^Z).\n",LIM);
	puts("To stop, press the Enter key at a line's start.");
	while(ct < LIM && gets(input[ct]) && input[ct][0] != '\0')
		{
			ptstr[ct] = input[ct];			//注意，不要把二维数组传到接受指针数组的函数，一个元素是指针，一个是字符，二维数组定义为char (str *)[SIZE]
			ct ++;
		}
	
	while((select = get_choice())!= 'q')
		{
			switch(select)
			{
				case 'a': origin_put(ptstr,ct);
									break;
				case 'b': ascii_put(ptstr,ct);
									break;
				case 'c': length_put(ptstr,ct);
									break;
				case 'd': first_word_length_put(ptstr,ct);
									break;
				default:	puts("Program error!");
									break;
			}
			
		}
	printf("Bye!\n");
		
	return 0;
}
char get_choice(void)
{
	char ch;
	puts("Please make choice for this string:");
	puts("a. put originally.");
	puts("b. put in order of ascii.");
	puts("c. put in order of string's length.");
	puts("d. put in order of first word's length.");
	puts("q. quit.");
	ch = getchar();
	while(getchar()!= '\n');
	while((ch <'a' || ch> 'd') && ch != 'q')
		{
			puts("Please respond with: a, b, c, d or q.");
			ch = getchar();
			while(getchar()!= '\n');
		}
	return ch;
}
void origin_put(char **str, int n)
{
	int i;
	for(i=0; i<n; i++)
		puts(str[i]);	
}

void ascii_put(char *str[], int n)
{
	char * temp;
	int top, seek;
	
	for(top = 0; top < n - 1; top++)
		for(seek = top + 1; seek < n; seek++)
			if(strcmp(str[top],str[seek]) > 0)
				{
					temp = str[top];
					str[top] = str[seek];
					str[seek] = temp;				
				}
	origin_put(str,n);
}
void length_put(char *str[], int n)
{
	char *temp;
	int top, seek;
	
	for(top = 0; top < n - 1; top++)
		for(seek = top + 1; seek < n; seek++)
			if(strlen(str[top]) > strlen(str[seek]))
				{
					temp = str[top];
					str[top] = str[seek];
					str[seek] = temp;
				}
	origin_put(str,n);
}

int first_word_length(char *str)
{
	int len = 0;
	

	while(*str++ )		
			{
				if(!isspace(*str))  //开头不能为空格
					len++;
				else
					break;			
			}
	return len;		
}
void first_word_length_put(char **str, int n)
{
	char *temp;
	int top, seek;
	
	for(top = 0; top < n - 1; top++)
		for(seek = top + 1; seek < n; seek++)
			if(first_word_length(str[top]) > first_word_length(str[seek]))
				{
					temp = str[top];
					str[top] = str[seek];
					str[seek] = temp;
				}
	origin_put(str,n);
}