#include <stdio.h>
#include <string.h>

struct fonts{
	unsigned int id				 :8;
	unsigned int size			 :7;
	unsigned int alignment :2;
	unsigned int bold			 :1;
	unsigned int italic		 :1;
	unsigned int underline :1;
};

char * align[3] = {"left","center","right"};
char * on_off[2] = {"off","on"};

int getmenu(void);
int getlet(const char *s);
void show(struct fonts num);
void get_id(struct fonts *num);
void get_size(struct fonts *num);
void change_align(struct fonts *num);
int change_style(int num);

int main(void)
{
	struct fonts font;
	int choice ;
	
	show(font);	
	while((choice = getmenu()) != 'q')
	{
		switch(choice)
			{
				case 'f': get_id(&font);						 
								  break;
				case 's': get_size(&font);
								  break;
				case 'a': change_align(&font);
								  break;
				case 'b': font.bold = change_style(font.bold);
							 	  break;
				case 'i': font.italic = change_style(font.italic);
							    break;
				case 'u': font.underline = change_style(font.underline);
								  break;
			}
	show(font);	
	}
	
	puts("Done!");
	
	return 0;
}
// 传入结构地址，因为只传入结构的话只是改变了副本，需要返回才能使用
void get_id(struct fonts *num)
{
	int value;
	puts("Enter fount ID (0-255):");
	scanf("%d",&value);
	while(getchar() != '\n');
	num->id = value ;
}

void get_size(struct fonts *num)
{
	int value;
	puts("Enter fount SIZE (0-127):");
	scanf("%d",&value);
	while(getchar() != '\n');
	num->size = value ;
}

void change_align(struct fonts *num)
{
	 puts("Select alignment:\nl)left  c)center  r)right\n");
	 switch(getlet("lcr"))
	 {
	 	case 'l': num->alignment = 0; 
							break;
	 	case 'c': num->alignment = 1; 
	 						break;
	 	case 'r': num->alignment = 2;  
	 						break;						 	
	 }
}

int change_style(int num)
{
	return !num;
}
// 这个函数无需传入地址，因为无需改变结构。传入的话用const声明
void show(struct fonts num)
{
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
				 "ID","SIZE","ALIGNMENT","B","I","U");
	printf("%-10d%-10d%-10s%-10s%-10s%-10s\n",
				 num.id,num.size,align[num.alignment],
				 on_off[num.bold],on_off[num.italic],on_off[num.underline]);
}

int getmenu(void)
{
	printf("f) change font   s) change size");
	printf("   a) change alignment\nb) toggle bold");
	printf("   i) toggle italic   u) toggle underline\n");
	puts("q) quit");
	
	return getlet("fsabiuq");
}

int getlet(const char *s)
{
	char c;
	
	c = getchar();
	while(strchr(s,c) == NULL)
		{
			puts("Enter a character in the list.");
			while(getchar() != '\n');
			c = getchar();
		}
	while(getchar() != '\n');
	
	return c;	
}