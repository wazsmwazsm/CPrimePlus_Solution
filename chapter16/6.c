#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM	5
#define SZIE	10
struct names {
	char first[SZIE];
	char last[SZIE];
};

void showarray(const struct names p[], int n);
int comp(const void * p1, const void * p2);


int main(void)
{
	struct names staff[NUM] = {
	{"Jawe",  "Hsadff"},
  {"Jasff",  "Hsadff"},
  {"Jasff",  "Paswqeq"},
  {"Qmetrbv",  "Tsjdfef"},
  {"Msdwersa", "Bsfwoo"},
	};
	puts("Random list:");
	showarray(staff, NUM);
	qsort(staff, NUM, sizeof(struct names),comp);
	puts("\nSorted list:");
	showarray(staff, NUM);
	
	return 0;
}

void showarray(const struct names p[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%-10s %-10s\n",p[i].first, p[i].last);	
}

int comp(const void * p1, const void * p2)
{
	const struct names *ps1 = (const struct names *) p1;
	const struct names *ps2 = (const struct names *) p2;
	int res;
	
	res = strcmp(ps1->last, ps2->last);
	if(res != 0)
		return res;
	else
		return strcmp(ps1->first, ps2->first);
}




