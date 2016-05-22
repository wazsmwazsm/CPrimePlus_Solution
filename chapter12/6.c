#include <stdio.h>
#include <stdlib.h>

void count_rand(int *ar);

int main(void)
{
	int i;
	int count[10] = {0};
	
	for(i=0; i<10; i++)
		{
			printf("seek = %d\n",i);
			srand(i);
			count_rand(count);
		}
	putchar('\n');	

	return 0;
}

void count_rand(int *ar)
{
	
	int j;

	for(j=0; j< 1000; j++)
		ar[rand()%10]++;
	for(j=0; j<10; j++)
		{
			printf("%d: %d times\t",j,ar[j]);
			if(j%5 == 0 && j!=0)
				putchar('\n');
		}
				putchar('\n');	
}

