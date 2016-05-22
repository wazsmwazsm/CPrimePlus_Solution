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
		fprintf(fp,"%s ",words); 						//scanf��ȡ����ֱ�������հ��ַ����������%s�����ո񻮷��ַ���
	
	puts("File contents:");
	rewind(fp);
	
	while(fscanf(fp,"%s",words) == 1)		//scanf��ȡ����ֱ�������հ��ַ����ո񡢻��з����Ʊ����,ֻ�ܶ�ȡ�������ַ���																				
		puts(words);												
		
	if(fclose(fp) != 0)	
		fprintf(stderr,"Error closing file\n");
		
	return 0;
}

