#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char getlet(char * str);
char menu(void);
void printitem(Item item);
void ShowWords(const Tree * ptree);
void lowercase(char *str);
void findword(const Tree * ptree);
bool MakeStr(char *str, FILE *fp);

inline void eatline(void)
{
	while(getchar() != '\n');
}


int main(void)
{
	Tree wordcount;
	Item word_item;
	
	FILE * fp;
	char filename[SLEN];
	char word[SLEN];
	char choice;
	char ch;
	
	puts("Enter name of file to be processed:");
	gets(filename);
	
	if((fp = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s",filename);
		exit(EXIT_FAILURE);
	}
	
	InitializeTree(&wordcount);
	
/* 此处直接读取字符串，但是会把标点符号读入   */		
/*	
	while(fscanf(fp,"%s",word) == 1 && !TreeIsFull(&wordcount))
	{
		lowercase(word);
		strcpy(word_item.words, word);
		AddItem(&word_item, &wordcount);		
	}
*/		

/* 改良后只读取单词，推荐，新定义了MakeStr函数   */	
	while((MakeStr(word, fp) == true) && !TreeIsFull(&wordcount))
	{
		lowercase(word);
		strcpy(word_item.words, word);
		AddItem(&word_item, &wordcount);		
	}
	
	while((choice = menu()) != 'q' )
	{
		switch(choice)
			{
				case 's': ShowWords(&wordcount);
									break;
				case 'f': findword(&wordcount);
									break;
				default : puts("Switching error");			
			}	
	}
	if(fclose(fp) != 0)
		{
			fprintf(stderr,"Can't close file %s",filename);
			exit(EXIT_FAILURE);
		}
	puts("Done!");
	
	return 0;
}

void ShowWords(const Tree * ptree)
{
	if(TreeIsEmpty(ptree))
		puts("No entries!");
	else
		Traverse(ptree,printitem);
}

void findword(const Tree * ptree)
{
	Item item;
	const Item * pi;
	
	if(TreeIsEmpty(ptree))
	{
		puts("No entries!");
		return;
	}
	
	puts("Please enter the word to find:");
	gets(item.words);
	lowercase(item.words);
	
	pi = WhereInTree(&item,ptree);
	if(pi == NULL)
		printf("%s is not in the list.\n",item.words);
	else
		printf("%s appears %d times.\n",pi->words,pi->count);	
}

char menu(void)
{
	int ch;
	
	puts(" word counting program ");
	puts(" Enter the letter corresponding to your choice ");
	puts(" s)show word list  f)find a word ");
	puts(" q)quit ");
	
	ch = getlet("sfq");
	
	return ch;
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

void printitem(Item item)
{
	printf("%s is appeared %d times\n",item.words,item.count);
}

void lowercase(char *str)
{
	while(*str)
	{
		*str = tolower(*str);	
		str++;
	}
}


/* 名称：MakeStr */
/* 输入：一个字符串(数组)，一个文件指针 */
/* 输出：一个布尔值 */
/* 功能：读取文件中的单词，并存储在字符串str中 */
/* 每次调用存储一个单词，读到文件尾返回false，反之返回true */

bool MakeStr(char *str, FILE *fp)
{
	char ch;
	char *temp = str;
	while((ch = getc(fp)) != EOF && isalpha(ch))
		{
			*str = ch;
			str++;
		}
	*str = '\0';
	str = temp;
	
	if(ch == EOF)
		return false;
	else
		return true;
}

