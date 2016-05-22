#include <stdio.h>

char * itobs(int n, char * ps);
int onbit(int n);

int main(void)
{
	int val;
	char bstr[8 * sizeof(int) + 1];
	
	puts("Enter an integer (negative to quit) :");
	while(scanf("%d",&val) && val >= 0)
	{
		printf("%d (%s) has %d bits on.\n", val,
						itobs(val,bstr), onbit(val));
		puts("Next value:");		
	}
	puts("Done!");
	
	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	static const int size = 8 * sizeof(int);
	
	for(i = size - 1; i >= 0; i--, n>>=1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	
	return ps;
}

int onbit(int n)
{
	static const int size = 8 * sizeof(int);
	
	int ct = 0;
	int i;
	
	for(i = 0; i < size; i++, n >>= 1)
		if((01 & n) == 1)
			ct++;
	
	return ct;
}

