#include <stdio.h>
int Fibonacci(int n);
int count = 0;


int main(void)
{
	int n;
	printf("Enter the max term of Fibonacci:\n");
	while(scanf("%d",&n) == 1)
	{		
		printf("The Fibonacci is %d:\n",Fibonacci(n));
		printf("The function of Fibonacci has call %d times.\n",count);
		printf("Enter the max term of Fibonacci:\n");
	}
	return 0;
}

int Fibonacci(int n)
{
	count++;
	if(n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return 1;
}

