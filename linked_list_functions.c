/*
ABEL JOHNSON B200190EE
IMPLEMENTATION OF FUNCTIONS in linked list
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int dat;
	struct node *link;
} *head = NULL;

void insert()
{
	int data;	
	struct node *new = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter your data : ");
	scanf("%d", &data);
	struct node *ptr = head;
	int flag = 0;
	struct node *t;
	while( ptr != NULL)
	{
		if(data == ptr -> dat)
		{
			flag++;
			break;
		}
		if ( ptr->link != NULL){
			ptr = ptr -> link;
		}else {
			t = ptr;
			break;
		}
	}	
	if(flag == 0)
	{
		if(head == NULL)
		{
			new -> dat = data;
			new -> link = NULL;
			head = new; 
		}
		else
		{
			new -> dat = data;
			new -> link = NULL;
			t -> link = new;
		}
	}
}

void delete() //deletion from top
{
	if(head == NULL)
	{
		printf("\n--------------------------------");
		printf("\nThe linked list is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nThe element %d was deleted.", head -> dat);
		printf("\n--------------------------------");
		head = head -> link;
	}
}

void display()
{
	if(head == NULL)
	{
		printf("\n--------------------------------");
		printf("\nlinked list is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		struct node *ptr;
		ptr = head;
		printf("\n--------------------------------");
		printf("\nThe elements of the linked list are : \n");
		while(ptr != NULL)
		{
			printf("%d\n", ptr -> dat);
			ptr = ptr -> link;
		}
		printf("\n--------------------------------");
	}
}

int main()
{
	int op;
	while(1)
	{
		printf("\n\nSelect your choice\n[1] Insert\n[2] Delete\n[3] Display\n[4] Exit\nEnter your choice : ");
		scanf("%d", &op);
		scanf("%*[^\n]");
		if(op == 1)
			insert();
		else if(op == 2)
			delete();
		else if(op == 3)
			display();
		else if(op == 4)
		exit(0);
		else 
		printf("\nInvalid option! Try again...");
	}
	return 0;
}
