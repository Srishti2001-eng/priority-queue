/*
[24]
Suppose a computer system has one processor to execute different tasks.
Each task has a time of execution.
Each task is assigned with a priority number depending upon the type of task:
Local Printing (Lowest Priority -1), Web Applications (Priority-2), I/O interfacing (Highest Priority -3).

Every time a task is generated, its execution time and priority number are entered and stored.
Which data structure can efficiently maintain task waiting for the processor?

Write functions for insertion and deletion operations for the tasks with the following conditions.
i) A task will be processed first with minimum execution time.
ii) A task will be processed first with highest priority.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* queue list node*/
struct priorityqueue
{
    struct queue
    {
        int time;
        struct queue *next;
    } * front, *rear;
} priority[3];

/*Function to create list*/
void insert(int time, int prio)
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->time = time;
    temp->next = NULL;
    prio--;
    if (priority[prio].rear == NULL)
        priority[prio].rear = priority[prio].front = temp;
    else
    {
        struct queue *t = priority[prio].front;
        while(t->time < time)
        {
            if(t->next != NULL)
                t = t->next;
            else
            {
                t->next = temp;
                priority[prio].rear = temp;
                return;
            }
        }
        struct queue *te = t;
        t = temp;
        if (priority[prio].front == te)
            priority[prio].front = t;
        t->next = te;
    }
}
/*Functuon to delete operation*/
void delete1()
{
    int i;
    for (i = 2; i > -1; i--)
    {
        if (priority[i].front != NULL)
        {
            struct queue *t = priority[i].front;
            int time = t->time;
            priority[i].front = t->next;
            if(priority[i].rear == t)
                priority[i].rear = NULL;
            free(t);
            printf("%d\t%d\n", time, i + 1);
            break;
        }
    }
    if(i == -1)
        printf("\nUnderflow\n");
}

void nullify()
{
    for (int i = 0; i < 3; i++)
        priority[i].front = priority[i].rear = NULL;
}

/*Driver program to test above function*/
int main()
{
    int ch, time, priority;
    nullify();
    while (1)
    {
        printf("\nEnter\n1 to insert\n2 to delete\nAny other number to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter time and priority of process\t");
            scanf("%d%d", &time, &priority);
            insert(time, priority);
            break;
        case 2:
            delete1();
            break;

        default:
            printf("\nThank You.");
            getch();
            return 0;
        }
    }
}