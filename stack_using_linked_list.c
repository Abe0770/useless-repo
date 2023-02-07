/*
ABEL JOHNSON B200190EE
IMPLEMENTATION OF STACK USING LINKED LIST
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int dat;
	struct node *link;
} *top = NULL;

void push()
{
	int dat;	
	struct node *new = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter your data : ");
	scanf("%d", &dat);
	new -> dat = dat;
	new -> link = top;
	top = new; 
}

void pop()
{
	if(top == NULL)
	{
		printf("\n--------------------------------");
		printf("\nThe stack is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nThe element %d was deleted.", top -> dat);
		printf("\n--------------------------------");
		top = top -> link;
	}
}

void display()
{
	if(top == NULL)
	{
		printf("\n--------------------------------");
		printf("\nStack is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		struct node *ptr;
		ptr = top;
		printf("\n--------------------------------");
		printf("\nThe elements of the stack are : \n");
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
	if(top != NULL)
	{
		printf("\n--------------------------------");
		printf("\nThe top element of the stack is : %d", top -> dat);
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nThe stack is empty!");
		printf("\n--------------------------------");
	}
}

int main()
{
	int op;
	while(1)
	{
		printf("\n\nSelect your choice\n[1] push\n[2] pop\n[3] Peek\n[4] Display\n[5] Exit\nEnter your choice : ");
		scanf("%d", &op);
		scanf("%*[^\n]");
		if(op == 1)
			push();
		else if(op == 2)
			pop();
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
