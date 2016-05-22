#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE	100

typedef char Item;

/* 同是一次性申请空间，这次用数组实现 */
typedef struct stack
{
	Item items[STACK_SIZE];     
	int top;
}Stack;

void InitializeStack(Stack * pstack);

bool StackIsFull(const Stack * pstack);

bool StackIsEmpty(const Stack * pstack);

bool PushStack(Item item, Stack * pstack);

bool PopStack(Item * pitem, Stack * pstack);





#endif
