/*
* function£ºprint out 
*
*									    A
*									   ABA
*									  ABCBA
*									 ABCDCDA
*									ABCDEDCBA
*/

#include <stdio.h>

int main(void)
{
	int i,j,k;
	char letter;
	printf("Please input a capital:");
	scanf("%c",&letter);
	
	k = letter - 'A' + 1;
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-i;j++)  printf(" ");         //print " "
		for(j=0;j<=i;j++)    printf("%c",'A'+j);  //print capital sequence 
		for(j=i-1;j>=0;j--) printf("%c",'A'+j);  //print capital Reverse
		
		printf("\n");
	}

	
return 0;
	
}