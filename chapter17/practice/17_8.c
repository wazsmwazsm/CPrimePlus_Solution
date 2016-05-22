#include <stdio.h>
#include <string.h>
#include "queue.h"

inline void eatline(void)
{
	while(getchar() != '\n');
}
char getlet(char *str);

int main(void)
{
	Queue line;
	Item temp;
	char ch;
	
	InitializeQueue(&line);
	puts("Testing the Queue interface. Type a to add a value,");
	puts("type d to delete a value, and type q to quit.");
	while((ch = getlet("adq")) != 'q')
	{
		if(ch == 'a')
		{
			printf("Integer to add: ");
			scanf("%d",&temp);
			eatline();
			if(!QueueIsFull(&line))
				{
					printf("Putting %d into queue\n",temp);
					EnQueue(temp, &line);
				}
			else
				puts("Queue is full!");				
		}
		else
		{
			if(QueueIsEmpty(&line))	
				puts("Nothing to delete!");
			else
				{
					DeQueue(&temp, &line);
					printf("Removing %d from queue\n",temp);
				}	
		}
		printf("%d items in queue\n",QueueItemCount(&line));	
		puts("Type a to add, d to delete, q to quit:");	
	}
	
	EmptyTheQueue(&line);
	puts("Bye!");
	
	
	return 0;
}

char getlet(char *str)
{
	char ch;
	
	ch = getchar();
	while(strchr(str, ch ) == NULL)
	{
		printf("please enter the charater from list %s",str);
		ch = getchar();
		eatline();
	}
	eatline();
	
	return ch;
}

