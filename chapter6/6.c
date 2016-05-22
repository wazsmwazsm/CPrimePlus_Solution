
#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[20];
	int i;
	
	printf("Please input a word:");
	scanf("%s",word);
	
	for(i=strlen(word)-1;i>=0;i--)
	{
		printf("%c",word[i]);
	}
	printf("\n");
	
	
return 0;
	
}