#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};

const struct month months[12] = {
		{"January","Jan",31,1},
		{"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};
int days(char *str);


int main(void)
{
	char input[20];
	int day_total = 0;
	
	printf("Enter the name of a month:\n");
	while(gets(input) != NULL && input[0] != '\0')
	{
		day_total = days(input);
		if(day_total != -1)
			printf("There are %d days through %s.\n",day_total,input);
		else
			printf("%s is not valid input.\n",input);				
			
		printf("Next name of a month (empty line to quit) :\n");
	}
	puts("Bye");
	
	return 0;
}

int days(char *str)
{
	int total = 0;
	int num = 0;
	int i;
// Transformation upper lower 转换大小写	
	str[0] = toupper(str[0]);
	for(i=1; str[i] != '\0';i++)
		str[i] = tolower(str[i]);
// find month number 查找月份号	
	for(i=0; i<12; i++)
			if(strcmp(str,months[i].name) == 0)
				{
					num = months[i].monumb;
					break;
				}
// count days 计算天数				}
	if(num == 0)	// if not find any month numbrt , return -1
		total = -1;
	else 
		for(i=0; i<num; i++)	
			total += months[i].days;
	
	return total;
}