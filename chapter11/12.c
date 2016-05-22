#include <stdio.h>

int main(int argc, char *argv[])
{
	int i ;
	
	for(i = argc -1; i>0; i--)
		puts(argv[i]);
		
		
	return 0;
}
