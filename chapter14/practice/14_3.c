#include  <stdio.h>
#define LEN 20

const char *msge[5] = {
	"	Thank you for the wonderful evening, ",
	"You certainly prove that a ",
	"is a special kind of guy. We must get together",
	"over a dilicious ",
	" and have a few laughs"	
};

struct names {
		char first[LEN];
		char last[LEN];
};

struct guy	{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow = {
		{"Ewen","Villard"},
		"grilled salmon",
		"personality coach",
		58112.00
	};
	
	printf("Dear %s, \n\n", fellow.handle.first);	
	printf("%s%s.\n", msge[0], fellow.handle.first);	
	printf("%s%s\n", msge[1], fellow.job);	
	printf("%s\n", msge[2]);	
	printf("%s%s%s",msge[3], fellow.favfood, msge[4]);	
	
	if(fellow.income > 150000.0)
		printf("!!\n");
	else if (fellow.income > 75000.0)
		printf("!\n");
	else 
		puts(".");	
	
	printf("\n%40s%s\n"," ","See you soon, ");	
	printf("%40s%s\n"," ","Shalala");	
	
	return 0;
}












