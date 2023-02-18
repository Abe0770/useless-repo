/*
Abel Johnson B200190EE
COMPILER : gcc (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lvl = 1, nthchild = 1, tlvl = 0, tnt = 0;

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
}tree;

typedef struct queue {
	tree* node;
	struct queue *link;
}queue;

queue *head = NULL, *tail = NULL;
tree *temp = NULL;

tree *create(tree *rootp, int dat1) {
	tree *new = (tree *)malloc(sizeof(tree));
	new -> data = dat1;
	new -> left = new -> right = NULL;
	return new;
}

queue createnode(tree *root) {
	queue *new = (queue *) malloc(sizeof(queue));
	new -> node = root;
	new -> link = NULL;
	if(head == NULL) {
		head = new;
		tail = head;
	}	
	else {
		tail -> link = new;
		tail = new;
	}
}

queue deletenode() {
	head = head -> link;
	if (head == NULL)
        	tail = NULL;
}

tree *insert (tree *root , int dat)
{
	if(root == NULL)
		return create(root, dat);
	
	createnode(root);
	
	while(head != NULL) {
		tree *temp = head -> node;
		deletenode();
		
		if(temp -> left == NULL) {
			temp -> left = create(root, dat);
			head = NULL;
			tail = NULL;
			return root;
		}
		else {
			createnode(temp -> left);
			createnode(temp -> right);
		}
		if(temp -> right == NULL) {
			temp -> right = create(root, dat);
			head = NULL;
			tail = NULL;
			return root;
		}
		else {
			createnode(temp -> left);
			createnode(temp -> right);
		}
		
	}
	return root;
}

tree inorder(tree *root) {
	if(root != NULL) {
		inorder(root -> left);
		printf("%d ", root -> data);
		inorder(root -> right);
	}
}

tree preorder(tree *root) {
	if(root != NULL) {
		printf("%d ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

tree postorder(tree *root) {
	if(root != NULL) {
		postorder(root -> left);
		postorder(root -> right);
		printf("%d ", root -> data);
	}
}

int main() {
	FILE *fp;
	fp = fopen("../input.txt", "r");
	if (fp == NULL) {
		printf("\nError in opening input.txt\n");
		exit(0);
	}
	tree *root = NULL;
	int op, dat;
	while(fscanf(fp, "%d", &dat) != EOF) {
		root = insert(root, dat);
	}
	printf("Pre-order  : ");
	preorder(root);
	printf("\nPost-order : ");
	postorder(root);
	printf("\nIn-order   : ");
	inorder(root);
	printf("\n");
	return 0;
}
