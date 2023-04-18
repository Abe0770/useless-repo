#ifndef DATSTRS_H
#define DATSTRS_H

typedef struct trees {
	int data;
	struct trees *left, *right;
}tree;

typedef struct stack {
	tree *loc;
	struct stack *next;
}stack;

typedef struct queue {
	int data;
	struct queue *next;
}queue;

stack *stack_push(tree *temp, stack **top) {
	stack *new = (stack *) malloc (sizeof(stack));
	new -> loc = temp;
	new -> next = NULL;
	if(*top == NULL) 
		*top = new;
	else {
		new -> next = *top;
		*top = new;
	}
	return *top;
}

queue *enqueue(int dat, queue **front, queue **back) {
	queue *new = (queue*) malloc(sizeof(queue));
	new -> data = dat;
	new -> next = NULL;
	if(*front == NULL) {
		*front = new;
		*back = new;
	}
	else {
		queue *ptr = *back;
		ptr -> next = new;
		*back = new;
	}
	return *front;
}

stack stack_pop(stack **top) {
	stack *ptr = *top;
	*top = ptr -> next;
}

queue *dequeue(queue **front, queue **back) {
	if(*front != NULL) {
		if(*front == *back) {
			free(*front);
			*front = *back = NULL;
		}
		else {
			queue *ptr = *front;
			*front = ptr -> next;
			free(ptr);
		}
	}
	return *front;
}

void q_view(queue *front) {
	while (front != NULL) {
		printf("%d ", front -> data);
		front = front -> next;
	}
}


tree *create_node(int dat) {
	tree *new = (tree*)malloc(sizeof(tree));
	new -> data = dat;
	new -> left = new -> right = NULL;
	return new;
}

void bst(int dat, tree **root) {
	if(*root == NULL)
		*root = create_node(dat);

	else {
		tree *ptr = *root, *lag = ptr;
		int f = 0;
		while(ptr != NULL) {
			lag = ptr;
			if(dat < ptr -> data)
				ptr = ptr -> left;
			else if(dat > ptr -> data)
				ptr = ptr -> right;
			else if(dat == ptr -> data) {
				f++;
				break;
			}
		}
		if(f == 0) {
			dat < lag -> data ? lag -> left = create_node(dat) : (dat > lag -> data ? lag -> right = create_node(dat) : 0);
		} 
	}
}

#endif