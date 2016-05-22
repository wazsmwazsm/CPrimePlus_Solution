#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 100
void sort_ar(int *ar, int limit);
void print_ar(const int *ar, int limit);

int main(void)
{
	int i;
	int ar[LEN];
	srand((unsigned int)time(0));
	for(i=0; i<LEN; i++)
			ar[i] = rand()%100 + 1;
	puts("Initial array");
	print_ar(ar, LEN);	
	sort_ar(ar, LEN);
	puts("sorted array");
	print_ar(ar, LEN);
	
	
	return 0;
}

void sort_ar(int *ar, int limit)
{
	int top,seek;
	int temp = 0;
	
	for(top = 0; top < limit - 1; top++)
		for(seek = top + 1; seek < limit; seek++)
			if(ar[seek] < ar[top])
			{
				temp = ar[seek];
				ar[seek] = ar[top];
				ar[top] = temp;
			}
}

void print_ar(const int *ar, int limit)
{
	int i;
	for(i=0; i<limit; i++)
		{
			printf("%5d",ar[i]);	
			if(i%10 == 9)
				putchar('\n');
		}
	if(i%10 != 0)
		putchar('\n');
}

