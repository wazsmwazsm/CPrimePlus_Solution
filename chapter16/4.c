#include <stdio.h>
#include <time.h>

void delay(double time);

int main(void)
{
	double time;
	puts("Enter a time(in seconds, q to quit):");
	while(scanf("%lf",&time) == 1)
	{
		delay(time);
		printf("Time is out!\n");
		puts("Enter a time(in seconds, q to quit):");
	}
	
	puts("Done!");
	return 0;
}

void delay(double time)
{
	double origin;
	origin = clock() / CLOCKS_PER_SEC;
	while((clock() / CLOCKS_PER_SEC) < (origin + time));
	
}


