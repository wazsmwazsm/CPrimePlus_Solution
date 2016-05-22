#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 14
#define EMPTY 0
#define TAKEN 1
#define SEATS	12
#define FLIGHT	4


struct planestats {
	int seat_id;
	int status;
	char first_name[LEN];
	char last_name[LEN];
};

struct flight {
	int flight_id;
	struct planestats seats[SEATS];
};

// 基本功能函数
int getmenu(void);
int get_let(const char *s);
void sort(struct planestats p[], int n);
int empty_seat(struct planestats p[], int n);

// 任务处理函数
void show_empty(struct planestats p[], int n);
void show_seats(struct planestats p[], int n);
void assign_seat(struct planestats p[], int n);
void delet_seat(struct planestats p[], int n);
void confirm_seat(struct planestats p[], int n);

int main(void)
{
	struct flight flights[FLIGHT];
	int seat_choice, flight_choice;
	int i,j;
	size_t size = sizeof(struct flight);
	FILE *fp;

	if((fp = fopen("air.dat","rb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s","air.dat\n");
			if((fp = fopen("air.dat","wb")) == NULL)
				{
					exit(1);
				}
			for(j=0; j<FLIGHT; j++)
				{
					flights[j].flight_id = j + 1;
					for(i=0; i<SEATS; i++)
						{
							flights[j].seats[i].seat_id = i + 1;
							flights[j].seats[i].status = 0;
						}
				}
				
			fwrite(flights, size , FLIGHT, fp);
			puts("We created the file air.dat now.");
			exit(1);
		}
		
	for(j=0; j<FLIGHT; j++)
		{
			flights[j].flight_id = j + 1;
			for(i=0; i<SEATS; i++)
				{
					flights[j].seats[i].seat_id = i + 1;
					flights[j].seats[i].status = 0;
				}
		}

	fread(flights, size , FLIGHT, fp);
	fclose(fp);
	
	while((flight_choice = choose_flight()) != -1)	
	{
		while((seat_choice = getmenu()) != 'g')	
		{
			switch(seat_choice)
			{
				case 'a': printf("%d seat is empty!\n",
													empty_seat(flights[flight_choice].seats,SEATS));
									break;
				case 'b':	show_empty(flights[flight_choice].seats,SEATS);
									break;
				case 'c':	show_seats(flights[flight_choice].seats,SEATS);
									break;
				case 'd':	assign_seat(flights[flight_choice].seats,SEATS);
									break;
				case 'e':	delet_seat(flights[flight_choice].seats,SEATS);
									break;
				case 'f':	confirm_seat(flights[flight_choice].seats,SEATS);
									break;				
			}	
		}
		
	}	
		
	if((fp = fopen("air.dat","wb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s","air.dat");
			exit(1);
		}	
	fwrite(flights, size , FLIGHT, fp);
	fclose(fp);	
		
	puts("Bye!");	
			
	return 0;
}

int choose_flight(void)
{
	int ch;
	puts("To choose a flight, enter its letter laber:");
	puts("a) Flight 1");
	puts("b) Flight 2");
	puts("c) Flight 3");
	puts("d) Flight 4");
	puts("q) quit");
	switch(get_let("abcdq"))
	{
		case 'a': return 0;
		case 'b': return 1;
		case 'c': return 2;
		case 'd': return 3;
		default: return -1;
	}
}

int getmenu(void)
{
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Confirm a seat assignment");
	puts("g) Exit to the top-level menu");
	
	return get_let("abcdefg");
}

// 此函数返回字符串中的一个字符,也可以直接读取判断

int get_let(const char *s)
{
	char c;
	
	c = getchar();
	// 在字符串s中搜寻字符c
	while(strchr(s, c) == NULL)
		{
			printf("Enter a character in the list %s.\n",s);
			while(getchar()!='\n');
			
			c = getchar();
		}
	while(getchar()!='\n');
	
	return c;
}

int empty_seat(struct planestats p[], int n)
{
	int count = 0;
	int seat;
	for(seat = 0; seat < n; seat++)
		if(p[seat].status == EMPTY)
			count++;
			
	return count;
}

void show_empty(struct planestats p[], int n)
{	
	int seat;
	if(empty_seat(p,n) == 0)
		puts("All seats are assigned");
	else
		{
			puts("The following seats are available:");
			for(seat = 0; seat < n; seat++)
				if(p[seat].status == EMPTY)
					printf("seats: %d\n",p[seat].seat_id);
		}
}

void show_seats(struct planestats p[], int n)
{
	int seat;
	if(empty_seat(p,n) == SEATS)
		puts("All seats are empty");
	else
		{
			sort(p,n);
			puts("The following seats are taked:");
			for(seat = 0; seat < n; seat++)
				if(p[seat].status == TAKEN)
					printf("seats: %d %s %s\n",p[seat].seat_id,
								p[seat].last_name,p[seat].first_name);
		}
}

void assign_seat(struct planestats p[], int n)
{
	int number, seat;
	show_empty(p,n);
	puts("Enter the seat ID (1 ~ 12) you choice:");
	while(scanf("%d",&number) != 1 || number < 1 || number > 12)
		{
			scanf("%*s");
			puts("Enter number (1 ~ 12)");
		}
	while(getchar() != '\n');
	
	for(seat = 0; seat < n; seat++)
			if(p[seat].seat_id == number)
				{
					if(p[seat].status == TAKEN)
						printf("NO.%d seat is already assigned!\n",p[seat].seat_id);	
					else
						{
							puts("Enter firstname:");
							gets(p[seat].first_name);
							puts("Enter lastname:");
							gets(p[seat].last_name);
							p[seat].status = 	TAKEN;	
							printf("assign NO.%d seat successfully!\n",p[seat].seat_id);					
						}
				}
}

void delet_seat(struct planestats p[], int n)
{
	int number, seat;
	show_seats(p,n);
	puts("Enter the seat ID (1 ~ 12) you choice:");
	while(scanf("%d",&number) != 1 || number < 1 || number > 12)
		{
			scanf("%*s");
			puts("Enter number (1 ~ 12)");
		}
	while(getchar() != '\n');
	
	for(seat = 0; seat < n; seat++)
			if(p[seat].seat_id == number)
				{
					if(p[seat].status == EMPTY)
						printf("NO.%d seat is already empty!\n",p[seat].seat_id);	
					else
						{
							p[seat].status = 	EMPTY;	
							printf("delet NO.%d seat successfully!\n",p[seat].seat_id);					
						}
				}
}

void sort(struct planestats p[], int n)
{
	int top, search;
	// 注意这里，用结构不用指针，结构名无法做地址，
	// 且交换时赋值表达式左值不能为表达式，无法用&运算符取地址
	struct planestats temp; 
	for(top = 0; top < n - 1; top++)
		for(search = top + 1; search < n; search++)
			if(strcmp(p[search].last_name, p[top].last_name) < 0)  // 按名字首字母进行排序
				{
					temp = p[search];
					p[search] = p[top];
					p[top] = temp;
				}
}

void confirm_seat(struct planestats p[], int n)
{
	int number, seat;
	puts("Enter the seat ID (1 ~ 12) you choice:");
	while(scanf("%d",&number) != 1 || number < 1 || number > 12)
		{
			scanf("%*s");
			puts("Enter number (1 ~ 12)");
		}
	while(getchar() != '\n');
	
	for(seat = 0; seat < n; seat++)
			if(p[seat].seat_id == number)
				{
					if(p[seat].status == EMPTY)
						printf("NO.%d seat is already empty!\n",p[seat].seat_id);	
					else
						{
						printf("NO.%d seat is already assigned!\n",p[seat].seat_id);							
						}
				}

}
