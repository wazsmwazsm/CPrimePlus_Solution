#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node * pnode);

/* interface function */

/* initialize function Set list to empty*/
void InitializeList(List * plist)
{
	*plist = NULL;
}

/* check List is or isn't empty */
bool ListIsEmpty(const List * plist)
{
	if(*plist == NULL)
		return true;
	else
		return false;
}

/* check List is or isn't full */
/* it's mean check memory is or isn't full*/
bool ListIsFull(const List * plist)
{
	Node * pt;
	bool full;
	
	pt = (Node *)malloc(sizeof(Node));
	if(pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;
}

/* count list item number */
unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;
	while(pnode != NULL)
		{
			++count;
			pnode = pnode->next;
		}
	return count;
}

/* adding item to list */
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = *plist;
	
	pnew = (Node*)malloc(sizeof(Node));
	if(pnew == NULL)
		return false;
		
	CopyToNode(item,pnew);
	pnew->next = NULL;
	
	if(scan == NULL)
		*plist = pnew;
	else
		{
			while(scan->next != NULL)
				scan = scan->next;
			
			scan->next = pnew;
		}		
	return true;			
}

/* access per list item , 
   pick a function act on them */
void Traverse(const List * plist, void (*pfun)(Item item))
{
	Node * pnode = *plist;
	while(pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* free the memory malloc() distributed 
   and set list point to NULL */
void EmptyTheList( List * plist)
{
	Node *psave;
	while(*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/* local function defination  */
/* copy a item to the list  */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}

