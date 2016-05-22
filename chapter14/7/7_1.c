#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL	40
#define MAXAUTL	40
#define MAXBKS	10

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
	struct book library[MAXBKS]; // 定义结构数组
	int count = 0;	// count用来最初读取文件内容计数
	int index, oindex;	// index 做处理完成后结构读取的引索，oindex 做读取新书目录的引索
	int deleted = 0;  // 用于记录删除次数
	FILE *pbooks;
	int size = sizeof(struct book);
	
	
	if((pbooks = fopen("book.dat","rb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n","book.dat");
			exit(1);
		}
	
	rewind(pbooks); // 文件指针返回原点
	
// 二进制模式读取文件内容到结构，并提示是否修改或删除该行目录	
	while(count < MAXBKS && fread(&library[count], size,
				1,pbooks) == 1)
		{
			if(count == 0)
				puts("Current contents of book.dat:");
				
			printf("%d) %s by %s: $%.2f\n", count + 1, library[count].title,
							library[count].author, library[count].value);
			
			puts("Do you wish to change or delete this entry? <y/n> ");
			if(getlet("yn") == 'y')
				{
					puts("Enter c to change , d to delet entry:");
					if(getlet("cd") == 'd')
					{
						library[count].del = YES;  // 如果要删除，将结构的删除标志位置为 1	
						deleted++;				
						puts("Enter marked for deletion.");
					}
					else
						updata(&library[count]);
				}
				
			count++;
		}
		fclose(pbooks);
/* 
	如果文件满员则退出		
  (count - deleted) 用来在文件满员但是有删除目录的情况下使用，
  以便可以删除满员文件的目录, 没有删除的话可满员退出 
*/
	if((count - deleted) == MAXBKS)  
		{
			puts("The book.dat file is full.");
			exit(2);
		}
		
// 	读入新的书本目录，遇到空行则退出	
	puts("Plaese add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	
	for(oindex = 0; oindex < MAXBKS; oindex++)
		{
			if(library[oindex].del == YES || oindex >= count)
				{
					if(getbook(&library[oindex])) 
						{
							if(library[oindex].del == YES) 
								oindex = count; // 如果没有添加新目录却删除目录，为显示之前的项目（除了删除的）计数
							break;					
						}
						
					puts("Plaese add new book titles.");
					puts("Press [enter] at the start of a line to stop.");
				}
		}
	if((pbooks = fopen("book.dat","wb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n","book.dat");
			exit(1);
		}
// 文件指针归位，将更新后的结构从内存写入到文件中				
		rewind(pbooks);		
// 读取完毕后显示更新后的目录
	if(oindex > 0 ) 
		{	
			puts("Here is the list of your books:");
			for(index = 0; index < oindex; index++)
				if(library[index].del != YES)
					{
						printf("%d) %s by %s: $%.2f\n",index, library[index].title,
									library[index].author, library[index].value);
						
						fwrite(&library[index],size, 1, pbooks);	
					}
		}		
	else
		puts("No books? Too bad.");	
		
	fclose(pbooks);	// 关闭文件，处理结束
	
	puts("Done!");
	
	return 0;
}

// 如果读取字符ch在字符串s中，则返回字符ch，否则提示重新输入

int getlet(const char *s)
{
	char ch;
	
	ch = getchar();
	// 在字符串s中搜寻字符ch
	while(strchr(s, ch) == NULL)
		{
			printf("Enter a character in the list %s.\n",s);
			while(getchar()!='\n');
			
			ch = getchar();
		}
	while(getchar()!='\n');
	
	return ch;
}

// 读取新书函数

int getbook(struct book *pb)
{			
	// 如果输入空行，返回 1 使循环break					
			if(gets(pb->title) == NULL || pb->title[0] == '\0')
					return 1;
					
	// 如果是删除行的话，把删除标志位置 0				
			if(pb->del == YES)
				pb->del = NO;
	// 读取作者				
			printf("Now enter the author: \n");
			gets(pb->author);
	// 读取价格，并剔除无用输入		
			printf("Now enter the value:\n");
			while(scanf("%f",&pb->value) != 1)
				{
					puts("Please use numberic input");
					scanf("%*s");
				}
			while(getchar() != '\n');		// 剔除回车符
			
			return 0;		// 正常读取的话返回 0
}

// 更新函数 

void updata(struct book *pb)
{
	struct book copy;
	char ch ;
	
	// 创建副本，占时存储更新内容	
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
								strcpy(copy.title," ");								
								break;
			case 'a': puts("Enter new author:");
								strcpy(copy.author," ");								
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
	
	// 如果要保存，把副本同步到源结构去
	if(ch == 's')
		*pb = copy;
}





