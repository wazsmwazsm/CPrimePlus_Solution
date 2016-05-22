/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
long Fib(int n);
int main(void)
{
	int n;
	printf("Enter an integer (q to quit):\n");
	while(scanf("%d",&n) == 1)
	{
		printf("The term %d of Fibonacci sequance is %ld\n",n,Fib(n));
		while(getchar() != '\n');
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
		
	}
	printf("Done. \n");
return 0;
}

long Fib(int n)
{
	int n1, n2, temp, i;
	if(n > 2)
		 for(n1=1, n2=1, i=3; i<=n; i++)
				{
					temp = n1+n2;
					n1 = n2;
					n2 = temp;	
				}
	else
		n2 = 1;

	return n2;	
}