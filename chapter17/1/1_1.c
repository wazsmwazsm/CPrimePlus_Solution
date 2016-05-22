#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE	45

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
};

void show_rec(const struct film * pf);

/* 本例用递归解决  */



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
		current = head;
		if(current != NULL)
			{
				puts("\nHere is list in reverse order:");
				show_rec(current);
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

void show_rec(const struct film * pf)
{
	if(pf->next != NULL)
		show_rec(pf->next);
	printf("Movie: %s Rating: %d\n",pf->title,pf->rating);
}