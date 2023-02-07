/*
ABEL JOHNSON B200190EE
IMPLEMENTATION OF STACK USING ARRAY
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100
int stack[N]; // integer data array of size 100
int top = -1; // initilizing top

bool isempty()
{
	if(top == -1)
		return 1;
	return 0;
}

void push()
{
	if(top == N-1)
	{
		printf("\n--------------------------------");
		printf("\nOverflow! Aborted...");
		printf("\n--------------------------------");
	}
	else
	{	
		int dat;
		printf("\nEnter your data: ");
		scanf("%d", &dat);
		top++;
		stack[top] = dat;
	}
}

void pop()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nUnderflow! Aborted...");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nElement %d was deleted!", stack[top]);
		printf("\n--------------------------------");
		top--;
	}
}

void peek()
{
	if (isempty())
	{
		printf("\n--------------------------------");
		printf("\nstack is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nThe top element is : %d", stack[top]);
		printf("\n--------------------------------");
	}
}

void display()
{
	if(isempty())
	{
		printf("\n--------------------------------");
		printf("\nStack is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nstack elements : \n");
		for(int i = top; i>-1; i--)
		{
			printf("%d\n", stack[i]);
		}
		printf("\n--------------------------------");
	}
}

int main()
{
	int op;
	
	while(1)
	{
		printf("\n\nSelect your choice\n[1] Push\n[2] Pop \n[3] Peek\n[4] Display\n[5] Exit\nEnter your choice : ");
		scanf(" %d", &op);
		scanf( "%*[^\n]" );
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
