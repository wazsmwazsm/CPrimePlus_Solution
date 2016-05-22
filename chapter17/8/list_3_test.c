#include <stdio.h>
#include <stdlib.h> // suport exit()
#include "list_3.h"			// suport List, Item

void showmovies(Item_list item);

/* �������������� list_3 �б��ļ���������ʱ���           */
/* list_3.h �е� Item  ������� int rating ;��һ� ���� */
/*                                                        */
/*		struct pat	{	                                      */
/*		 char petkind[20];                                  */
/*		};                                                  */
/*		typedef struct pat	Item_list;                      */
/*		                                                    */
/*		��Ϊ��                                              */
/*		struct film	{	                                      */
/*			char movie[20];                                   */
/*			int rating;                                       */
/*		};                                                  */
/*		typedef struct film	Item_list;                      */
/*                  */

int main(void)
{
	List movies;
	Item_list temp;
	
	/* Initialize */
	InitializeList(&movies);
	if(ListIsFull(&movies))
		{
			fprintf(stderr,"No memory avaliable! Bye!\n");
			exit(1);
		}
	
	/* collecte and storage data */
	puts("Enter first movie title :");
	while(gets(temp.petkind) != NULL &&
				temp.petkind[0] != '\0')
	{
		puts("Enter your rating <0-10> : ");
		scanf("%d",&temp.rating);
		while(getchar() != '\n');
		
		if(AddListItem(temp,&movies) == false)
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
			TraverseList(&movies,showmovies);			
		}
	printf("Your entered %d movies.\n",ListItemCount(&movies));
	
	/* search a item from the List */
	puts("Now search a item, enter the item you want to search:");
	gets(temp.petkind);
	
	if(InList(temp,&movies))
		printf("%s is in the list.\n",temp.petkind);
	else
		printf("%s is not in the list.\n",temp.petkind);
		
	/* display the list after search item */
	printf("Here is the movie list :\n");
			Traverse(&movies,showmovies);	
	
	
	/* Delete a item from the List*/
	puts("Now delete a item, enter the item you want to delete:");
	gets(temp.petkind);
	
	if(DeleteListItem(temp,&movies))
		printf("%s is deleted.\n",temp.petkind);
	else
		printf("%s delete error.\n",temp.petkind);
		
	/* display the list after delete item */
	printf("Here is the movie list :\n");
			Traverse(&movies,showmovies);	
		
	/* clean list */
	EmptyTheList(&movies);
	
	printf("Bye!\n");	
	
	return 0;
}


/* ��ӡitem���ݵĺ������������б�ı������������� */
void showmovies(Item_list item)
{
	printf("Movie: %s Rating: %d\n",item.petkind,
				 item.rating);
}














