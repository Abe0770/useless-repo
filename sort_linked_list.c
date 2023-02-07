/*
ABEL JOHNSON B200190EE
IMPLEMENTATION OF STACK USING LINKED LIST
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *link;
} *head = NULL;

void insert()
{
	int dat;
	
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("\nEnter your data : ");
		scanf("%d", &dat);
		ptr -> data = dat;
		ptr -> link = NULL;
		head = ptr;
	}
	else
	{
		printf("\nEnter your data : ");
		scanf("%d", &dat);
		ptr -> data = dat;
		ptr -> link = NULL;
		struct node *temp;
		temp = head;
		while(temp -> link != NULL)
		{
			temp = temp -> link;
		}
		temp -> link = ptr;
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

void sort() // bubble sort
{
	int temp = 0;
	struct node *i, *j;
	for(i=head; i!=NULL; i = i -> link)
	{
		for(j = i->link; j!= NULL; j = j-> link)
		{
			if(j-> data < i -> data)
			{
				temp = i -> data;
				i-> data = j -> data;
				j -> data = temp;
			}
		}
	}
	display();
}

int main()
{
	int op;
	while(1)
	{
		printf("\n\nSelect your choice\n[1] Insert\n[2] Sort\n[3] Display\n[4] Exit\nEnter your choice : ");
		scanf("%d", &op);
		scanf("%*[^\n]");
		if(op == 1)
			insert();
		else if(op == 2)
			sort();
		else if(op == 3)
			display();
		else if(op == 4)
		exit(0);
		else 
		printf("\nInvalid option! Try again...");
	}
	return 0;
}
