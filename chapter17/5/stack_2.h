#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE	100

typedef char Item;

typedef struct stack
{
	Item *top;     
	Item *save;
	int size;
}Stack;

void InitializeStack(Stack * pstack);

bool StackIsFull(const Stack * pstack);

bool StackIsEmpty(const Stack * pstack);

bool PushStack(Item item, Stack * pstack);

bool PopStack(Item * pitem, Stack * pstack);

bool EmptyStack(Stack * pstack);




#endif
