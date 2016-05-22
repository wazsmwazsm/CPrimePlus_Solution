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
int getbook(struct book *pb);
void updata(struct book *pb);

int main(void)
{
	struct book library[MAXBKS]; // ����ṹ����
	int count = 0;	// count���������ȡ�ļ����ݼ���
	int index, oindex;	// index ��������ɺ�ṹ��ȡ��������oindex ����ȡ����Ŀ¼������
	int deleted = 0;  // ���ڼ�¼ɾ������
	FILE *pbooks;
	int size = sizeof(struct book);
	
	
	if((pbooks = fopen("book.dat","rb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n","book.dat");
			exit(1);
		}
	
	rewind(pbooks); // �ļ�ָ�뷵��ԭ��
	
// ������ģʽ��ȡ�ļ����ݵ��ṹ������ʾ�Ƿ��޸Ļ�ɾ������Ŀ¼	
	while(count < MAXBKS && fread(&library[count], size,
				1,pbooks) == 1)
		{
			if(count == 0)
				puts("Current contents of book.dat:");
				
			printf("%d) %s by %s: $%.2f\n", count + 1, library[count].title,
							library[count].author, library[count].value);
			
			puts("Do you wish to change or delete this entry? <y/n> ");
			if(getlet("yn") == 'y')
				{
					puts("Enter c to change , d to delet entry:");
					if(getlet("cd") == 'd')
					{
						library[count].del = YES;  // ���Ҫɾ�������ṹ��ɾ����־λ��Ϊ 1	
						deleted++;				
						puts("Enter marked for deletion.");
					}
					else
						updata(&library[count]);
				}
				
			count++;
		}
		fclose(pbooks);
/* 
	����ļ���Ա���˳�		
  (count - deleted) �������ļ���Ա������ɾ��Ŀ¼�������ʹ�ã�
  �Ա����ɾ����Ա�ļ���Ŀ¼, û��ɾ���Ļ�����Ա�˳� 
*/
	if((count - deleted) == MAXBKS)  
		{
			puts("The book.dat file is full.");
			exit(2);
		}
		
// 	�����µ��鱾Ŀ¼�������������˳�	
	puts("Plaese add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	
	for(oindex = 0; oindex < MAXBKS; oindex++)
		{
			if(library[oindex].del == YES || oindex >= count)
				{
					if(getbook(&library[oindex])) 
						{
							if(library[oindex].del == YES) 
								oindex = count; // ���û�������Ŀ¼ȴɾ��Ŀ¼��Ϊ��ʾ֮ǰ����Ŀ������ɾ���ģ�����
							break;					
						}
						
					puts("Plaese add new book titles.");
					puts("Press [enter] at the start of a line to stop.");
				}
		}
	if((pbooks = fopen("book.dat","wb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n","book.dat");
			exit(1);
		}
// �ļ�ָ���λ�������º�Ľṹ���ڴ�д�뵽�ļ���				
		rewind(pbooks);		
// ��ȡ��Ϻ���ʾ���º��Ŀ¼
	if(oindex > 0 ) 
		{	
			puts("Here is the list of your books:");
			for(index = 0; index < oindex; index++)
				if(library[index].del != YES)
					{
						printf("%d) %s by %s: $%.2f\n",index, library[index].title,
									library[index].author, library[index].value);
						
						fwrite(&library[index],size, 1, pbooks);	
					}
		}		
	else
		puts("No books? Too bad.");	
		
	fclose(pbooks);	// �ر��ļ����������
	
	puts("Done!");
	
	return 0;
}

// �����ȡ�ַ�ch���ַ���s�У��򷵻��ַ�ch��������ʾ��������

int getlet(const char *s)
{
	char ch;
	
	ch = getchar();
	// ���ַ���s����Ѱ�ַ�ch
	while(strchr(s, ch) == NULL)
		{
			printf("Enter a character in the list %s.\n",s);
			while(getchar()!='\n');
			
			ch = getchar();
		}
	while(getchar()!='\n');
	
	return ch;
}

// ��ȡ���麯��

int getbook(struct book *pb)
{			
	// ���������У����� 1 ʹѭ��break					
			if(gets(pb->title) == NULL || pb->title[0] == '\0')
					return 1;
					
	// �����ɾ���еĻ�����ɾ����־λ�� 0				
			if(pb->del == YES)
				pb->del = NO;
	// ��ȡ����				
			printf("Now enter the author: \n");
			gets(pb->author);
	// ��ȡ�۸񣬲��޳���������		
			printf("Now enter the value:\n");
			while(scanf("%f",&pb->value) != 1)
				{
					puts("Please use numberic input");
					scanf("%*s");
				}
			while(getchar() != '\n');		// �޳��س���
			
			return 0;		// ������ȡ�Ļ����� 0
}

// ���º��� 

void updata(struct book *pb)
{
	struct book copy;
	char ch ;
	
	// ����������ռʱ�洢��������	
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
								strcpy(copy.title," ");								
								break;
			case 'a': puts("Enter new author:");
								strcpy(copy.author," ");								
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
	
	// ���Ҫ���棬�Ѹ���ͬ����Դ�ṹȥ
	if(ch == 's')
		*pb = copy;
}





