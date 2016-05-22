#include <stdio.h>
#define LEN 81
char * my_strncpy(char *, const char *, int );
int main(void)
{
	char str1[LEN];
	char str2[LEN];
	int n;
	
	puts("Input string1:");

	while(gets(str1) && str1[0] != '\0')
	{
		puts("Input string2:");
		gets(str2);
		
		puts("Input the number of copying char:");
		scanf("%d",&n);
		while(getchar()!='\n');
		
		puts("After copy:");
		puts(my_strncpy(str1, str2, n));
		
		puts("Input string1:");
	}
	puts("Done.");
	return 0;
}
char * my_strncpy(char *dest,
									const char *source,
									int count
									)
{
	char *start = dest; // 保存dest的开始指针到start
	
	while(count && (*dest++ = *source++))
		count--;
	
	if(count)
		while(--count)
			*dest++ = '\0';
 	return start;
}
	