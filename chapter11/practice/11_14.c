#include <stdio.h>
#include <string.h>
#define SIZE 80
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smile like a old shoes."; 
	
	puts("what is your favorite flower?");
	gets(flower);
	
	strcat(flower,addon);
	puts(flower);
	puts(addon);
	
	
	return 0;
}