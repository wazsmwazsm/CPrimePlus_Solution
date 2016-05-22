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

int main(void)
{
	font sample = 1 | (12 << SIZE_SHIFT) | LEFT | ITALIC;
	int value = 0;
	int choice ;
	
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
				 "ID","SIZE","ALIGNMENT","B","I","U");
	printf("%-10ld%-10ld%-10s%-10s%-10s%-10s\n",
				 sample & ID_MASK,(sample & SIZE_MASK)>>SIZE_SHIFT, 
				 align[(sample & ALIGN_MASK)>>ALIGN_RIGHT],
				 on_off[(sample & BOLD)>>BOLD_RIGHT],
				 on_off[(sample & ITALIC)>>ITALIC_RIGHT],
				 on_off[(sample & UNDERLINE)>>UNDERLINE_RIGHT]);
	
	while((choice = getmenu()) != 'q')
	{
		switch(choice)
			{
				case 'f':puts("Enter fount ID (0-255):");
								 scanf("%d",&value);
								 while(getchar() != '\n');
								 sample &= ~ID_MASK;
								 sample |= value ;								 
								 break;
				case 's':puts("Enter fount size (0-127):");
								 scanf("%d",&value);
								 while(getchar() != '\n');
								 sample &= ~SIZE_MASK;
								 sample |= (value << SIZE_SHIFT) ;
								 break;
				case 'a':puts("Select alignment:\nl)left  c)center  r)right\n");
								 switch(getlet("lcr"))
								 {
								 	case 'l': sample &= ~ALIGN_MASK;
								 						sample |= LEFT ; 
								 						break;
								 	case 'c': sample &= ~ALIGN_MASK;
								 						sample |= CENTER ; 
								 						break;
								 	case 'r': sample &= ~ALIGN_MASK;
								 						sample |= RIGHT ;  
								 						break;							 	
								 }
								 break;
				case 'b':sample ^= BOLD;
								 break;
				case 'i':sample ^= ITALIC;
								 break;
				case 'u':sample ^= UNDERLINE;
								 break;
			}
		
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
				 "ID","SIZE","ALIGNMENT","B","I","U");
	printf("%-10ld%-10ld%-10s%-10s%-10s%-10s\n",
				 sample & ID_MASK,(sample & SIZE_MASK)>>SIZE_SHIFT, 
				 align[(sample & ALIGN_MASK)>>ALIGN_RIGHT],
				 on_off[(sample & BOLD)>>BOLD_RIGHT],
				 on_off[(sample & ITALIC)>>ITALIC_RIGHT],
				 on_off[(sample & UNDERLINE)>>UNDERLINE_RIGHT]);	
	}
	
	puts("Done!");
	
	return 0;
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