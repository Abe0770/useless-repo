#include <stdio.h>
#include <stdlib.h>
#include "datstrs.h" // tree, stack and queue related functions

stack *top = NULL;

void inorder(tree *root) {
    while(root != NULL || top != NULL) {
        if(root != NULL) {
            stack_push(root, &top);
            root = root -> left;
        }
        else {
            root = top -> loc;
            stack_pop(&top);
            printf("%d ", root -> data);
            root = root -> right;
        }
    }   
}

void preorder(tree *root) {
	stack_push(root, &top);
	while(top != NULL) {
		stack *temp = top;
		stack_pop(&top);
		printf("%d ", temp -> loc -> data);
		if(temp -> loc -> right) 
			stack_push(temp -> loc -> right, &top);
		if(temp -> loc -> left)
			stack_push(temp -> loc -> left, &top);
	}
}

void postorder(tree *root) {
	stack *out_stack_top = NULL;
	stack_push(root, &top);
	while(top != NULL) {
		stack *temp = top;
		stack_pop(&top);
		stack_push(temp -> loc, &out_stack_top);
		if(temp -> loc -> left) 
			stack_push(temp -> loc -> left, &top);
		if(temp -> loc -> right) 
			stack_push(temp -> loc -> right, &top);
	}
	while(out_stack_top != NULL) {
		printf("%d ", out_stack_top -> loc -> data);
		stack_pop(&out_stack_top);
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
		bst(dat, &root);
	printf("Inorder   : ");
		inorder(root);
	printf("\nPreorder  : ");
		preorder(root);
	printf("\nPostorder : ");
		postorder(root);
	return 0;
}