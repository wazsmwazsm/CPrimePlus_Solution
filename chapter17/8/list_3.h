#ifndef __LIST_H
#define __LIST_H

#include <stdbool.h> // C99

/* the max Length of the list */
/* 列表的最大长度 */
#define TSIZE	45

/* specific type defination */
/* 特定类型定义 */
struct pat	{	
	char petkind[20];
};

/* general type defination */
/* 通常类型定义 */

typedef struct pat	Item_list;

typedef struct node_list {
	Item_list item;
	struct node_list * next;
}Node_list;

/* 双向列表 */
typedef  struct list {
	Node_list * head;
	Node_list * end;
} List;

/* Function  prototype */
/* 类型操作函数定义定义 */

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
bool AddListItem(Item_list item, List * plist);

/* operation:         ensure the item (Yes or Not) in the list  */
bool InList(Item_list item, const List * plist);

/* operation:         Delete a item of the list  */
/* beafur operation:  plist point a initialized list  */
/* after operation:   if delete successed ,return true, else return false  */
bool DeleteListItem(Item_list item, List * plist);

/* operation:         access per list item , 
   										pick a function act on them  */
/* beafur operation:  plist point a initialized list 
											pfun point a fucntion who accept a paramter item
											and return void	*/
/* after operation:   the fuction pfun pointed act on per item of the list  */
void TraverseList(const List * plist, void (*pfun)(Item_list item));

/* operation:         free the memory malloc() distributed  */
/* beafur operation:  plist point a initialized list  */
/* after operation:   the memory of the list will be freed
											and set the list to empty(NULL)  */
void EmptyTheList( List * plist);

#endif