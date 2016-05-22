#include <stdio.h>
#include <string.h>

#define ID_MASK 			0x000FF
#define SIZE_MASK			0x07F00
#define LEFT					0x00000
#define CENTER				0x08000
#define RIGHT					0x10000
#define ALIGN_MASK		0x18000
#define REGULAR				0x00000
#define BOLD					0x20000
#define ITALIC				0x40000
#define UNDERLINE			0x80000
#define STYLE_MASK		0xE0000
#define SIZE_SHIFT		8
#define ALIGN_RIGHT   15
#define BOLD_RIGHT   17
#define ITALIC_RIGHT   18
#define UNDERLINE_RIGHT   19

typedef unsigned long font;

char * align[3] = {"left","center","right"};
char * on_off[2] = {"off","on"};

int getmenu(void);
int getlet(const char *s);
void show(font num);
font get_id(font num);
font get_size(font num);
font change_align(font num);
font change_style(font num, font style);

int main(void)
{
	font sample = 1 | (12 << SIZE_SHIFT) | LEFT | ITALIC;
	int choice ;
	
	show(sample);	
	while((choice = getmenu()) != 'q')
	{
		switch(choice)
			{
				case 'f': sample = get_id(sample);						 
								  break;
				case 's': sample = get_size(sample);
								  break;
				case 'a': sample = change_align(sample);
								  break;
				case 'b': sample = change_style(sample, BOLD);
							 	  break;
				case 'i': sample = change_style(sample, ITALIC);
							    break;
				case 'u': sample = change_style(sample, UNDERLINE);
								  break;
			}
	show(sample);	
	}
	
	puts("Done!");
	
	return 0;
}

font get_id(font num)
{
	int value;
	puts("Enter fount ID (0-255):");
	scanf("%d",&value);
	while(getchar() != '\n');
	
	num &= ~ID_MASK;
	num |= value ;
	
	return num;
}

font get_size(font num)
{
	int value;
	puts("Enter fount SIZE (0-127):");
	scanf("%d",&value);
	while(getchar() != '\n');
	
	num &= ~SIZE_MASK;
	num |= (value << SIZE_SHIFT) ;
	
	return num;
}

font change_align(font num)
{
	 puts("Select alignment:\nl)left  c)center  r)right\n");
	 switch(getlet("lcr"))
	 {
	 	case 'l': num &= ~ALIGN_MASK;
	 						num |= LEFT ; 
	 						break;
	 	case 'c': num &= ~ALIGN_MASK;
	 						num |= CENTER ; 
	 						break;
	 	case 'r': num &= ~ALIGN_MASK;
	 						num |= RIGHT ;  
	 						break;							 	
	 }
	 
	 return num;
}

font change_style(font num, font style)
{
	num ^= style;
	
	return num;
}

void show(font num)
{
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
				 "ID","SIZE","ALIGNMENT","B","I","U");
	printf("%-10ld%-10ld%-10s%-10s%-10s%-10s\n",
				 num & ID_MASK,(num & SIZE_MASK)>>SIZE_SHIFT, 
				 align[(num & ALIGN_MASK)>>ALIGN_RIGHT],
				 on_off[(num & BOLD)>>BOLD_RIGHT],
				 on_off[(num & ITALIC)>>ITALIC_RIGHT],
				 on_off[(num & UNDERLINE)>>UNDERLINE_RIGHT]);	
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