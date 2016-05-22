#include <stdio.h>

char * itobs(int n, char * ps);
unsigned int rotate(unsigned int n, unsigned int bit);

int main(void)
{
	unsigned int val, rot, places;
	char bstr1[8 * sizeof(int) + 1],bstr2[8 * sizeof(int) + 1];
	
	puts("Enter an integer ( 0 to quit):");
	while(scanf("%ud",&val) && val > 0 )
		{
			puts("Enter the number of bits to be rotated:");
			scanf("%ud",&places);
			rot = rotate(val, places);
			itobs(val, bstr1);
			itobs(rot, bstr2);
			printf("%u rotated is %u.\n", val, rot);
			printf("%s rotated is %s.\n", bstr1, bstr2);
			puts("Next value: ");
		}
	puts("Done! ");
		
	return 0;
}

unsigned int rotate(unsigned int n, unsigned int bit)
{
	static const int size = 8 * sizeof(int);
	unsigned int overflow;
	
	bit %= size; // keep bit a valid value
	
	overflow = n>>(size - bit);
	
	return (n<<bit) | overflow;
}

char * itobs(int n, char * ps)
{
	int i;
	static const int size = 8 * sizeof(int);
	
	for(i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	
	return ps;
}
