#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

BSTree::BSTree()
{
	root = NULL;
}

void BSTree::insert(int val)
{
	struct Node *n, *p = root, *parent;

	n = (struct Node *) malloc(sizeof(*n));
	n->val = val;
	n->left = NULL;
	n->right = NULL;

	if (root == NULL) {
		root = n;
		return;
	}

	while (p) {
		parent = p;
		if (val < p->val)
			p = p->left;
		else
			p = p->right;
	}

	if (val < parent->val)
		parent->left = n;
	else
		parent->right = n;
}

void BSTree::do_postorder(struct Node *n, int *arr, int *count)
{
	if (n == NULL)
		return;

	do_postorder(n->left, arr, count);
	do_postorder(n->right, arr, count);

	arr[*count] = n->val;

	(*count)++;
}

void BSTree::postorder(int *arr, int *count)
{
	*count = 0;
	do_postorder(root, arr, count);
}

int BSTree::search(int val, int *nops)
{
	struct Node *p = root;

	*nops = 0;

	while (p) {
		
		(*nops)++;

		if (val < p->val)
			p = p->left;
		else if (val > p->val)
			p = p->right;
		else
			break;
	}
	
	return (p != NULL);
}
