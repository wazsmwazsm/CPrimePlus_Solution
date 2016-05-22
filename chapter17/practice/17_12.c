#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

inline void eatline(void)
{
	while(getchar() != '\n');
}

char menu(void);
void addpet(Tree * pt);
void showpet(const Tree * pt);
void printitem(Item item);
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
	
	if(TreeIsFull(pt))
		puts("No room in the club!");
	else
		{
			puts("Please enter name of pet:");
			gets(temp.petname);
			puts("Please enter the pet kind.");
			gets(temp.petkind);
			uppercase(temp.petname);
			uppercase(temp.petkind);
			
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
	printf("Pet: %-19s Kind: %-19s\n",item.petname,
				 item.petkind);
}

void findpet(const Tree *pt)
{
	Item temp;
	
	if(TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}
	
	puts("Please enter name of pet:");
	gets(temp.petname);
	puts("Please enter the pet kind.");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname,temp.petkind);
	if(InTree(&temp,pt))
		printf("is a member.\n");
	else
		printf("is not a member.\n");
}

void droppet(Tree *pt)
{
	Item temp;
	
	if(TreeIsEmpty(pt))
		{
			puts("No entries.");
			return;
		}
	puts("Please enter name of pet:");
	gets(temp.petname);
	puts("Please enter the pet kind.");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname,temp.petkind);
	
	if(DeleteItem(&temp,pt))	
		puts("is dropped from the club.");
	else	
		puts("is not a member.");
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


