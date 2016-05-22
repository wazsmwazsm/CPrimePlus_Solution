#include <stdio.h>
#define MAXTITL 40
#define MAXAUTL	40
#define MAXBKS	100

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct book library[MAXBKS];
	
int main(void )
{
		int count = 0;
		int index;
		
		printf("Enter the book title.\n");
		printf("Press [Enter] at the start of a line to stop.\n");
		
		while(count < MAXBKS && gets(library[count].title) != NULL 
						&& library[count].title[0] != '\0')
		{
			printf("Now enter the author.\n");
			gets(library[count].author);
			printf("Now enter the value.\n");
			scanf("%f",&library[count++].value);
			
			while(getchar()!= '\n');
			
			if(count < MAXBKS)
				printf("Enter the next title.\n");
		}
	
	if(count > 0 )
		{
			printf("Here is the list of your books:\n");
			for(index = 0; index < count; index ++)
				printf("%s by %s : $%.2f \n",
				library[index].title,
				library[index].author,
				library[index].value);
		}
	else
		puts("No books? Too bad!");	
	
	
	return 0;
}	















