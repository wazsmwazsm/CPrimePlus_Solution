#include <stdio.h>
#include <stdlib.h>
#define MAX	40

int main(void)
{
	FILE *fp;
	char words[MAX];
	
	if((fp = fopen("words","a+")) == NULL)
		{
			fprintf(stdout,"Can't open \"words\" file.\n");
			exit(1);
		}
		
	printf("Enter words to add to the file; press the Enter.\n");
	puts("key at the beginning of a line to terminate.");
	
	
	while(gets(words) != NULL && words[0] != '\0')
		fprintf(fp,"%s ",words); 						//scanf读取变量直到遇到空白字符，这里加入%s后加入空格划分字符串
	
	puts("File contents:");
	rewind(fp);
	
	while(fscanf(fp,"%s",words) == 1)		//scanf读取变量直到遇到空白字符（空格、换行符、制表符）,只能读取连续的字符串																				
		puts(words);												
		
	if(fclose(fp) != 0)	
		fprintf(stderr,"Error closing file\n");
		
	return 0;
}

