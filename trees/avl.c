#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
	int data, h;
	struct tree *left, *right;
}tree;

int height(tree *node) {
	if(node == NULL)
		return 0;
	return node -> h;
}

tree *create(int dat) {
	tree *new = (tree *)malloc(sizeof(tree));
	new -> data = dat;
	new -> h = 1;
	new -> left = new -> right = NULL;
	return new;
}

int balance(tree *node) {
	if(node == NULL) 
		return 0;
	return height(node -> left) - height(node -> right);
}

int max(int x, int y) {
	return x > y ? x : y; 
}

tree *right_rotate(tree *root) {
	tree *lef = root -> left;
	tree *lef_rig = lef -> right;
	lef -> right = root;
	root -> left = lef_rig;
	root -> h = max(height(root -> right), height(root -> left)) + 1;
	lef -> h = max(height(lef -> right), height(lef -> left)) + 1;
	return lef;
}

tree *left_rotate(tree *root) {
	tree *rig = root -> right;
	tree *rig_lef = rig -> left;
	rig -> left = root;
	root -> right = rig_lef;
	root -> h = max(height(root -> right), height(root -> left)) + 1;
	rig -> h = max(height(root -> right), height(root -> left)) + 1;
	return rig;
}

tree *insert(tree *root, int dat) {
	if(root == NULL) 
		return create(dat);
	if(dat < root -> data) 
		root -> left = insert(root -> left, dat);
	else if(dat > root -> data)
		root -> right = insert(root -> right, dat);
	root -> h = max(height(root -> left), height(root -> right)) + 1;
	int bal = balance(root);
	
	if(bal > 1 && dat < root -> left -> data) 
		return right_rotate(root);
	if(bal < -1 && dat > root -> right -> data) 
		return left_rotate(root);
	if(bal > 1 && dat > root -> left -> data) {
		root -> left = left_rotate(root -> left);
		return right_rotate(root);
	}
	if(bal < -1 && dat < root -> right -> data) {
		root -> right = right_rotate(root -> right);
		return left_rotate(root);
	}
	return root;
}

void preorder(tree *root) {
	if(root != NULL) {
		printf("%d ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

int main() {
	tree *root = NULL;
	FILE *f;
	f = fopen("input.txt", "r");
	if(!f ? printf("Error : File doesn't exist! ") : 0)
		exit(0);
	int dat;
	while(fscanf(f, "%d", &dat) != EOF)
		root = insert(root, dat);
	
	preorder(root);	
	
	return 0;
}
