#include <stdio.h>
#include <string.h>

struct {
	unsigned int id				 :8;
	unsigned int size			 :7;
	unsigned int alignment :2;
	unsigned int bold			 :1;
	unsigned int italic		 :1;
	unsigned int underline :1;
} font;


char * align[3] = {"left","center","right"};
char * on_off[2] = {"off","on"};

int getmenu(void);
int getlet(const char *s);

int main(void)
{
	int value = 0;
	int choice ;
	
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
				 "ID","SIZE","ALIGNMENT","B","I","U");
	printf("%-10d%-10d%-10s%-10s%-10s%-10s\n",
				 font.id,font.size,align[font.alignment],
				 on_off[font.bold],on_off[font.italic],on_off[font.underline]);
	
	while((choice = getmenu()) != 'q')
	{
		switch(choice)
			{
				case 'f':puts("Enter fount ID (0-255):");
								 scanf("%d",&value);
								 while(getchar() != '\n');
								 font.id = value ;								 
								 break;
				case 's':puts("Enter fount size (0-127):");
								 scanf("%d",&value);
								 while(getchar() != '\n');
								 font.size = value;
								 break;
				case 'a':puts("Select alignment:\nl)left  c)center  r)right\n");
								 switch(getlet("lcr"))
								 {
								 	case 'l': font.alignment = 0; 
								 						break;
								 	case 'c': font.alignment = 1; 
								 						break;
								 	case 'r': font.alignment = 2;  
								 						break;							 	
								 }
								 break;
				case 'b':font.bold = !font.bold;
								 break;
				case 'i':font.italic = !font.italic;
								 break;
				case 'u':font.underline = !font.underline;
								 break;
			}
		
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
				 "ID","SIZE","ALIGNMENT","B","I","U");
	printf("%-10d%-10d%-10s%-10s%-10s%-10s\n",
				 font.id,font.size,align[font.alignment],
				 on_off[font.bold],on_off[font.italic],on_off[font.underline]);		
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