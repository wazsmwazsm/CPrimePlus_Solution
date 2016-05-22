#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE	45

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
};


int main(void)
{
		struct film *head = NULL;
		struct film * prev, * current;
		char input[TSIZE];
		
		
		puts("Enter first movie title:");
		while(gets(input) != NULL && input[0] != '\0')
		{
			current = (struct film *) malloc(sizeof(struct film));
			
			if(head == NULL)  // first struct
				head = current;
			else 
				prev->next = current; // next struct
				
			current->next  = NULL;
			strcpy(current->title, input);
			puts("Enter your rating:");
			scanf("%d",&current->rating);
			while(getchar() != '\n');
			puts("Enter next movie title (empty line to stop):");	
			
			prev = current;
		}
		
		if(head == NULL)
			puts("No data entered.");
		else
			puts("Here is the movie list:");
			
// show the movie list	
	
		current = head;
		while(current != NULL)
			{
				printf("Moive: %s  Rating: %d.\n",current->title,
							 current->rating);
				current = current->next;
			}


// free the memery
		
		current = head;
		while(current != NULL)
			{
				free(current);
				current = current->next;
			}
		
		puts("Bye!");
		
	return 0;
}
