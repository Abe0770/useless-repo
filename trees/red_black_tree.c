#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
	int data, r;
	struct tree *left, *right, *parent;
}tree;

tree *temp = NULL;

bool isLeftchild(tree *node) {
	parent -> left == node ? return 1 : return 0;
	return 0;
}

void flipColor(tree *node) {
	node -> r == 1 ? node -> r = 0 : node -> r = 1;
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

tree *create(tree *root, tree *par) {
	tree *new = (tree *)malloc(sizeof(tree));
	new -> data = dat;
	new -> left = new -> right = NULL;
	new -> parent = par;
	new -> r = 1;
	return new;
}

tree *insert(tree *root, int dat, tree *par) {
	if(root == NULL) {
		temp = create(dat, par);
		return temp;
	}
	if(dat < root -> dat)
		root -> left = insert(root -> left, dat, root);
	else if(dat > root -> data)
		root -> right = insert(root -> right, dat, root);
	return root;
}

int isTriangle(tree *node) {
	if(node -> parent -> parent -> right -> left == node)
		return 1;
	else if(node -> parent -> parent -> left -> right == node)
		return 2;
	else if(node -> parent -> parent -> left -> left == node)
		return 3;
	else if(node -> parent -> parent -> right -> right == node)
		return 4;
	return 0;
}

void red_black(tree *root) {
	temp == root ? root -> r = 0, return : 0;
	if(temp -> parent -> parent -> left -> r == 1) {
		flipColor(temp -> parent);
		flipColor(temp -> parent -> parent);
		flipColor(temp -> parent -> parent -> left);
	}
	else if(temp -> parent -> parent -> left -> r == 0) {
		
	}
}

void inorder(tree *root) {
	if(root != NULL) {
		inorder(root -> left);
		r == 1 ? printf("\033[0;31m \e[1mRed - ") : printf("\n\033[0;30m\e[1mBlack - ");
		printf("%d\n", root -> data);
		inorder(root -> right);
	}
}

int main() {
	FILE *f;
	tree *root, *par = NULL;
	int dat;
	f = fopen("input.txt", "r");
	!f ? printf("Error : File doesn't exist! "), exit(0) : 0; 
	while(fscanf(f, "%d", &dat) != EOF) {
		root = insert(root, dat, par);
		red_black(root);	
	}
	inorder(root);
	return 0;
}
