#include <stdio.h>
int gap(int *, int );

int main(void)
{
	int arr[] = {4,5,6,3,2,8};
	
	printf("The gap between max and min is:%d\n",gap(arr,sizeof arr / sizeof arr[0]));
	
	return 0;
}
int gap(int *ar, int n)
{
	int i,max,min;

	for(i=1, max=ar[0], min = ar[0]; i<n; i++)
		{
			if(max< ar[i]) max = ar[i];
			if(min> ar[i]) min = ar[i];
		}	
	return max - min;
	
}