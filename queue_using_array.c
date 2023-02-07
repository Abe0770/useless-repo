/*
IMPLEMENTATION OF QUEUE USING ARRAY.
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100
int queue[100];
int front = -1;
int rear = -1;

bool isempty()
{
	if(front == -1 && rear == -1)
		return 1;
	return 0;
}

void enqueue()
{
	if(rear == N-1)
	{
		printf("\n--------------------------------");
		printf("\nOverflow! Aborted...");
		printf("\n--------------------------------");
	}
	else if(isempty())
	{
		int dat;
		printf("\nEnter your data : ");
		scanf("%d", &dat);
		rear = front = 0;
		queue[rear] = dat;
	}
	else
	{
		int dat;
		printf("\nEnter your data : ");
		scanf("%d", &dat);
		rear++;
		queue[rear] = dat;
	}
}

void dequeue()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nUnderflow! Abortting...");
		printf("\n--------------------------------");
	}
	else if(front == rear)
	{
		printf("\n--------------------------------");
		printf("\nElement %d was removed.", queue[front]);
		printf("\n--------------------------------");
		front = -1;
		rear = -1;
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nElement %d was removed.", queue[front]);
		printf("\n--------------------------------");
		front++;
	}
}

void peek()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nQueue is empty.");
		printf("\n--------------------------------");
	}
	else 
	{
		printf("\n--------------------------------");
		printf("\nThe front element of the queue is : %d", queue[front]);
		printf("\n--------------------------------");
	}
}

void display()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nQueue is empty!");
		printf("\n--------------------------------");
	}
	else
	{	
		printf("\n--------------------------------");
		printf("\nElements of the queue are : ");
		for(int i = front; i <= rear; i++)
		{
			printf("\n%d", queue[i]);
		}
		printf("\n--------------------------------");
	}
}

int main()
{
	int op;
	while(1)
	{
		printf("\n\nSelect your choice\n[1] Enqueue\n[2] Dequeue \n[3] Peek\n[4] Display\n[5] Exit\nEnter your choice : ");
		scanf("%d", &op);
		scanf( "%*[^\n]" );
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
