#include <stdio.h>
#define NAMELEN	20
#define N 5

struct names{
	char firstname[NAMELEN];
	char middlename[NAMELEN];
	char lastname[NAMELEN];
};

struct persons{
	char number[10];
	struct names name;
};

struct persons person[N] = {
	{"302255402",{"Dribble","Mackede","Flossie"}},
	{"302255524",{"Gadenfs","","Plose"}},
	{"302255425",{"Marry","Lorrola","Flessil"}},
	{"302255444",{"Jack","","Bob"}},
	{"302255125",{"Apple","Jesion","Oriaagne"}}
};

void display(const struct persons *pers,int n);

int main(void)
{
	
	display(&person[0],N);  // 也能用person传递地址，因为是数组名
	
	return 0;
}

void display(const struct persons *pers,int n)
{
	int i;
	for(i=0; i<n; i++)
		{
			if((pers+i)->name.middlename[0] != '\0')
				printf("%s, %s %c. - %s\n",(pers+i)->name.firstname,
						(pers+i)->name.lastname,(pers+i)->name.middlename[0],
						(pers+i)->number);
			else
				printf("%s, %s - %s\n",(pers+i)->name.firstname,
						(pers+i)->name.lastname,(pers+i)->number);
		}
}
