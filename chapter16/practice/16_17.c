#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

void showarray(const int ar[], int n);

int main(void)
{
	int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	int target[SIZE];
	double curious[SIZE / 2] = {1.0, 2.0, 3.0, 4.0, 5.0};
	
	puts("memcpy() used: ");
	puts("values (original dara):");
	
	showarray(values,SIZE);
	memcpy(target,values,SIZE * sizeof(int));
	puts("target (copy of values):");
	showarray(target,SIZE);
	
	puts("\nUsing memmove() with overlapping ranges:");
	memmove(values + 2, values, 5 * sizeof(int));
	puts("values -- elements 0-5 copied to 2-7");
	showarray(values,SIZE);
	
	puts("\nUsing memcpy() to copy double to int:");
	memcpy(target, curious, (SIZE/2) * sizeof(double));
	puts("target -- 5 double into 10 int positions:");
	showarray(target,SIZE);
	
	return 0;
}

void showarray(const int ar[], int n)
{
	int i;
	
	for(i=0; i<n; i++)
		printf("%4d",ar[i]);
	putchar('\n');
}

