/* pe14-7.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL     40
#define MAXAUTL     40
#define MAXBKS      10         /* maximum number of books */
#define CONTINUE    0
#define DONE        1
#define YES         1
#define NO          0
struct book {                  /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int delete;
};

int getlet(const char * s);
int getbook(struct book * pb);
void update(struct book * item);

int main(void)
{
     struct book library[MAXBKS]; /* array of structures     */
     int count = 0;
     int deleted = 0;
     int index, filecount, open;
     FILE * pbooks;
     int size = sizeof (struct book);

     if ((pbooks = fopen("book.dat", "r")) != NULL)
     {
         while (count < MAXBKS &&  fread(&library[count], size,
                     1, pbooks) == 1)
         {
             if (count == 0)
                 puts("Current contents of book.dat:");
             printf("%s by %s: $%.2f\n",library[count].title,
                 library[count].author, library[count].value);
             printf("Do you wish to change or delete this entry?<y/n> ");
             if (getlet("yn") == 'y')
             {
                 printf("Enter c to change, d to delete entry: ");
                 if (getlet("cd") == 'd')
                 {
                     library[count].delete = YES;
                     deleted++;
                     puts("Entry marked for deletion.");
                 }
                 else
                     update(&library[count]);
             }
             count++;
         }
         fclose(pbooks);
     }
     filecount = count - deleted;
     if (count == MAXBKS)
     {
         fputs("The book.dat file is full.", stderr);
         exit(2);
     }
     puts("Please add new book titles.");
     puts("Press [enter] at the start of a line to stop.");
     open = 0;
     while (filecount < MAXBKS)
     {
        if (filecount < count)
        {
            while (library[open].delete == NO)
                open++;
            if (getbook(&library[open]) == DONE)
                break;
        }
        else if (getbook(&library[filecount]) == DONE)
            break;
        filecount++;
        if (filecount < MAXBKS)
            puts("Enter the next book title.");    
     }
     puts("Here is the list of your books:");
     for (index = 0; index < filecount; index++)
         if (library[index].delete == NO)
            printf("%s by %s: $%.2f\n",library[index].title,
                library[index].author, library[index].value);
     if ((pbooks = fopen("book.dat", "w")) == NULL)
     {
         fputs("Can't open book.dat file for output\n",stderr);
         exit(1);
     }
     for (index = 0; index < filecount; index++)
         if (library[index].delete == NO)
            fwrite(&library[index], size, 1, pbooks);
     fclose(pbooks);
     puts("Done!");

     return 0;
}

int getlet(const char * s)
{
    char c;
    
    c = getchar();
    while (strchr(s, c) == NULL)
    {
        printf ("Enter a character in the list %s\n", s);
        while( getchar() != '\n')
            continue;
        c = getchar();
    }
    while (getchar() != '\n')
        continue;
    
    return c;
}

int getbook(struct book * pb)
{
    int status = CONTINUE;
    if (gets(pb->title) == NULL || pb->title[0] == '\0')
        status = DONE;
    else
    {
        printf ("Now enter the author: ");
        gets (pb->author);
        printf ("Now enter the value: ");
        while (scanf("%f", &pb->value ) != 1)
        {    
            puts("Please use numeric input");
            scanf("%*s");
        }
        while (getchar() != '\n')
            continue; /*clear input line */
        pb->delete = NO;
    }
    return status;
}

void update(struct book * item)
{
    struct book copy;
    char c;
    
    copy = *item;
    puts("Enter the letter that indicates your choice:");
    puts("t) modify title     a) modify author");
    puts("v) modify value     s) quit, saving changes");
    puts("q) quit, ignore changes");
    while ( (c = getlet("tavsq")) != 's' && c != 'q')
    {
        switch ( c )
        {
            case 't' : puts("Enter new title: ");
                       gets (copy.title);
                       break;
            case 'a' : puts("Enter new author: ");
                       gets (copy.author);
                       break;
            case 'v' : puts("Enter new value: ");
                       while (scanf("%f", &copy.value) != 1)
                       {
                           puts ("Enter a numeric value: ");
                           scanf("%*s");
                       }
                       while( getchar() != '\n')
                           continue;
                       break;
        }
        puts("t) modify title     a) modify author");
        puts("v) modify value     s) quit, saving changes");
        puts("q) quit, ignore changes");
    }        
    if (c == 's')
        *item = copy;
}
