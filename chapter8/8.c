/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
#include <ctype.h>
#define STARS      "****************************************"
#define   QUIT   'q'

int menu(void);
float get_float(void);
char get_first(void);


int main(void)
{
	char choice;
	float num1,num2;
	
	while((choice = tolower(menu())) != QUIT )
	{
		
		if(choice < 'a' || choice > 'd')
			{
				printf("Please enter a, b, c, d, or q.\n");
				continue;
			}
	
		printf("Enter first number:");	
		num1 = 	get_float();
		printf("Enter second number:");
		num2 = 	get_float();
		
//		while((choice == 'd') && (num2 == 0))
//			{
//				printf("Enter a number other than 0:");
//				num2 = 	get_float();
//			}	
			
		switch (choice)
		{
			case 'a':printf("%.2f + %.2f = %.2f\n",num1,num2,num1 + num2);
				break;	
			case 'b':printf("%.2f - %.2f = %.2f\n",num1,num2,num1 - num2);
				break;
			case 'c':printf("%.2f * %.2f = %.2f\n",num1,num2,num1 * num2); 
				break;			
			case 'd':
							 while((choice == 'd') && (num2 == 0))
							 {
								 printf("Enter a number other than 0:");
								 num2 = get_float();
							 }	
							 printf("%.2f / %.2f = %.2f\n",num1,num2,num1 / num2); 
					     break;			
			default:
				break;
		}
	}

return 0;
}

int menu(void)
{
	
	char ch;
	printf("\n%s%s\n",STARS,STARS);
	printf("Enter the operation of your choice:\n");
	printf("a. add\t\t\tb. substact\n");
	printf("c. multiply\t\td. divide\n");
	printf("q) quit \n");
	printf("\n%s%s\n",STARS,STARS);
	
	ch = get_first();
	
	return ch ;
	
}

float get_float(void)
{
	float num;
	char ch;
	while(scanf("%f",&num) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		
		printf(" is not an number.\nPlease enter ");
		printf("an number, such as 2.5, -1.78E8, or 3:");
		
	}
	while( getchar() != '\n');
	return num;
}

char get_first(void)
{
	char ch;
	while(isspace(ch=getchar()));
	while(getchar() != '\n');
	return ch;
}

