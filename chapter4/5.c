#include <stdio.h>
#include <string.h>

int main(void)
{
	char surname[20],firstname[20];
	printf("Please input your firstname and surname :\n");
	scanf(" %s",firstname);
	scanf(" %s",surname);
	
	printf("%s %s\n",firstname,surname);
	
	printf("%*d %*d\n",strlen(firstname),		\
	strlen(firstname),strlen(surname),		\
	strlen(surname));
	
	printf("%s %s\n",firstname,surname);
	
	printf("%-*d %-*d\n",strlen(firstname),		\
	strlen(firstname),strlen(surname),		\
	strlen(surname));
	

	return 0;
	
}