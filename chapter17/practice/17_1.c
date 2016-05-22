#include <stdio.h>
#define TSIZE	45
#define FMAX	5

struct film {
	char title[TSIZE];
	int rating;
	
};
 
int main(void)
{
	struct film movies[FMAX];
	int i = 0;
	int j;
	
	puts("Enter first movie title");
	while(i < FMAX && gets(movies[i].title) != NULL && 
				movies[i].title[0] != '\0')
	{
		puts("Enter your rating: ");
		scanf("%d",&movies[i++].rating);
		while(getchar() != '\n');
		
		puts("Enter next movie title (empty line to stop):");		
	}
	
	if(i == 0)
		printf("No data entered.\n");
	else
		printf("Here is the movie list:\n");
	
	for(j=0; j<i; j++)
		printf("Movie: %s Rating: %d\n",movies[j].title,
						movies[j].rating);
	
	puts("Bye!");
	
	return 0;
}
