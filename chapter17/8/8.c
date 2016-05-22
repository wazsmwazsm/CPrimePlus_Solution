#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree_2.h"

inline void eatline(void)
{
	while(getchar() != '\n');
}

char menu(void);
void addpet(Tree * pt);
void showpet(const Tree * pt);
void printitem(Item item);
void printitemList(Item_list item);
void findpet(const Tree *pt);
void droppet(Tree *pt);
char getlet(char * str);
void uppercase(char * str);

int main(void)
{
	Tree pets;
	char choice;
	
	InitializeTree(&pets);
	while((choice = menu()) != 'q')
	{
		switch(choice)
		{	
			case 'a': addpet(&pets);
							 break;
			case 'l': showpet(&pets);
							 break;
			case 'f': findpet(&pets);
							 break;
			case 'n': printf("%d pets in club",
										  TreeItemCount(&pets));
							 break;
			case 'd': droppet(&pets);
							 break;
			default: puts("Switching error");
		}
	}
	DeleteAll(&pets);
	puts("Bye!");
	
	return 0;
}

char menu(void)
{
	int ch;
	
	puts(" Nerfville Pet Club Membership Program ");
	puts(" Enter the letter corresponding to your choice ");
	puts(" a)add a pet  l)show list of pets ");
	puts(" n)number of pets  f)find pets ");
	puts(" d)delete am pet  q)quit ");
	
	ch = getlet("alnfdq");
	
	return ch;
}

void addpet(Tree * pt)
{
	Item temp;
	Item_list list_temp;
	char word[20];
	
	
	InitializeList(&temp.petinfo);
	
	if(TreeIsFull(pt))
		puts("No room in the club!");
	else
		{
			puts("Please enter name of pet:");
			gets(temp.petname);
			puts("Please enter the pet kind.");
			gets(word);
			uppercase(temp.petname);
			uppercase(word);
			strcpy(list_temp.petkind,word);
			AddListItem(list_temp,&temp.petinfo);
			AddItem(&temp, pt);
		}
	
}

void showpet(const Tree * pt)
{
	if(TreeIsEmpty(pt))
		puts("No entries");
	else
		Traverse(pt,printitem);
}

void printitem(Item item)
{
	int count = 0;
	if((count = ListItemCount(&item.petinfo)) > 1)
		{
			printf("There are %d pet named %s, their kind is ",count,item.petname);
			TraverseList(&item.petinfo, printitemList);
			putchar('\n');
		}	
	else
		printf("Pet: %-19s Kind: %-19s\n",item.petname,
				 	 item.petinfo.head->item.petkind);
}

void printitemList(Item_list item)
{
	printf("Kind: %-10s\t",item.petkind);
}


void findpet(const Tree *pt)
{
	Item temp;
	Item_list list_temp;
	char word[20];
	
	InitializeList(&temp.petinfo);

	if(TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet:");
	gets(temp.petname);
	puts("Please enter the pet kind.");
	gets(word);
	uppercase(temp.petname);
	uppercase(word);
	strcpy(list_temp.petkind,word);
	AddListItem(list_temp,&temp.petinfo);
	
	printf("%s the %s ", temp.petname, word);
	if(InTree(&temp,pt))
		printf("is a member.\n");
	else
		printf("is not a member.\n");
	
	EmptyTheList(&temp.petinfo);
}

void droppet(Tree *pt)
{
	Item temp;
	Item_list list_temp;
	char word[20];
	InitializeList(&temp.petinfo);
	
	if(TreeIsEmpty(pt))
		{
			puts("No entries.");
			return;
		}
	puts("Please enter name of pet:");
	gets(temp.petname);
	puts("Please enter the pet kind.");
	gets(word);
	uppercase(temp.petname);
	uppercase(word);
	strcpy(list_temp.petkind,word);
	AddListItem(list_temp,&temp.petinfo);
			
	printf("%s the %s ",temp.petname,word);
	
	if(DeleteItem(&temp,pt))	
		puts("is dropped from the club.");
	else	
		puts("is not a member.");
	
	EmptyTheList(&temp.petinfo);
}

char getlet(char * str)
{
	char ch;
	
	ch = getchar();
	
	while(strchr(str,ch) == NULL)
		{
			printf("Please enter the character in list %s \n",str);
			ch = getchar();
			eatline();
		}
	eatline();	
	return ch;
}


void uppercase(char * str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}


