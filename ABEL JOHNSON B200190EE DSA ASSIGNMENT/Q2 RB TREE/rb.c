#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	struct node *right, *left;
	int data;
	char color;
} node;

typedef struct tree
{
	struct node *root;
} tree;

void preorder(struct node *root, FILE *o) {
	if (root != NULL)
	{
		fprintf(o, "( %d %c ", root->data, root->color);
		preorder(root->left, o);
		preorder(root->right, o);
		fprintf(o, ") ");
	}
	else
		fprintf(o, "( ) ");
}

void deallocate(struct node *root) {
	if (root == NULL)
		return;
	deallocate(root->left);
	deallocate(root->right);
	free(root);
}

node *left_rotate(node *root)
{
	node *x = root;
	node *y = x->right;

	x->right = y->left;

	y->left = x;

	return y;
}

node *right_rotate(node *root)
{
	node *x = root;
	node *y = x->left;

	x->left = y->right;

	y->right = x;

	return y;
}

node *createnode(int x) {
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = x;
	new_node->color = 'R';
	new_node->left = new_node->right = NULL;
	return new_node;
}

node *insert(node *root, int x){
	if (root == NULL)
		return (createnode(x));
	else if (x < root->data){
		root->left = insert(root->left, x);
		if (root->left->color == 'B')
			return root;
		else {
			if ((root->left->left != NULL && root->left->left->color == 'R') || (root->left->right != NULL && root->left->right->color == 'R')) {
				if (root->right !=NULL && root->right->color == 'R') {
					root->right->color = 'B';
					root->left->color = 'B';
					root->color = 'R';
					return root;
				}
				else {
					if (root->left->right != NULL && root->left->right->color == 'R') {
						root->left = left_rotate(root->left);
					}
					node *y = right_rotate(root);
					y->right->color = 'R';
					y->color = 'B';
					return y;
				}
			}
			else
				return root;
		}
	}
	else {
		root->right = insert(root->right, x);
		if (root->right->color == 'B')
			return root;
		else {
			if ((root->right->right != NULL && root->right->right->color == 'R') || (root->right->left != NULL && root->right->left->color == 'R')) {
				if (root->left!=NULL && root->left->color == 'R') {
					root->left->color = 'B';
					root->right->color = 'B';
					root->color = 'R';
					return root;
				}
				else {
					if (root->right->left != NULL && root->right->left->color == 'R') {
						root->right = right_rotate(root->right);
					}
					node *y = left_rotate(root);
					y->left->color = 'R';
					y->color = 'B';
					return y;
				}
			}
			else
				return root;
		}
	}

	return root;
}


int main()
{
	char c;
	int dat;
	tree *T = (tree *)malloc(sizeof(tree));
	T->root = NULL;
	FILE *f = fopen("input.txt", "r");
	FILE *o = fopen("output.txt", "w");
	!f ? printf("Error : File doesn't exist!"), exit(0) : 0;    
	while (fscanf(f, "%d", &dat) != EOF)
	{
		T->root = insert(T->root, dat);
		T->root->color = 'B';
		preorder(T->root, o);
		fprintf(o, "\n");
	}
	printf("-----------------------------------------\nOutput was stored in output.txt file...\n-----------------------------------------\n");
	deallocate(T->root);
	fclose(o);
	fclose(f);
	return 0;
}
