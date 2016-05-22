#include <stdio.h>
#include <stdlib.h>
#include "list_3.h"


/* 用来追踪当前节点指针和前一个节点的指针 */
typedef struct pair_list {
	Node_list * prev;
	Node_list * current;
	
}Pair_list;


/* local function prototype */
/* 本地函数声明（不作为编程接口的函数） */
static void CopyToNode(Item_list item, Node_list * pnode);

static Pair_list SearchItem(Item_list item, const List * plist);


/* interface function */
/* 接口函数定义 */

/* initialize function Set list to empty*/
void InitializeList(List * plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

/* check List is or isn't empty */
bool ListIsEmpty(const List * plist)
{
	if(plist->head == NULL)
		return true;
	else
		return false;
}

/* check List is or isn't full */
/* it's mean check memory is or isn't full*/
bool ListIsFull(const List * plist)
{
	Node_list * pt;
	bool full;
	
	pt = (Node_list *)malloc(sizeof(Node_list));
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
	Node_list * pnode = plist->head;
	while(pnode != NULL)
		{
			++count;
			pnode = pnode->next;
		}
	return count;
}

/* adding item to list */
bool AddListItem(Item_list item, List * plist)
{
	Node_list * pnew;
	
	pnew = (Node_list*)malloc(sizeof(Node_list));
	if(pnew == NULL)
		return false;
		
	CopyToNode(item,pnew);
	pnew->next = NULL;
	
	if(ListIsEmpty(plist))
		plist->head = pnew;
	else
		plist->end->next = pnew; /* add item to the end of list */
	
	plist->end = pnew; /* update end point */
		
	return true;			
}

/*  ensure the item (Yes or Not) in the list  */
bool InList(Item_list item, const List * plist)
{
	return SearchItem(item,plist).current == NULL ? false : true;	
}

/* search a item , return the static Pair_list look  */
static Pair_list SearchItem(Item_list item, const List * plist)
{
	Pair_list look;
	look.current = plist->head;  
	look.prev = NULL;
	
	if(look.current == NULL)
		return look;
		
	while(look.current != NULL)
	{
		if(strcmp(look.current->item.petkind, item.petkind) == 0)
			break;
		look.prev = look.current;
		look.current = look.current->next;
	}
	return look;
}

bool DeleteListItem(Item_list item, List * plist)
{
	Pair_list look;
	
	
	if(ListIsEmpty(plist))
		{
			return false;
		}
		
	if((look = SearchItem(item,plist)).current == NULL)
		{
			fprintf(stderr, "delete error!");
			return false;
		}
	else
		{
			if(look.current == plist->head) // 如果要删除条目是列表头的话
				{			
					plist->head = look.current->next;		// 重新定位头指针
					free(look.current);
					return true;
				}
			else
				{
				look.prev->next = look.current->next;
				free(look.current);
				return true;
				}
		}
}

/* access per list item , 
   pick a function act on them */
void TraverseList(const List * plist, void (*pfun)(Item_list item))
{
	Node_list * pnode = plist->head;
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
	Node_list *psave;
	Node_list *pscan = plist->head;
	
	while(pscan != NULL)
	{
		psave = pscan->next;
		free(pscan);
		pscan = psave;
	}
}

/* local function defination  */
/* copy a item to the list  */
static void CopyToNode(Item_list item, Node_list * pnode)
{
	pnode->item = item;
}

