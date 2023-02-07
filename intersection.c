/*
ABEL JOHNSON B200190EE
SET UNION
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
int arr[1000], n1=0;
typedef struct list1 {
	int data;
	struct list1 *link;
}L1;
L1 *head1 = NULL;

typedef struct list2 {
	int data;
	struct list2 *link;
}L2;
L2 *head2 = NULL;

void insert1()
{
	int dat;	
	L1 *new = (L1 *) malloc(sizeof(L1));
	printf("\nEnter your data : ");
	scanf("%d", &dat);
	arr[n1] = dat;
	L1 *ptr = head1;
	int flag = 0;
	L1 *t;
	while( ptr != NULL)
	{
		if(dat == ptr -> data)
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
		if(head1 == NULL)
		{
			new -> data = dat;
			new -> link = NULL;
			head1 = new; 
		}
		else
		{
			new -> data = dat;
			new -> link = NULL;
			t -> link = new;
		}
	}
	n1++;
}

void insert2()
{
	int dat;	
	L2 *new = (L2 *) malloc(sizeof(L2));
	printf("\nEnter your data : ");
	scanf("%d", &dat);
	L2 *ptr = head2;
	int flag = 0;
	L2 *t;
	while( ptr != NULL)
	{
		if(dat == ptr -> data)
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
		if(head2 == NULL)
		{
			new -> data = dat;
			new -> link = NULL;
			head2 = new; 
		}
		else
		{
			new -> data = dat;
			new -> link = NULL;
			t -> link = new;
		}
	}
}


void display()
{
	printf("\nThe elements of set A : ");
	for(int i=0; i<n1; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n\nThe elements of set B : ");
	if(head2 == NULL) {
		printf("NULL");
	}
	else {
		L2 *ptr;
		ptr = head2;
		while(ptr != NULL) {
			printf("%d ", ptr -> data);
			ptr = ptr -> link;
		}
	}
	if(head1 == NULL && head2 == NULL) {
		printf("\n\n--------------------------------");
		printf("\nUnion list is empty!");
		printf("\n--------------------------------");
	}
	else {
		L1 *ptr;
		ptr = head1;
		printf("\n--------------------------------");
		printf("\nThe elements of the Intersection list are : \n");
		while(ptr != NULL) {
			printf("%d\n", ptr -> data);
			ptr = ptr -> link;
		}
		printf("\n--------------------------------");
	}
}

void inters() {
	L1 *p1 = head1, *temp = head1;
	L2 *p2 = head2;
	int f = 0;
	if(head1 == NULL || head2 == NULL) {
			printf("\nNo intersection!");
			exit(0);
	}
	for(L1 *ptr1 = head1; ptr1 != NULL; ptr1 = ptr1 -> link) {
		for(L2 *ptr2 = head2; ptr2 != NULL; ptr2 = ptr2 -> link) {
			if(ptr1 -> data == ptr2 -> data) {
				f++;
			}
		}
		if(f == 0) {
			temp -> link = ptr1 -> link;
		}
		temp = ptr1;
		f = 0;
	}
	display();
}

int main() {
	int op, n, flag = 0;
			printf("\nEnter the number of elements to add to list A: ");
			scanf("%d", &n);
			for(int i=0; i<n; i++) {
				insert1();
			}	
			printf("\nEnter the number of elements to add to list B: ");
			scanf("%d", &n);
			for(int i=0; i<n; i++) {
				insert2(op);
			}
			inters();
	return 0;
}
