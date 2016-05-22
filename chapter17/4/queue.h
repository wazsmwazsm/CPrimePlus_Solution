#pragma c9x on			// 开启C99特性，gcc上好像不太支持
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>

// 条目声明
typedef struct item {
	long arrive;					// 顾客到达的时间
	int processtime;			// 顾客服务的时间
} Item;

// 队列最大长度
#define MAXQUEUE 10

// 节点声明
typedef struct node{
	Item item;
	struct node *next;
}Node;
// 队列声明
typedef struct queue{
	Node * front;
	Node * rear;
	int items;
}Queue;


// 初始化队列
void InitializeQueue(Queue *pq);

// 队列是否已满
bool QueueIsFull(const Queue *pq);

// 队列是否为空
bool QueueIsEmpty(const Queue *pq);

// 队列条目数量
int QueueItemCount(const Queue *pq);

// 添加条目到队列中
bool EnQueue(Item item, Queue *pq);

// 删除一个条目到队列
bool DeQueue(Item *pitem, Queue * pq);

// 清空队列，释放申请的内存
void EmptyTheQueue(Queue *pq);


#endif












