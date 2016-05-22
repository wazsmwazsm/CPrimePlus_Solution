#include <stdio.h>
#include "stack.h"


void InitializeStack(Stack * pstack)
{
	pstack->top = 0;
}
bool StackIsFull(const Stack * pstack)
{
	if(pstack->top == STACK_SIZE)
		return true;
	else
		return false;
}
bool StackIsEmpty(const Stack * pstack)
{
	if(pstack->top == 0)
		return true;
	else
		return false;
}
bool PushStack(Item item, Stack * pstack)
{
	if(StackIsFull(pstack))
		return false;
	else
	{
		pstack->items[pstack->top++] = item;
	}
	return true;
}
bool PopStack(Item * pitem, Stack * pstack)
{
	if(StackIsEmpty(pstack))
		return false;
	else
	{
		pstack->top--;
		*pitem = pstack->items[pstack->top];
	}
	return true;
	
}


























