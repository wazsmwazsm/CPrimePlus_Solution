#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// 不属于接口函数的本地函数
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

// 接口函数
void InitializeQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
	return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
	return pq->items;
	
}

bool EnQueue(Item item, Queue *pq)
{
	Node * pnew;
	
	if(QueueIsFull(pq))
		return false;
	pnew = (Node *)malloc(sizeof(Node));
	if(pnew == NULL)
	{
		fprintf(stderr,"Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if(QueueIsEmpty(pq))   // 如果是对一个条目的话，接到头上去
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;       // 添加条目后重新设置队列尾指针
	pq->items++;					 // 条目数加一
	
	return true;
}

// 删除条目，遵循队列先进先出，先删除头部
bool DeQueue(Item *pitem, Queue * pq)
{
	Node *pt;
	
	if(QueueIsEmpty(pq))
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	
	pq->items--;
	if(pq->items == 0)
		pq->rear = NULL;
		
	return true;
}

void EmptyTheQueue(Queue *pq)
{
	Item dummy;
	while(!QueueIsEmpty(pq))
		DeQueue(&dummy,pq);
}

static void CopyToNode(Item item, Node * pn)
{
	pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}
