#include <stdio.h>

void why_me();

int main(void)
{
	printf("This file is %s\n", __FILE__);
	printf("This date is %s\n", __DATE__);
	printf("This time is %s\n", __TIME__);
	printf("This verson is %ld\n", __STDC_VERSION__);
	printf("This is line %d\n", __LINE__);
	printf("This function is %s\n", __func__);
	why_me();
	return 0;
}
void why_me()
{
	printf("This function is %s\n", __func__);
	printf("This is line %d\n", __LINE__);
	
}

