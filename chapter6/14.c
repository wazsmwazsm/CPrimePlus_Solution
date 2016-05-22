
#include <stdio.h>
#include <string.h>
#define LENGTH 255

int main(void)
{
	char string[255] = {0};
	int i=0;
	
	printf("Enter a string:");
	
//	for(i=0;i<LENGTH && ((string[i] = getchar()) != '\n');i++) ;
		
	while((string[i] = getchar()) != '\n')
	{
		i++;
	}
	for(i=strlen(string)-2;i>=0;i--) //i = strlen(string)-2 ,to ignore '/n'
			printf("%c",string[i]);
			
	printf("\n");
	
return 0;
	
}