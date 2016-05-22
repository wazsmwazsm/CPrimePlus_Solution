#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL	40
#define MAXAUTL	40
#define MAXBKS	10

#define CONTINUE	0
#define DONE	1
#define YES	1
#define NO 0

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int del;
};

int getlet(const char *s);
int getbook(struct book *pb);
void updata(struct book *pb);

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int deleted = 0;
	int index, filecount, open;
	FILE *pbook;
	int size = sizeof(struct book);
	
	
	if((pbook = fopen("book.dat","rb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n","book.dat");
			exit(1);
		}
	rewind(pbook);
	while(count < MAXBKS && fread(&library[count], size,
				1,pbook) == 1)
		{
			if(count == 0)
				puts("Current contents of book.dat:");
				
			printf("%s by %s: $%.2f\n",library[count].title,
							library[count].author,library[count].value);
			
			puts("Do you wish to change or delete this entry? <y/n> ");
			if(getlet("yn") == 'y')
				{
					puts("Enter c to change , d to delet entry:");
					if(getlet("cd") == 'd')
					{
						library[count].del = YES;
						deleted++;
						
					}
					else
						updata(&library[count]);
				}
				
			count++;
		}
	fclose(pbook);
	
	filecount = count - deleted;
	
	if(filecount == MAXBKS)
		{
			puts("The book.dat file is full.");
			exit(2);
		}
	puts("Plaese add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	open =0;
	
	while(filecount < MAXBKS)
	{
		if(filecount < count)
			{
				while(library[open].del == NO)
					open++;
				if(getbook(&library[open]) == DONE)
					{
						filecount = count;  // 如果删除却没有填新值，但是空目录也占数组，所以要全显示
						break;
					}
			}
		else if (getbook(&library[filecount]) == DONE)												
					break;
				
		filecount++;  // 删除又添加新目录的话，可以用filecount来计数显示
		if(filecount < MAXBKS)
			puts("Enter the next book title.");
	}
	
		puts("Here is the list of your books:");
		for(index = 0; index < filecount; index++)
			if(library[index].del == NO)
				printf("%s by %s: $%.2f\n",library[index].title,
								library[index].author,library[index].value);
		
		
		if((pbook = fopen("book.dat","wb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n","book.dat");
			exit(1);
		}
		rewind(pbook);
		for(index = 0; index < filecount; index++)
			if(library[index].del == NO)
				fwrite(&library[index],size, 1, pbook);
		fclose(pbook);
		
		
	puts("Done!");
	
	return 0;
}

// 此函数返回字符串中的一个字符,也可以直接读取判断

int getlet(const char *s)
{
	char c;
	
	c = getchar();
	// 在字符串s中搜寻字符c
	while(strchr(s, c) == NULL)
		{
			printf("Enter a character in the list %s.\n",s);
			while(getchar()!='\n');
			
			c = getchar();
		}
	while(getchar()!='\n');
	
	return c;
}

int getbook(struct book *pb)
{
	int status = CONTINUE;
	
	if(gets(pb->title) == NULL || pb->title[0] == '\0')
		status = DONE;
	else
		{
			printf("Now enter the author: \n");
			gets(pb->author);
			printf("Now enter the value:\n");
			while(scanf("%f",&pb->value) != 1)
				{
					puts("Please use numberic input");
					scanf("%*s");
				}
			while(getchar() != '\n');
			
			pb->del = NO;
		}
	
	return status;
}

void updata(struct book *pb)
{
	struct book copy;
	char ch ;
		
	copy = *pb;
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title			a) modify author");
	puts("v) modify value			s) quit and saving changes");
	puts("q) quit and ignore changes");
	
	while((ch = getlet("tavsq")) != 's' && ch != 'q')
	{
		switch (ch)
		{
			case 't': puts("Enter new title:");
								gets(copy.title);
								break;
			case 'a': puts("Enter new author:");
								gets(copy.author);
								break;
			case 'v': puts("Enter new value:");
								while(scanf("%f",&copy.value) != 1)
								{
									puts("Enter a numberic value:");
									scanf("%*s");
								}
								while(getchar() != '\n');
								break;			
		}
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title			a) modify author");
	puts("v) modify value			s) quit and saving changes");
	puts("q) quit and ignore changes");		
	}
	if(ch == 's')
		*pb = copy;
}





