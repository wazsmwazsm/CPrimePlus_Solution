#include <stdio.h>
#define MAXLINE	20
int main(void)
{
	char line[MAXLINE];
	
	while(fgets(line,MAXLINE,stdin ) != NULL && line[0] != '\n')   //gets����˻��з�������fgets����
		fputs(line,stdout);
	
	
	
	return 0;
}

