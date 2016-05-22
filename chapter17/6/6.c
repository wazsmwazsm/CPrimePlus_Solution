#include <stdio.h>
#include <stdlib.h>
#define NUM 10

void showarray(const int ar[], int n);
void InputArray(int *ar, int n);
int mycomp(const void * p1, const void * p2);
void showarray(const int ar[], int n);
int search(const int ar[], int n, int sch);

int main(void)
{
	int vals[NUM];
	int sch, position;
	
	// 初始化数组并显示
	InputArray(vals,NUM);
	puts("List you input:");
	showarray(vals,NUM);
	
	// 排序后并显示
	qsort(vals,NUM,sizeof(int),mycomp);
	puts("List when sorted:");
	showarray(vals,NUM);
	
	// 进行二分搜索，判断要查询的数是否在数组中
	puts("Now we search a number from array, enter the number:");
	
	scanf("%d",&sch);
		while(getchar() != '\n');
	
	if((position = search(vals,NUM,sch)) != 0)
		printf("The number is in array, index: %d!\n",position+1);
	else
		printf("The number is not in array!\n");
		
	return 0;
}

// 输入值到数组
void InputArray(int *ar, int n)
{
	int index;
	
	printf("Enter %d numbers for the array:\n",n);
	for(index = 0; index < n; index++)
		{
			printf("number %d:\n",index+1);
			scanf("%d",&ar[index]);
			while(getchar() != '\n');
		}
}

// 显示数组
void showarray(const int ar[], int n)
{
	int index;
	
	for(index = 0; index < n; index++)
		{
			printf("%9d",ar[index]);
			if(index % 6 == 5)
				putchar('\n');
		}
	if(index % 6 != 0)
		putchar('\n');
}


// 提供给qsort函数做参数的比较函数
int mycomp(const void * p1, const void * p2)
{
	const int * a1 = (const int *)p1;
	const int * a2 = (const int *)p2;
	
	if(*a1 < *a2)
		return -1;
	else if(*a1 == *a2)
		return 0;
	else
		return 1;
}
/* 二分搜索函数 */
/* if search successful, return num position */
/* else return 0                             */

int search(const int ar[], int n, int sch)
{
	int min = 0;
	int half;
	
	while(min <= n)
	{
		half = (min + n) / 2;
		if(sch > ar[half])
			min = half + 1;
		else if(sch < ar[half])
			n = half - 1;
		else
			return half;	
	}
	
	return 0;
}


