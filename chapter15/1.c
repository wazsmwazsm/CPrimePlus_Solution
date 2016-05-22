#include <stdio.h>
#include <stdbool.h>

int bstr_to_dec(const char * str);
bool check_value(const char * str);

int main(void)
{
	char value[8 * sizeof(int) + 1];
	
	printf("Enter a binary number with up to %d digits (empty line to quit) :\n",
					8 * sizeof(int));
	while(gets(value) && value[0] != '\0' && value[0] != '\n')
		{
			if(check_value(value))
				printf("%s is %d\n",value,bstr_to_dec(value));
			else
				puts("A binary number contains just 0s and 1s.\n");
			
			puts("Enter next value:");
		}
	puts("Done!");
		
	return 0;
}

int bstr_to_dec(const char * str)
{
	int val = 0;
	
	while(*str != '\0')
//		val = 2 * val + (*str++ - '0');  // here use ( val << 1 ) better
		val = (val << 1) + (*str++ - '0');
	return val;
}

bool check_value(const char * str)
{
	bool valid = true;
	
	while(valid && *str != '\0')
		{
			if(*str != '0' && *str != '1')
					valid = false;
			++str;
		}
	
	return valid;
}


