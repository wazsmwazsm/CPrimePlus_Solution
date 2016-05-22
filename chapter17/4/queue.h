#pragma c9x on			// ����C99���ԣ�gcc�Ϻ���̫֧��
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>

// ��Ŀ����
typedef struct item {
	long arrive;					// �˿͵����ʱ��
	int processtime;			// �˿ͷ����ʱ��
} Item;

// ������󳤶�
#define MAXQUEUE 10

// �ڵ�����
typedef struct node{
	Item item;
	struct node *next;
}Node;
// ��������
typedef struct queue{
	Node * front;
	Node * rear;
	int items;
}Queue;


// ��ʼ������
void InitializeQueue(Queue *pq);

// �����Ƿ�����
bool QueueIsFull(const Queue *pq);

// �����Ƿ�Ϊ��
bool QueueIsEmpty(const Queue *pq);

// ������Ŀ����
int QueueItemCount(const Queue *pq);

// �����Ŀ��������
bool EnQueue(Item item, Queue *pq);

// ɾ��һ����Ŀ������
bool DeQueue(Item *pitem, Queue * pq);

// ��ն��У��ͷ�������ڴ�
void EmptyTheQueue(Queue *pq);


#endif












