/*
ABEL JOHNSON B200190EE
SET UNION
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *link;
} node;

node *head1 = NULL, *head2 = NULL, *tail = NULL;

bool check(int dat, node *sike) {	
	node *ptr = sike;
	while(ptr != NULL) {
		if(ptr -> data == dat) {
			return true;
		}
		ptr = ptr -> link;
	}
	return false;
}

node *insert(int n, node *bruh) {
	if(n > 0) {
		bruh = insert(--n, bruh);
		int dat;
		printf("\nEnter your data : ");
		scanf("%d", &dat);
		node *new = (node *)malloc(sizeof(node));
		new -> data = dat;
		new -> link = NULL;
		if(bruh == NULL) {
			bruh = new;
			tail = new;
		}
		else {
			if(check(dat, bruh)) {
				printf("\nThe element %d already exists!\n", dat);
				free(new);
				return bruh;
			}
			tail -> link = new;
			tail = new;
		}
	}
	return bruh;
}

node display(node *head1, node *head2) {
	printf("\nThe elements of SET-A : ");
	node *ptr = head1;
	while(ptr != NULL) {
		printf("%d ", ptr -> data);
		ptr = ptr -> link;
	}
	printf("\nThe elements of SET-B : ");
	ptr = head2;
	while(ptr != NULL) {
		printf("%d ", ptr -> data);
		ptr = ptr -> link;
	}
}

node sort() {
	for(node *ptr1 = head1; ptr1 -> link != NULL; ptr1 = ptr1 -> link) {
		for(node *ptr2 = ptr1 -> link , *lag = ptr1; ptr2 != NULL; ptr2 = ptr2 -> link) {
			if(ptr1 -> data > ptr2 -> data) {
				int temp = ptr1 -> data;
				ptr1 -> data = ptr2 -> data;
				ptr2 -> data = temp;
			}
			else if (ptr1 -> data == ptr2 -> data) {
				lag -> link = ptr2 -> link;
				continue;
			}
			lag = ptr2;
		}	
	}
	
	node *ptr = head1;
	printf("\nUnion of the sets : ");
	while(ptr != NULL) {
		printf("%d ", ptr -> data);
		ptr = ptr -> link;
	}
}

node *unio() {
	if(head1 == NULL && head2 == NULL) {
		printf("\nUnion doesn't exist!");
		return head1;
	}
	else if(head1 == NULL) {
		head1 = head2;
		return head1;
	}
	else if(head2 == NULL)
		return head1;
	node *ptr = head1;
	while(ptr -> link != NULL) {
		ptr = ptr -> link;
	}
	ptr -> link = head2;
	sort();
	return head1;
}

int main() {
	int n;
	printf("\nEnter the number of elements in set-A : ");
	scanf("%d", &n);
	head1 = insert(n, head1);
	printf("\nEnter the number of elements in set-B : ");
	scanf("%d", &n);
	head2 = insert(n, head2);
	display(head1, head2);
	unio();
	return 0;
}
