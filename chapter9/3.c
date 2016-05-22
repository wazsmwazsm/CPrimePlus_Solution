/*
*	name:
*	function:
*	
*
*/

#include <stdio.h>
void chline(char ch, int row, int column);
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

void chline(char ch, int row, int column)
{
	int x,y;
	for(x=0; x<row; x++)
	{
		for(y=0; y<column; y++)
			printf("%c",ch);
		
		printf("\n");
	}
}