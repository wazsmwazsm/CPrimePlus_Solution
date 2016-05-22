#include <stdio.h>
#define NUM	4

float add(float x, float y);
float substract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);
void showmenu(void);

int main(void)
{
	float (*pf[NUM])(float , float) = {add,substract,multiply,divide}; 
// Лђеп typedef float (*PF[NUM])(float , float);
// 			PF pf = {add,substract,multiply,divide}; 
	
	int choice = 0;
	float x,y;
		
	showmenu();
	while(scanf("%d",&choice) == 1 )
		{
			while(getchar() != '\n');
			if(choice <= 0 || choice > 4)
				{
					puts("Enter 1 ~ 4 or q.");
					continue;
				}
			puts("Enter x and y.");
			scanf("%f %f",&x, &y);
			while(getchar() != '\n');
			printf("result is : %g.\n",pf[choice - 1](x,y));
			showmenu();
		}
		
	puts("Bye.");
	
	return 0;
}

void showmenu(void)
{
	printf("Select function:\n");
  printf("1 :  x + y\n");
  printf("2 :  x - y\n");
  printf("3 :  x * y\n");
  printf("4 :  x / y\n");
  printf("q :  quit\n");

}
float add(float x, float y)
{
	return x + y;	
} 

float substract(float x, float y)
{
	return x - y;	
} 
float multiply(float x, float y)
{
	return x * y;	
} 
float divide(float x, float y)
{
	return x / y;	
} 
