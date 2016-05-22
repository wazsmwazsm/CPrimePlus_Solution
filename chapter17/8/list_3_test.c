#include <stdio.h>
#include <stdlib.h> // suport exit()
#include "list_3.h"			// suport List, Item

void showmovies(Item_list item);

/* 本例子用来测试 list_3 列表文件包，测试时请把           */
/* list_3.h 中的 Item  定义加上 int rating ;这一项， 如下 */
/*                                                        */
/*		struct pat	{	                                      */
/*		 char petkind[20];                                  */
/*		};                                                  */
/*		typedef struct pat	Item_list;                      */
/*		                                                    */
/*		改为：                                              */
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


/* 打印item内容的函数，用来给列表的遍历函数做参数 */
void showmovies(Item_list item)
{
	printf("Movie: %s Rating: %d\n",item.petkind,
				 item.rating);
}














