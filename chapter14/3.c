#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL	40
#define MAXBKS	100

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

struct book library[MAXBKS];
	
void sort_t(struct book *pb, int n);
void sort_v(struct book *pb, int n);

int main(void )
{
		int count = 0;
		int index;
		struct book *pb;
		pb = &library[0];
		
		printf("Enter the book title.\n");
		printf("Press [Enter] at the start of a line to stop.\n");
		
		while(count < MAXBKS && gets(library[count].title) != NULL 
						&& library[count].title[0] != '\0')
		{
			printf("Now enter the author.\n");
			gets(library[count].author);
			printf("Now enter the value.\n");
			scanf("%f",&library[count++].value);
			
			while(getchar()!= '\n');
			
			if(count < MAXBKS)
				printf("Enter the next title.\n");
		}
	
	if(count > 0 )
		{
			printf("Here is the list of your books:\n");
			for(index = 0; index < count; index ++)
				printf("%s by %s : $%.2f \n",
				library[index].title,
				library[index].author,
				library[index].value);
				
			printf("Here is the list of your books sortrd by title:\n");		
			sort_t(pb,count);
			for(index = 0; index < count; index ++)
				printf("%s by %s : $%.2f \n",
				library[index].title,
				library[index].author,
				library[index].value);
		
			printf("Here is the list of your books sortrd by value:\n");		
			sort_v(library,count);
			for(index = 0; index < count; index ++)
				printf("%s by %s : $%.2f \n",
				library[index].title,
				library[index].author,
				library[index].value);	
		}
	else
		puts("No books? Too bad!");	
	
	
	return 0;
}	

void sort_t(struct book pb[], int n)
{
	int top, search;
	struct book temp;
	
	for(top = 0 ; top < n - 1; top++)
		for(search = top + 1 ; search < n; search++)
			if(strcmp(pb[search].title,pb[top].title) < 0)
				{
					temp = pb[search];
					pb[search] = pb[top];
					pb[top] = temp;
				}
}

void sort_v(struct book pb[], int n)
{
	int top,search;
	struct book temp;
	
	for(top = 0; top < n - 1; top++)
		for(search = top + 1; search < n; search++)
			if(pb[search].value < pb[top].value)
				{
					temp = pb[search];
					pb[search] = pb[top];
					pb[top] = temp;				
				}			
}

/* 错误的例子，只是互换temp1和temp2的指向，但结构的指针木有互换啊！
void sort_t(struct book *pb, int n)
{
	int top, search;
	struct book *temp,*temp1,*temp2;
	
	for(top = 0 ; top < n - 1; top++)
		for(search = top + 1 ; search < n; search++)
			if(strcmp((pb+search)->title,(pb + top)->title) > 0)
				{
					temp1 = pb + search;
					temp2 =  pb + top;
					temp = temp1;
					temp1 = temp2;
					temp2 = temp;
				}
}
*/







