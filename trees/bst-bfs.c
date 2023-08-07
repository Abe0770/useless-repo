#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
} tree;

typedef struct queue {
	tree* Node;
	struct queue *next;
} queue;

tree * createNode(int data) {
	tree * newNode = (tree *) malloc(sizeof(tree));
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}

tree * insertNode(tree * root, int data) {
	if(!root) 
		return createNode(data);
	if(data >= root -> data) 
		root -> right = insertNode(root -> right, data);
	else
		root -> left = insertNode(root -> left, data);
	return root;
}

void preorder(tree * root) {
	if(root) {
		printf("%d ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

queue * push(queue * front, tree * root) {
	queue * newNode = (queue *) malloc(sizeof(queue));
	newNode -> Node = root;
	newNode -> next = NULL;
	if(!front)
		front = newNode;
	else {
		queue * ptr = front;
		while(ptr -> next != NULL) 
			ptr = ptr -> next;
		ptr -> next = newNode;
	}
	return front;
}

queue * pop(queue *front) {
	queue * temp = front;
	front = front -> next;
	free(temp);
	return front;
}

int getSize(queue * front) {
	int count = 0;
	while(front != NULL) {
		++count;
		front = front -> next;
	}
	return count;
}

void bfs(tree *root) {
	if(root) {
		queue  * front = NULL;
		front = push(front, root);
		int a = 0;
		while(front) {
			int size = getSize(front);
			for(int i = 0 ; i < size ; i++) {
				printf("%d ", front -> Node -> data);
				if(front -> Node -> left)
					push(front, front -> Node -> left);
				if(front -> Node -> right)
					push(front, front -> Node -> right);
				front = pop(front);
			}
		}
	} else 
		printf("Tree is empty!");
}

int main() {
	int a[12] = {0, 10, 20, 5, 7, 17, -10, -20, -5, -7, -17, -2};
	int n = sizeof(a) / sizeof(int);
	tree * root = NULL;
	for(int i = 0; i < n ; i++) 
		root = insertNode(root, a[i]);
	preorder(root);
	printf("\nBFS : ");
	bfs(root);
	
	return 0;
}
