#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL	40
#define MAXAUTL	40
#define MAXBKS	10

#define YES	1
#define NO 0

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int del;
};

int getlet(const char *s);
void updata(struct book *pb);

int main(void)
{
	struct book library[MAXBKS];
	struct book lib_copy[MAXBKS];
	int count = 0, deleted = 0, changed = 0;
	int index ;
	int dindex = 0;
	int line = 0;
	
// ���ļ�	
	FILE *pbooks;
	int size = sizeof(struct book);
	
	if((pbooks = fopen("book.dat","r")) == NULL)
		{
			fputs("Can't open book.dat file.\n",stderr);
			exit(1);
		}
// ��ȡ�ļ����ݵ������ṹ		
	rewind(pbooks);	
	while(count < MAXBKS && fread(&lib_copy[count],size,1,pbooks) == 1)
		{
			if(count == 0)
				puts("Current contents of book.dat: ");
			printf("%d) %s by %s: $%.2f\n", count + 1, lib_copy[count].title,
						lib_copy[count].author, lib_copy[count].value);
			count++;	
		}
	fclose(pbooks);
		
// ѡ��Ŀ¼�����޸Ļ�ɾ��	
	printf("Please enter 1 ~ 10 to select the line to ");
	printf("change or delet: ( enter others to give up )\n");
	while(scanf("%d",&line) == 1 && line >=1 && line <= 10)
		{
			
			while(getchar() != '\n'); // �޳���������
			puts("Do you wish to change or delete this entry? <c/d> ");
			if(getlet("cd") == 'd')
					{	
							lib_copy[line - 1].del = YES;			// ɾ����־λ��λ	
							deleted++;					
					}
			else
					{
							updata(&lib_copy[line - 1]);
							changed++;
					}
						
		printf("Please enter 1 ~ 10 to select the line to ");
		printf("change or delet: ( enter others to give up )\n");	
		}
			scanf("%*s");							// �޳���������
			while(getchar() != '\n'); // �޳���������ֱ�����з�
				
	 if((count - deleted - changed) == MAXBKS)
		{
			puts("The book.dat file is full.");
			exit(2);
		}
	
	
// ��δ��ɾ����Ŀ¼�Ӹ����ṹ���µ�Ŀ¼�ṹ��	
	for(index = 0; index < count; index++)	
			if(lib_copy[index].del != YES)
					library[dindex++] = lib_copy[index];
					
					
		
// �Ӹ��º��Ŀ¼��ʼ��������Ŀ¼	
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while(dindex < MAXBKS && gets(library[dindex].title) != NULL
					&& library[dindex].title[0] != '\0')
		{
			puts("Now enter the author.");
			gets(library[dindex].author);
			puts("Now enter the value.");
			scanf("%f",&library[dindex++].value);
			while(getchar() != '\n');
			if(dindex < MAXBKS)
				puts("Enter the next title.");			
		}	
	if((pbooks = fopen("book.dat","w")) == NULL)
		{
			fputs("Can't open book.dat file.\n",stderr);
			exit(1);
		}		
// ��ʾ�������ļ�		
	if(dindex > 0)
		{
			puts("Here is the list of your books: ");
			for(index = 0; index < dindex; index++)
				printf("%d) %s by %s: $%.2f\n", index + 1, library[index].title,
						library[index].author, library[index].value);
			rewind(pbooks);
			fwrite(&library[0], size, dindex, pbooks); // ��7_1��ͬ���ǣ��ڼ������Ѿ�ɾ����ȱ�����Կ���һ��д�����ж�
		}
	else
		puts("No books? Too bad.");	

	fclose(pbooks);
	
	puts("Bye!");
	
	return 0;
}

// �˺��������ַ����е�һ���ַ�,Ҳ����ֱ�Ӷ�ȡ�ж�

int getlet(const char *s)
{
	char c;
	
	c = getchar();
	// ���ַ���s����Ѱ�ַ�c
	while(strchr(s, c) == NULL)
		{
			printf("Enter a character in the list %s.\n",s);
			while(getchar()!='\n');
			
			c = getchar();
		}
	while(getchar()!='\n');
	
	return c;
}


void updata(struct book *pb)
{
	struct book copy;
	char ch ;
		
	copy = *pb;
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title			a) modify author");
	puts("v) modify value			s) quit and saving changes");
	puts("q) quit and ignore changes");
	
	while((ch = getlet("tavsq")) != 's' && ch != 'q')
	{
		switch (ch)
		{
			case 't': puts("Enter new title:");															
								gets(copy.title);
								break;
			case 'a': puts("Enter new author:");														
								gets(copy.author);
								break;
			case 'v': puts("Enter new value:");
								while(scanf("%f",&copy.value) != 1)
								{
									puts("Enter a numberic value:");
									scanf("%*s");
								}
								while(getchar() != '\n');
								break;			
		}
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title			a) modify author");
	puts("v) modify value			s) quit and saving changes");
	puts("q) quit and ignore changes");		
	}
	if(ch == 's')
		*pb = copy;
}





