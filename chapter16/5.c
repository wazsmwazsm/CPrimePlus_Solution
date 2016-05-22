#include <stdio.h>
#include <string.h>
#include <time.h>

#define SPORTS	10
#define PICKS	6

inline void eatline(void)
{
	while(getchar() != '\n');
}
void random_pick(int ar[], int arsize, int picks);
char getlet(char *str);

int main(void)
{
	int lotto[SPORTS];
	int i;
	char ch;
	// init array
	for(i=0; i<SPORTS; i++)
		lotto[i] = i + 1;
	puts("Now start ramdom picks? (y/n)");
	while((ch = getlet("yn")) == 'y')	
		{
			random_pick(lotto, SPORTS, PICKS);
			puts("Again? (y/n)");
		}
	
	puts("Done!");
	return 0;
}

char getlet(char *str)
{
	char ch;
	ch = getchar();
	while(strchr(str, ch) == NULL)
		{
			printf("Please enter a character int he list %s\n",str);
			eatline();
			ch = getchar();
		}
	eatline();
	
	return ch;
}

void random_pick(int ar[], int arsize, int picks)
{
	int i, index, temp;
	
	srand(time(0));
	if(picks > arsize)
	{
		fputs("Number of picks > array size\n",stderr);
		fputs("Setting picks = array size\n",stderr);
		picks = arsize;
	}
	
	for(i=0; i<picks; i++)
	{
		index = rand() % (arsize - 1);
		temp = ar[index];
		printf("%d\t",temp);
		if(i % 20 == 19)
			putchar('\n');
	// 把已选的数交换到末尾，并缩减搜索数量，以防重复	
		ar[index] = ar[arsize - 1];
		ar[arsize - 1] = temp;
		arsize--;
	}
	if(i % 20 != 0)
		putchar('\n');
		
}

