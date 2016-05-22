#include <stdio.h>
#include <stdlib.h>
int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int *pa;
	int size;
	int value;
	
	printf("Enter the number of element:");
	scanf("%d", &size);
	while(getchar()!= '\n');
	while(size > 0)
	{
		printf("Enter the initialization value:");
		scanf("%d",&value);
		pa = make_array(size,value);
		if(pa)
			{
				show_array(pa, size);
					free(pa);
			}
			
	printf("Enter the number of element(<1 to quit):");
	scanf("%d", &size);
	while(getchar()!= '\n');
	}
	return 0;
}

int *make_array(int elem, int val)
{
	int *pa;
	int i;
	pa = (int *)malloc(elem * sizeof(int));
	for(i=0; i<elem; i++)
		pa[i] = val;
	
	return pa;
}

void show_array(const int ar[], int n)
{
	int i;
	for(i=0; i<n; i++)
		{
			printf("%3d",ar[i]);
			if(i%8 == 7) printf("\n");
		}
	printf("\n");
}


