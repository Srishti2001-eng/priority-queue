#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    int priority_no;
    struct node *next;
}NODE;
NODE *front=NULL;

void insert(int item,int priority)
{
    NODE *new,*q;
    new=(NODE*)malloc(sizeof(NODE));
    new->data=item;
    new->priority_no=priority;

    if(front==NULL || priority>front->priority_no)
    {
        new->next=front;
        front=new;
    }

    else
	{
		q = front;
		while( q->next != NULL && q->next->priority_no <= priority )
		  q=q->next;
		new->next = q->next;
		q->next =new;
	}
}

void delete()
{
    NODE *tmp;
	if(front == NULL)
		printf("Queue Underflow\n");
	else
	{
		tmp = front;
		printf("Deleted item is %d\n",tmp->data);
		front = front->next;
		free(tmp);
	}
}

void display()
{
    NODE *ptr;
	ptr = front;
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{	
		printf("Queue is :\n");
		printf("Priority       Item\n");
		while(ptr != NULL)
		{
			printf("%5d        %5d\n",ptr->priority_no,ptr->data);
			ptr = ptr->next;
		}
	}
}

int main()
{
	int choice,item,priority;
	do
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Input the item value to be added in the queue : ");
				scanf("%d",&item);
				printf("Enter its priority : ");
				scanf("%d",&priority);
				insert(item,priority);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
			break;
				default :
				printf("Wrong choice\n");
		}
	}while(choice!=4);

	return 0;
}