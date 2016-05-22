#include <stdio.h>
extern void srand1(unsigned int seed);
extern int rand1(void);

int main(void)
{
	int count;
	unsigned int seed;
	
	printf("Enter your choice for seed.\n");
	while(scanf("%u", &seed) == 1)
		{
			srand1(seed);
			for(count = 0; count < 5; count++)
				printf("%hd\n",rand1());
				
		printf("Enter next seed (q to qiut).\n");	
		}
	return 0;
}
