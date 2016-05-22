#include <stdio.h>
int max(int *, int );

int main(void)
{
	int arr[] = {4,5,6,3,2,8};
	
	printf("The max numnber's index is:%d\n",max(arr,sizeof arr / sizeof arr[0]));
	
	return 0;
}
int max(int *ar, int n)
{
	int i,max;

	for(i=1, max=0; i<n; i++)
		if(ar[max]< ar[i])
			max = i;
			
	return max;
	
}

