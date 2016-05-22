#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bstoi(const char * str);
char * itobs(int n, char * ps);

int main(int argc, char * argv[])
{
	int v1, v2;
	int i;
	char bstr[8 * sizeof(int) + 1];
	
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s binarynum1 binarynum2\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	
	for(i='2';i<='9';i++)
	 if(strchr(argv[1],i) != NULL)
			{
				puts("binary number only contain 0 and 1 !");
				exit(EXIT_FAILURE);
			}
	for(i='2';i<='9';i++)
	 if(strchr(argv[2],i) != NULL)	
			{
				puts("binary number only contain 0 and 1 !");
				exit(EXIT_FAILURE);
			}
			
	v1 = bstoi(argv[1]);
	v2 = bstoi(argv[2]);
	
	printf("~%s = %s\n", argv[1], itobs(~v1, bstr));
	printf("~%s = %s\n", argv[2], itobs(~v2, bstr));
	printf("%s & %s = %s\n", argv[1], argv[2], itobs(v1 & v2, bstr));
	printf("%s | %s = %s\n", argv[1], argv[2], itobs(v1 | v2, bstr));
	printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(v1 ^ v2, bstr));
	
	puts("Done!");
	
	return 0;
}

int bstoi(const char * str)
{
	int val = 0;
	
	while(*str != '\0')
		val = 2 * val + (*str++ - '0');
	return val;
}

char * itobs(int n, char * ps)
{
	int i;
	static int size = 8 * sizeof(int);
	
	for(i=size - 1; i>=0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';	
	ps[size] = '\0';
	
	return ps;
}

