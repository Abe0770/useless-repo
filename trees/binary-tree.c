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
		return create(dat);
	else if(dat > root -> data)
		root -> right = insert(root -> right, dat);
	else if(dat < root -> data)
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
	int op, dat;
	tree *root = NULL;
	while(1) {
		printf("\nSelect an option : \n[1] Insert to binary tree \n[2] Display Pre-order \n[3] Display Post-order \n[4] Display In-order \n[5] Exit \nEnter your option : ");
		scanf("%d", &op);

		if(op == 1) {
			printf("\nEnter your data : ");
			scanf("%d", &dat);
			root = insert(root, dat);
		}
		else if(op == 2) 
			preorder(root);
		else if(op == 3)
			postorder(root);
		else if(op == 4) 
			inorder(root);
		else if(op == 5) 
			exit(0);
		else 
			printf("Invaid Input... Try again!");
	}
	return 0;
}
