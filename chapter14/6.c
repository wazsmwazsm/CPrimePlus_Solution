#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMEMAX	30
#define P_NUM	18		// �ܹ�18����Ա

char filename[NAMEMAX];  // ��Ϊȫ�ֱ�������������������ȡ

struct baseball {
	
	char first_name[NAMEMAX];
	char last_name[NAMEMAX];
	int bat;
	int hit;
	int walk;
	int rbi;
	float average;
};

void init_struct(struct baseball p[]);
void get_info(struct baseball p[]);
void cal_average(struct baseball p[]);
char * Output(struct baseball p[]);
void display( char *str);

int main(void)
{
	struct baseball person[P_NUM];
	// ��ʼ��
	init_struct(person);
	// ��ȡ��Ϣ
	get_info(person);
	// ����ƽ��ֵ
	cal_average(person);
	// ��ʾ����ļ�������
	display(Output(person));
	
	return 0;
}

// ��ʼ���ṹ

void init_struct(struct baseball p[])
{
	int i;
	for(i=0; i<P_NUM; i++)
		{
			strcpy(p[i].first_name, "");
			strcpy(p[i].last_name, "");
			p[i].bat = 0;
			p[i].hit = 0;
			p[i].walk = 0;
			p[i].rbi = 0;
			p[i].average = 0;
		}	
};

// ���ļ���ȡ��Ϣ����

void get_info(struct baseball p[])
{
	int num, bat, hit, walk, rbi;
	char firstname[NAMEMAX], lastname[NAMEMAX];
	
	FILE *fp;
	puts("Enter the file name:");
	gets(filename);
	if((fp = fopen(filename,"r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n",filename);
			exit(1);
		}
	// ���ļ���ʼ��ȡ��Ϣ���ṹ��
	while(fscanf(fp," %d %s %s %d %d %d %d\n",
				&num,firstname,lastname,&bat,&hit,&walk,&rbi) == 7)
		{
			strcpy(p[num - 1].first_name, firstname);  // �����0��ʼ�������Ҫ��1
			strcpy(p[num - 1].last_name, lastname);
			p[num - 1].bat += bat;
			p[num - 1].hit += hit;
			p[num - 1].walk += walk;
			p[num - 1].rbi += rbi;
	
		}
	if(fclose(fp) != 0)
		fprintf(stderr, "Can't close file %s\n",filename);
}

// ����ƽ��ֵ����

void cal_average(struct baseball p[])
{
	int i;
	for(i=0; i<P_NUM; i++)
		if(p[i].bat)
			p[i].average = (float) p[i].hit / (float) p[i].bat;
}

// �����������ļ����������ļ�������

char * Output(struct baseball p[])
{
	int i;
	FILE *fp;
	static char fexdname[NAMEMAX]; // static ����ʹ�ַ���ָ�������ȷ����
	struct baseball total = {"","",0,0,0,0,0}; // ͳ��ȫ������
	
	// ���ļ�������
	strcpy(fexdname,filename);
	strcat(fexdname,".exd");
	
	if((fp = fopen(fexdname,"w")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n",fexdname);
			exit(2);
		}
		
		
	fprintf(fp,"%7s%10s%10s%5s%5s%5s%5s%10s\n","number","firstname",
				"lastname","bat","hit","walk","RBI","average");
	
	for(i=0; i<P_NUM; i++)		
			if(p[i].bat)  // �������
			{
				fprintf(fp,"%7d%10s%10s%5d%5d%5d%5d%10g\n", i + 1, p[i].first_name,
				p[i].last_name, p[i].bat, p[i].hit, p[i].walk,
				p[i].rbi, p[i].average);
				
				total.bat += p[i].bat;
				total.hit += p[i].hit;
				total.walk += p[i].walk;
				total.rbi += p[i].rbi;
			}
	
	if(total.bat)
		total.average = (float) total.hit / (float) total.bat;
	fprintf(fp,"\n\n%27s%5d%5d%5d%5d%10g\n\n", "total team", total.bat, total.hit,
				total.walk, total.rbi, total.average);
				
	if(fclose(fp) != 0)
		fprintf(stderr, "Can't close file %s\n",fexdname);	
		
	return fexdname;
}

void display( char *str)
{
	FILE *fp;
	char ch;
	if((fp = fopen(str,"r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n",str);
			exit(2);
		}
		
	while((ch = getc(fp)) != EOF)
		putc(ch,stdout);
		
	if(fclose(fp) != 0)
		fprintf(stderr, "Can't close file %s\n",str);	
}

