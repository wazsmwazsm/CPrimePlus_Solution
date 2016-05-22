#include <stdio.h>
#include "stack_2.h"

/* ��ʲô��ͬ�� */
/* ��Ϊջ��ʼ��������һ�����ڴ����Կ���ֱ�ӵ�ַ���� */
/* ���б������Щ��һ��һ�����룬�ڴ��ַ���룬������ */
/* Ҫһ���ڵ㣬��Ҫһ��next��prev��ָ����Ѱ���£��ϣ�һ�ṹ */

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

























