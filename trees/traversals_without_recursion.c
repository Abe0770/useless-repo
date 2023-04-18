/*
Abel Johnson B200190EE
COMPILER : gcc (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
}tree;

typedef struct nod {
	tree *node;
	struct node *next;
}nod;

nod *top = NULL;

tree *create(int dat) {
	tree *rootp = (tree *) malloc (sizeof(tree));
	rootp -> data = dat;
	rootp -> left = rootp -> right = NULL;
	return rootp;
}

tree *insert(tree *root, int dat) {
	if(root == NULL)
		return create(dat);
	else if(dat > root -> data)
		root -> right = insert(root -> right, dat);
	else if(dat < root -> data)
		root -> left = insert(root -> left, dat);
	return root;
}

nod insert(tree *temp) {
	nod *new = (nod *)malloc(sizeof(nod));
	new -> nod = temp;
	new -> next = top;
	top = new;
}

node delete() {
	if(top != NULL)
		top = top -> next;
}

tree inorder(tree *root) {
	tree *temp = root;
	while(top != NULL || tree != NULL) {
		if(temp != NULL) {
			insert(temp);
			temp = temp -> left;
		}
		else {
			temp = top -> node;
			delete();
			printf("%d ", temp -> data);
			temp = temp -> right;
		}
	}
}

tree preorder(tree *root) {
}

tree postorder(tree *root) {
}	

int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
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

