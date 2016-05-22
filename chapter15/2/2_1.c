#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 8*sizeof(int)+1

char * extend(char * target, char * source);
char * reverse(char * target, char * source);
char * and(char * target, char * source1, char * source2);
char * or(char * target, char * source1, char * source2);
char * exclusive_or(char * target, char * source1, char * source2);


int main(int argc, char * argv[])
{
	char x[M], y[M], z[M];
	int i;
	
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
			
	printf(" x = %s\n", extend(x,argv[1]));
	printf(" y = %s\n", extend(y,argv[2]));
	printf(" ~x = %s\n", reverse(z,x));
	printf(" ~y = %s\n", reverse(z,y));
	printf(" x & y = %s\n", and(z,x,y));
	printf(" x | y = %s\n", or(z,x,y));
	printf(" x ^ y = %s\n", exclusive_or(z,x,y));
	
	return 0;
}

char * extend(char * target, char * source)
{
	int i;
	
	for(i=0; i< M - 1 - strlen(source); i++)
		target[i] = '0';
	target[i] = '\0'; // 为了形成字符串，strcat后整合两个字符串
	strcat(target, source);
	
	return target;
}

char * reverse(char * target, char * source)
{
	char * save = target;
	
	strcpy(target,source);	
	while(*target != '\0')
		{
			if(*target == '0') *target = '1';
			else *target = '0';
				
			target++;
		}
	
	return save;
}

char * and(char * target, char * source1, char * source2)
{
	char * save = target;
	
	while(*source1 != '\0')
		{
			if(*source1 == '1' && *source2 == '1') 
				*target = '1';
			else 
				*target = '0';
				
			source1++;
			source2++;	
			target++;
		}
	
	return save;
}

char * or(char * target, char * source1, char * source2)
{
	char * save = target;
	
	while(*source1 != '\0')
		{
			if(*source1 == '1' || *source2 == '1') 
				*target = '1';
			else 
				*target = '0';
				
			source1++;
			source2++;	
			target++;
		}
	
	return save;
}

char * exclusive_or(char * target, char * source1, char * source2)
{
	char * save = target;
	
	while(*source1 != '\0')
		{
			if(*source1 != *source2) 
				*target = '1';
			else 
				*target = '0';
				
			source1++;
			source2++;	
			target++;
		}
	
	return save;
}
