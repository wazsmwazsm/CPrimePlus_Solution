#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_2.h"

typedef struct pair {
	Node * parent;
	Node * child;
	
}Pair;

static void InOrder(const Node * root,void(*pfun)(Item item));
static void DeleteAllNode(Node * root);
static void AddNode(Node * new_node, Node * root);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static Node * MakeNode(const Item * pi);
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Node **ptr);

void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if(ptree->root == NULL)
		return true;
	else
		return false;	
}

bool TreeIsFull(const Tree * ptree)
{
	if(ptree->size == MAXITEMS)
		return true;
	else
		return false;		
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
		Node * new_node;
		Pair look;
		
		if(TreeIsFull(ptree))
			{
				fprintf(stderr,"Tree is full\n");
				return false;
			}
		if((look = SeekItem(pi,ptree)).child != NULL)
			{
				if(!AddListItem(pi->petinfo.head->item, &look.child->item.petinfo)) 
					return false;
				else
					{
						ptree->size++;
						return true;
					}
			}
		new_node = MakeNode(pi);
		if(new_node == NULL)
			{
				fprintf(stderr,"Couldn't create node\n");
				return false;
			}
		ptree->size++;	
		
		if(ptree->root == NULL)	
			ptree->root = new_node;
		else
			AddNode(new_node,ptree->root);
		
		return true;	
}

bool InTree(const Item * pi, const Tree * ptree)
{
	Pair look;
	
	if((look = SeekItem(pi,ptree)).child == NULL)
		return false;
	else 
		{
			if(InList(pi->petinfo.head->item, &look.child->item.petinfo))
				return true;
			
			return false;
		}
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	Item_list list_temp = pi->petinfo.head->item;

	look = SeekItem(pi,ptree);
	if(look.child == NULL || !InList(list_temp, &look.child->item.petinfo))
		return false;
	
	
	if(ListItemCount(&look.child->item.petinfo) > 1)
	{	
			if(DeleteListItem(list_temp, &look.child->item.petinfo));
				ptree->size--;	 // 如果删除成功减少项目数
			
	}
	else
	{
		if(look.parent == NULL)
			DeleteNode(&ptree->root);
		else if(look.parent->left == look.child)	
			DeleteNode(&look.parent->left);
		else
			DeleteNode(&look.parent->right);
		ptree->size--;
	}
	
	return true;
}

void Traverse(const Tree * ptree, void(*pfun)(Item item))
{
	if(ptree != NULL)
		InOrder(ptree->root, pfun);	
}

void DeleteAll(Tree * ptree)
{
	if(ptree != NULL)
		DeleteAllNode(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static void InOrder(const Node * root,void(*pfun)(Item item))
{
	if(root != NULL)
	{
		InOrder(root->left,pfun);
		(*pfun)(root->item);
		InOrder(root->right,pfun);		
	}	
}

static void DeleteAllNode(Node * root)
{
	Node * pright;
	
	if(root != NULL)
	{
		pright = root->right;
		DeleteAllNode(root->left);
		
		EmptyTheList(&root->item.petinfo);
		free(root);
		
		DeleteAllNode(pright);
	}	
}

static void AddNode(Node * new_node, Node * root)
{
	if(ToLeft(&new_node->item, &root->item))
	{
		if(root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node,root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if(root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node,root->right);
	}
	else
	{
		fprintf(stderr,"Location error in AddNode()\n");
		exit(1);
	}	
}


static bool ToLeft(const Item * i1, const Item * i2)
{
	if(strcmp(i1->petname,i2->petname) < 0)
		return true;
	else 
		return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
	if(strcmp(i1->petname,i2->petname) > 0)
		return true;
	else 
		return false;
}

static Node * MakeNode(const Item * pi)
{
	Node * new_node;
	
	new_node = (Node *)malloc(sizeof(Node));
	if(new_node != NULL)
	{
		new_node->item = *pi;		  
		new_node->left = NULL;
		new_node->right = NULL;
	}
	
	return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	
	if(look.child == NULL)
		return look;
	while(look.child != NULL)
	{
		if(ToLeft(pi,&(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if(ToRight(pi,&(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;			
		}
		else
			break;
	}
	
	return look;
}

static void DeleteNode(Node **ptr)
{
	Node *temp;
	
	puts((*ptr)->item.petname);
	if((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		
		EmptyTheList(&temp->item.petinfo);
		free(temp);
	}
	else if((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		
		EmptyTheList(&temp->item.petinfo);
		free(temp);
	}
	else
	{
		for(temp = (*ptr)->left; temp->right != NULL;
				temp = temp->right);
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		
		EmptyTheList(&temp->item.petinfo);
		free(temp);	
	}
}





