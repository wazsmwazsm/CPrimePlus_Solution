/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
	int x,y;
	char ch;
	
	printf("input a char:");
	scanf("%c",&ch);
	while(getchar()!='\n');
	printf("input two integer:");
	scanf("%d%d",&x,&y);	
	while(getchar()!='\n');
	chline(ch,x,y);

return 0;
}

void chline(char ch, int i, int j)
{
	int k;
	for(k=0; k<i; k++)
		printf(" ");
	for(;k<j;k++)
		printf("%c",ch);
	printf("\n");
}
