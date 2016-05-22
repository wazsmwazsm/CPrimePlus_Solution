#include <stdio.h>
#include "16_10.h"

void get_names(names * pn)
{
	int i = 0;
	
	printf("Please enter your first name:   ");
	fgets(pn->first, SLEN, stdin);
	while(pn->first[i] != '\n' && pn->first[i] != '\0')
		i++;
	if(pn->first[i] == '\n')	
		pn->first[i] == '\0';
	else
		while(getchar() != '\n');	
		
	printf("Please enter your last name:   ");
	fgets(pn->last, SLEN, stdin);
	i = 0;
	while(pn->last[i] != '\n' && pn->last[i] != '\0')
		i++;
	if(pn->last[i] == '\n')	
		pn->last[i] == '\0';
	else
		while(getchar() != '\n');		
		
}
void show_names(const names *pn)
{
	printf("%s %s",pn->first,pn->last);
	
	
}