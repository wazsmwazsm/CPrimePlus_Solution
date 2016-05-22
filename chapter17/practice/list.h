#ifndef __LIST_H
#define __LIST_H

#include <stdbool.h> // C99

#define TSIZE	45

/* specific type defination */

struct film	{
	char title[TSIZE];
	int rating;
};

/* general type defination */
typedef struct film	Item;

typedef struct node {
	Item item;
	struct node * next;
}Node;

typedef Node * List;

/* Function  prototype */

/* operation:         initialize a list  */
/* beafur operation:  plist point a list  */
/* after operation:   list set to NULL  */
void InitializeList(List * plist);

/* operation:         sure the list is empty list  */
/* beafur operation:  plist point a initialized list  */
/* after operation:   if plist is empty return true, else return false  */
bool ListIsEmpty(const List * plist);

/* operation:         sure the list is full list  */
/* beafur operation:  plist point a initialized list  */
/* after operation:   if plist is full return true, else return false  */
bool ListIsFull(const List * plist);

/* operation:         ensure the item number of the list  */
/* beafur operation:  plist point a initialized list  */
/* after operation:   return the number of item  */
unsigned int ListItemCount(const List * plist);

/* operation:         add a item to end of the list  */
/* beafur operation:  item is what will be adding, 
											plist point a initialized list  */
/* after operation:   if could, add a item to end of the list,
											successed return ture, else return false   */
bool AddItem(Item item, List * plist);

/* operation:         access per list item , 
   										pick a function act on them  */
/* beafur operation:  plist point a initialized list 
											pfun point a fucntion who accept a paramter Item
											and return void	*/
/* after operation:   the fuction pfun pointed act on per item of the list  */
void Traverse(const List * plist, void (*pfun)(Item item));

/* operation:         free the memory malloc() distributed  */
/* beafur operation:  plist point a initialized list  */
/* after operation:   the memory of the list will be freed
											and set the list to empty(NULL)  */
void EmptyTheList( List * plist);

#endif