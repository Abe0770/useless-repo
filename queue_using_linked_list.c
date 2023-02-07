/*
IMPLEMENTATION OF STACK USING LINKED LIST
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int dat;
	struct node *link;
} *front = NULL, *rear = NULL;

bool isempty()
{
	if(front == NULL && rear == NULL)
		return 1;
	return 0;
}

void enqueue()
{
	int a;	
	struct node *new = (struct node *) malloc(sizeof(struct node));
	if(front == NULL && rear == NULL)
	{
		printf("\nEnter your data : ");
		scanf("%d", &a);
		new -> dat = a;
		new -> link = NULL;
		front = new;
		rear = new;
	} 
	else
	{
		printf("\nEnter your data : ");
		scanf("%d", &a);
		new -> dat = a;
		rear -> link = new;
		new -> link = NULL;
		rear = new;
	}
}	

void dequeue()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nThe queue is empty!");
		printf("\n--------------------------------");
	}
	else if(front == rear)
	{
		printf("\n--------------------------------");
		printf("\nThe element %d was deleted.", front -> dat);
		printf("\n--------------------------------");
		front = NULL;
		rear = NULL;
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nThe element %d was deleted.", front -> dat);
		printf("\n--------------------------------");
		front = front -> link;
	}
}

void display()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nThe queue is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		struct node *ptr;
		ptr = front;
		printf("\n--------------------------------");
		printf("\nThe elements of the queue are : \n");
		while(ptr != NULL)
		{
			printf("%d\n", ptr -> dat);
			ptr = ptr -> link;
		}	
		printf("\n--------------------------------");
	}
}

void peek()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nThe queue is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------------");
		printf("\nThe front element of the queue is : %d", front -> dat);
		printf("\n--------------------------------------");
	}
}

int main()
{
	int op;
	while(1)
	{
		printf("\n\nSelect your choice\n[1] enqueue\n[2] dequeue\n[3] Peek\n[4] Display\n[5] Exit\nEnter your choice : ");
		scanf("%d", &op);
		scanf("%*[^\n]");
		if(op == 1)
			enqueue();
		else if(op == 2)
			dequeue();
		else if(op == 3)
			peek();
		else if(op == 4)
			display();
		else if(op == 5)
		exit(0);
		else 
		printf("\nInvalid option! Try again...");
	}
	return 0;
}
