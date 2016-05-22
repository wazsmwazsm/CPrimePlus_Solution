#include <stdio.h>
#include <stdlib.h> // suport exit()
#include "list_2.h"			// suport List, Item

void showmovies(Item item);

int main(void)
{
	List movies;
	Item temp;
	
	/* Initialize */
	InitializeList(&movies);
	if(ListIsFull(&movies))
		{
			fprintf(stderr,"No memory avaliable! Bye!\n");
			exit(1);
		}
	
	/* collecte and storage data */
	puts("Enter first movie title :");
	while(gets(temp.title) != NULL &&
				temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10> : ");
		scanf("%d",&temp.rating);
		while(getchar() != '\n');
		
		if(AddItem(temp,&movies) == false)
			{
				fprintf(stderr,"Problem allocating memory\n");
				break;
			}
		if(ListIsFull(&movies))
		{
			puts("The list id full.");
			break;
		}
		
		puts("Enter next movie title (empty line to quit):");
	}
	
	/* Display List */
	if(ListIsEmpty(&movies))
		printf("No data entred.");
	else
		{
			printf("Here is the movie list :\n");
			Traverse(&movies,showmovies);			
		}
	printf("Your entered %d movies.\n",ListItemCount(&movies));
	
	/* clean list */
	EmptyTheList(&movies);
	
	printf("Bye!\n");	
	
	return 0;
}

void showmovies(Item item)
{
	printf("Movie: %s Rating: %d\n",item.title,
				 item.rating);
}









