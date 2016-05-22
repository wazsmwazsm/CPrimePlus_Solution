#include <stdio.h>
#define MAXLINE	20
int main(void)
{
	char line[MAXLINE];
	
	while(fgets(line,MAXLINE,stdin ) != NULL && line[0] != '\n')   //gets会过滤换行符，但是fgets不会
		fputs(line,stdout);
	
	
	
	return 0;
}

