#include <stdio.h>

#define CSIZE	4
#define NAMESIZE 20
#define SCORE	3

struct names {
	char firstname[NAMESIZE];
	char lastname[NAMESIZE];
};

struct students {
	struct names name;
	float grade[SCORE];
	float average;
};

void get_score(struct students stu[], int n);
void find_average(struct students stu[], int n);
void display(const struct students stu[], int n);
void show_ave(const struct students stu[], int n);


int main(void)
{
	struct students student[CSIZE] = {
			{{"Flip","Snide"},{0},0},
			{{"Clare","Voyans"},{0},0},
			{{"Bingo","Higgs"},{0},0},
			{{"Fawn","Hunter"},{0},0}
	};
	get_score(student,CSIZE);
	find_average(student,CSIZE);
	display(student,CSIZE);
	show_ave(student,CSIZE);
	
	return 0;
}

void get_score(struct students stu[], int n)
{
	int i,j;
	
	for(i=0; i<n; i++)
		{
			printf("Please enter %d score for %s %s:\n",SCORE,
						stu[i].name.firstname,stu[i].name.lastname);
			for(j=0; j<SCORE; j++)
				{
					while(scanf(" %f",&stu[i].grade[j]) != 1)
						{
							while(getchar() != '\n');
							puts("Please use numeric input.");
						}
				}
		}	
}

void find_average(struct students stu[], int n)
{
	int i,j;
	float tot = 0;
	
	for(i=0; i<n; i++)
		{
			tot = 0;
			for(j=0; j< SCORE; j++)
				tot += stu[i].grade[j];
			stu[i].average = tot / SCORE;
		}
}

void display(const struct students stu[], int n)
{
	int i,j;
	
	for(i=0; i< n ; i++)
		{
			printf("%s %s",stu[i].name.firstname,stu[i].name.lastname);
			for(j=0; j<SCORE; j++)
				printf("%6.1f ",stu[i].grade[j]);
			printf("Average = : %5.2f\n",stu[i].average);
		}
}

void show_ave(const struct students stu[], int n) 
{
	int i = 0,j;
	float tot = 0;
	
	printf("\n%27s\n","QUIZ AVERAGES");
	for(j=0 ; j<SCORE; j++)
		{
			tot = 0;
			
			for(i=0; i<n; i++)
				{
					tot += stu[i].grade[j];
					
				}
			printf("score %d %6.2f\n", j+1, tot / n);
		}
		
}

