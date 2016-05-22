#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};

struct month months[12] = {
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

int days(int day, int mon, int year);

int main(void)
{
	int day = 0;
	int mon = 0;
	int year = 0;
	int tot_day = 0;
	
	printf("Enter the number of day month year: ");
	while(scanf(" %d %d %d",&day, &mon, &year) == 3)
		{
			tot_day = days(day,mon,year);
			if(tot_day != -1)
				printf("There are %d days through day %d, month %d, year %d.\n",
							tot_day,day,mon,year);
			else
				printf("day %d, month %d, year %d is not valid input.\n",day,mon,year);	
			
			printf("Next month (q to quit) :\n");	
		}
	
	puts("Bye");
	
	return 0;
}

int days(int day, int mon, int year)
{
	int i;
	int total = 0;
	
	if(leapyear(year))
		months[1].days = 29;
	else 
		months[1].days = 28;
	
	if(mon <1 || mon >12 || day <1 || day > months[mon - 1].days)
		return -1;
	else 
		for(i=0; i< mon-1; i++)
			total += months[i].days;

	return (total + day);

}

int leapyear(int year)
{
	if(year%400 == 0)
		return 1;
	else if(year%100 != 0 && year%4 == 0)
		return 1;
	else return 0;
}