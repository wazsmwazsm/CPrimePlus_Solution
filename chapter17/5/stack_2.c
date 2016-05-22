#include <stdio.h>
#include "stack_2.h"

/* 有什么不同？ */
/* 因为栈开始就申请了一块大的内存所以可以直接地址访问 */
/* 而列表队列这些是一个一个申请，内存地址分离，所以需 */
/* 要一个节点，需要一个next（prev）指针来寻找下（上）一结构 */

void InitializeStack(Stack * pstack)
{
	pstack->save = (Item *)malloc(STACK_SIZE * sizeof(Item));
	pstack->top = pstack->save + STACK_SIZE * sizeof(Item);
	pstack->size = 0;
}
bool StackIsFull(const Stack * pstack)
{
	if(pstack->size == STACK_SIZE)
		return true;
	else
		return false;
}
bool StackIsEmpty(const Stack * pstack)
{
	if(pstack->size == 0)
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
		(pstack->top)--;
		*(pstack->top) = item;
		pstack->size++;
	}
	return true;
}
bool PopStack(Item * pitem, Stack * pstack)
{
	if(StackIsEmpty(pstack))
		return false;
	else
	{
		*pitem = *(pstack->top);
		(pstack->top)++;
		pstack->size--;
	}
	return true;
	
}
bool EmptyStack(Stack * pstack)
{
	free(pstack->save);	
}

























