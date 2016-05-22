#include <stdio.h>
#include <stdlib.h>
#include "list_2.h"


/* interface function */

/* initialize function Set list to empty*/
void InitializeList(List * plist)
{
	plist->items = 0;
}

/* check List is or isn't empty */
bool ListIsEmpty(const List * plist)
{
	if(plist->items == 0)
		return true;
	else
		return false;
}

/* check List is or isn't full */
/* it's mean check memory is or isn't full*/
bool ListIsFull(const List * plist)
{
	if(plist->items == MASIZE)
		return true;
	else
		return false;
}

/* count list item number */
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

/* adding item to list */
bool AddItem(Item item, List * plist)
{
	if(ListIsFull(plist))
		{
			puts("The list ia full, add faild");
			return false;
	  }
	plist->entries[plist->items] = item;
	
	plist->items++;
	
	return true;			
}

/* access per list item , 
   pick a function act on them */
void Traverse(const List * plist, void (*pfun)(Item item))
{
	int index;
	for(index = 0; index < plist->items; index++)
		(*pfun)(plist->entries[index]);
}

/* free the memory malloc() distributed 
   and set list point to NULL */
void EmptyTheList( List * plist)
{
		plist->items = 0;
}
