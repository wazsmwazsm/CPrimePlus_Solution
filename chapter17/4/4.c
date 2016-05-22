#include <stdio.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0     // 分和时转换
#define MAX 2	

// 这里为了方便摊数，把一些变量放到结构里了

typedef struct mall {
	
	int hours;           					// 模拟小时数
	int perhours;								  // 每小时顾客平均数
	long cyclelimit;							// 时间循环计数上限
	long turnaway;								// 被拒绝的顾客数
	long customers;								// 加入队列的顾客数
	long served;									// 被服务的顾客数
	long sum_line;								// 累计队列长度，总人数
	int wait_time;								// 从刚开始服务到空闲所需等待的时间
	double min_per_cust;					// 顾客来的平均时间间隔
	long line_wait;								// 队列累计等待时间
	
}Mall;

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line[MAX];  // 两个摊位，所以定义两个队列
	Item temp;				// 队列的条目
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

// 输入每个摊位的营业时间、每小时来的顾客人数	
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

// 处理所有摊位，进行排队模拟
	
	for(index=0; index<MAX; index++)
	{
		// 这里cycle代表分钟
		for(cycle = 0; cycle < Booth[index].cyclelimit; cycle++)
		{
			if(newcustomer(Booth[index].min_per_cust))  // 如果有顾客来
				{
					if(QueueIsFull(&line[index]))
						Booth[index].turnaway++;    // 客人满了的话被拒绝，否则进行等待时间模拟并加入队列
					else
						{
							Booth[index].customers++;
							temp = customertime(cycle);
							EnQueue(temp,&line[index]);
						}
				}
			// 当服务完一个顾客后，接着服务下一个顾客
			if(Booth[index].wait_time <= 0 && !QueueIsEmpty(&line[index]))
				{
					DeQueue(&temp, &line[index]);
					Booth[index].wait_time = temp.processtime;
					Booth[index].line_wait += cycle - temp.arrive;
					Booth[index].served++;
				}
			// 顾客还在服务等待中，时间减一
			if(Booth[index].wait_time > 0)
				Booth[index].wait_time--;
			// 计算总共的排队顾客总数
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

// 有新顾客到来吗

bool newcustomer(double x)
{
	if(rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

// 设置顾客参量

Item customertime(long when)
{
	Item cust;
	
	cust.arrive = when;
	cust.processtime = rand() % 3 + 1;
	
	return cust;
}
