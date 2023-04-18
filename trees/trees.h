#ifndef TREES_H
#define TREES_H

typedef struct tree {
	int data;
	struct tree *left, *right;
}tree;

tree *root = NULL;



tree *insert_1(int dat, tree *temp) {
	if (temp == NULL) {
		return temp;
	}
	return temp;
}

tree insert(int dat) {
	root = insert_1(dat, root);
}

#endif
