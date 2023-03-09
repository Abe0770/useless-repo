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

tree *create(int dat) {
	tree *rootp = (tree *) malloc (sizeof(tree));
	rootp -> data = dat;
	rootp -> left = 	rootp -> right = NULL;
	return rootp;
}

tree *insert(tree *root, int dat) {
	if(root == NULL)
		return create(dat); else if(dat > root -> data)
		root -> right = insert(root -> right, dat); else if(dat < root -> data)
		root -> left = insert(root -> left, dat);
	return root;
}

tree inorder(tree *root) {	
	if(root != NULL) {
		inorder(root -> left);
		printf(" %d ", root -> data);
		inorder(root -> right);
	}
}

tree preorder(tree *root) {
	if(root != NULL) {
		printf(" %d ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

tree postorder(tree *root) {
	if(root != NULL) {
		postorder(root -> left);
		postorder(root -> right);
		printf(" %d ", root -> data);
	}
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
	while(fscanf(fp, "%d", &dat) != EOF) 
		root = insert(root, dat);
	
	printf("Pre-order  : ");
	preorder(root);
	printf("\nPost-order : ");
	postorder(root);
	printf("\nIn-order   : ");
	inorder(root);
	printf("\n");
	return 0;
}

