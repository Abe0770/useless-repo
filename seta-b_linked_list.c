/*
ABEL JOHNSON B200190EE
COMPILER - gcc (GCC) 12.2.1 20220819 (Red Hat 12.2.1-2)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *link;
} list;

int check = 0;

list *head = NULL, *tail = NULL, *setb = NULL;

int repeat(int dat, int check) {
	list *ptr = NULL;
	if (check == 0)
		ptr = head;
	else
		ptr = setb;
	while(ptr != NULL) {
		if(dat == ptr -> data) 
			return 1;
		ptr = ptr -> link;
	}
	return 0;
}

list insert() {
	int dat;
	list *new = (list *)malloc(sizeof(list));
	if(check == 0) { 
		beg1:
		printf("\nEnter the data for set A : ");
		scanf("%d", &dat);
		if(repeat(dat, check)) {
			printf("\nThe element already exists in set A... Try again!");
			goto beg1;
		}
		new -> data = dat;
		if(head == NULL) {
			new -> link = head;
			head = new;
			tail = new;
		}
		else {
			new -> link = NULL;
			tail -> link = new;
			tail = new;
		}
	}
	else {
		beg2:
		printf("\nEnter the data for set B : ");
		scanf("%d", &dat);
		if(repeat(dat, check)) {
			printf("\nThe element already exists in set B... Try again!");
			goto beg2;
		}
		new -> data = dat;
		if(head == NULL) {
			new -> link = setb;
			head = new;
			tail = new;
			setb = head;
		}
		else if(setb == NULL){
			new -> link = NULL;
			tail -> link = new;
			setb = new;
			tail = new;
		}
		else {
			new -> link = NULL;
			tail -> link = new;
			tail = new;
		}
	}
}

list sort() {
	int temp;
	for(list *ptr = head; ptr != setb; ptr = ptr -> link) {
		for(list *ptr2 = ptr -> link; ptr2 != setb; ptr2 = ptr2 -> link) {
			if(ptr -> data > ptr2 -> data) {
				temp = ptr -> data;
				ptr -> data = ptr2 -> data;
				ptr2 -> data = temp;
			}
		}
	}
	list *ptr = head;
	printf("\nThe resulting subtracted and sorted set A : ");
	while(ptr != setb) {
		printf("%d ", ptr -> data);
		ptr = ptr -> link;
	}
}

list *display() {
	list *ptr = head;
	int f = 0;
	printf("\nThe elements of set A :");
	while(ptr != NULL) {
		if(ptr == setb) {
			f++;
			printf("\nThe elements of set B : ");
		}
		if(f == 0) {
			printf("%d ", ptr -> data);
			ptr = ptr -> link;
		}
		else {
			printf("%d ", ptr -> data);
			ptr = ptr -> link;
		}
	}
}

list subtract() {
	list *ptr1 = head, *ptr2 = setb;
	while(ptr1!=NULL && ptr2 != NULL && ptr1 != setb) {
		ptr1 -> data = ptr1 -> data - ptr2 -> data;
		ptr1 = ptr1 -> link;
		ptr2 = ptr2 -> link;
	}
	sort();
}

void freeList(list* node){
	if(node!= NULL) {
	freeList(node->link);
	free(node);
	}
}

int main() {
	int na;
	printf("\nEnter the number of elements in set A : ");
	scanf("%d", &na);
	while(na--)
	insert();
	check++;
	printf("\nEnter the number of elements in set b : ");
	scanf("%d", &na);
	while(na--)
	insert();
	display();
	subtract();
	freeList(head);
	return 0;
}