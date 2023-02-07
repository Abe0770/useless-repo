/*
ABEL JOHNSON B200190EE
INSERTING ELEMENTS IN A SORTED MANNER USING LINKED LIST
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *link;
} *head = NULL;

void insert(int dat)
{	
	struct node *p = head, *a=NULL;
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr -> data = dat;
	ptr -> link = NULL;
	
	if(head == NULL)
	{

		head = ptr;
	}
	else
	{
		while( p != NULL)
		{
			if (dat == p -> data)
			break;
			if(p -> link == NULL && dat > p -> data)
			{
				p -> link = ptr;
				break;
			}
			else if( dat > p -> data)
			{
				a = p;
				p = p -> link;
			}
			else if ( dat < p->data)
			{
				if ( a == NULL ){
					head = ptr;
					ptr->link = p;
					break;
				}
				a -> link = ptr;
				ptr->link =p;
				break;
			}
		}
	}
}

void display()
{
	if(head == NULL)
	{
		printf("\n--------------------------------");
		printf("\nThe linked list is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		struct node *ptr;
		ptr = head;
		printf("\n-----------------------------------------");
		printf("\nThe elements of the linked list are :\n");
		while(ptr != NULL)
		{
			printf("%d\n", ptr -> data);
			ptr = ptr -> link;
		}
		printf("\n-----------------------------------------");
	}
}


int main()
{
	int op, dat;
	while(1)
	{
		printf("\n\nSelect your choice\n[1] Insert\n[2] Display\n[3] Exit\nEnter your choice : ");
		scanf("%d", &op);
		scanf("%*[^\n]");
		if(op == 1)
		{
			printf("\nEnter your data : ");
			scanf("%d", &dat);
			insert(dat);
		}
		else if(op == 2)
			display();
		else if(op == 3)
		exit(0);
		else 
		printf("\nInvalid option! Try again...");
	}
	return 0;
}
