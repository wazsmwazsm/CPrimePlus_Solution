#include <stdio.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0     // �ֺ�ʱת��
#define MAX 2	

// ����Ϊ�˷���̯������һЩ�����ŵ��ṹ����

typedef struct mall {
	
	int hours;           					// ģ��Сʱ��
	int perhours;								  // ÿСʱ�˿�ƽ����
	long cyclelimit;							// ʱ��ѭ����������
	long turnaway;								// ���ܾ��Ĺ˿���
	long customers;								// ������еĹ˿���
	long served;									// ������Ĺ˿���
	long sum_line;								// �ۼƶ��г��ȣ�������
	int wait_time;								// �Ӹտ�ʼ���񵽿�������ȴ���ʱ��
	double min_per_cust;					// �˿�����ƽ��ʱ����
	long line_wait;								// �����ۼƵȴ�ʱ��
	
}Mall;

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line[MAX];  // ����̯λ�����Զ�����������
	Item temp;				// ���е���Ŀ
	long cycle; 
	int index;
	
/* defination two booth */	
	Mall Booth[MAX] = {{0,0,0,0,0,0,0,0,0,0},
										 {0,0,0,0,0,0,0,0,0,0}};
	
/* initalize two queue */	
	for(index=0; index<MAX; index++)
		InitializeQueue(&line[index]);
	
	srand(time(0));
	
	puts("Case Study: Sigmund Lander's Advice Sooth");

// ����ÿ��̯λ��Ӫҵʱ�䡢ÿСʱ���Ĺ˿�����	
	for(index=0; index<MAX; index++)
	{	
		printf("Booth %d:\nEnter the number of simulation hours: ",index+1);
		scanf("%d",&Booth[index].hours);	
		while(getchar() != '\n');
		Booth[index].cyclelimit = MIN_PER_HR * Booth[index].hours;
		puts("Enter the average number of vustomers per hours:");
		scanf("%d",&Booth[index].perhours);
			while(getchar() != '\n');
		Booth[index].min_per_cust = MIN_PER_HR / Booth[index].perhours;
	}

// ��������̯λ�������Ŷ�ģ��
	
	for(index=0; index<MAX; index++)
	{
		// ����cycle�������
		for(cycle = 0; cycle < Booth[index].cyclelimit; cycle++)
		{
			if(newcustomer(Booth[index].min_per_cust))  // ����й˿���
				{
					if(QueueIsFull(&line[index]))
						Booth[index].turnaway++;    // �������˵Ļ����ܾ���������еȴ�ʱ��ģ�Ⲣ�������
					else
						{
							Booth[index].customers++;
							temp = customertime(cycle);
							EnQueue(temp,&line[index]);
						}
				}
			// ��������һ���˿ͺ󣬽��ŷ�����һ���˿�
			if(Booth[index].wait_time <= 0 && !QueueIsEmpty(&line[index]))
				{
					DeQueue(&temp, &line[index]);
					Booth[index].wait_time = temp.processtime;
					Booth[index].line_wait += cycle - temp.arrive;
					Booth[index].served++;
				}
			// �˿ͻ��ڷ���ȴ��У�ʱ���һ
			if(Booth[index].wait_time > 0)
				Booth[index].wait_time--;
			// �����ܹ����Ŷӹ˿�����
			Booth[index].sum_line += QueueItemCount(&line[index]);		
		}
		
		if(Booth[index].customers > 0)
		{
			printf("Booth %d :\n",index+1);
			printf("customers accepted: %ld\n",Booth[index].customers);
			printf("customers served: %ld\n",Booth[index].served);
			printf("turnaways: %ld\n",Booth[index].turnaway);
			printf("average queue size: %.2f\n",
						 (double)Booth[index].sum_line / Booth[index].cyclelimit);
			printf("average wait time: %.2f minutes\n",
			       (double)Booth[index].line_wait / Booth[index].served);
		}
		else
			puts("No customers!");
		
	}
	for(index=0; index<MAX; index++)
		EmptyTheQueue(&line[index]);
	
	puts("Bye!");
	return 0;
}

// ���¹˿͵�����

bool newcustomer(double x)
{
	if(rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

// ���ù˿Ͳ���

Item customertime(long when)
{
	Item cust;
	
	cust.arrive = when;
	cust.processtime = rand() % 3 + 1;
	
	return cust;
}
