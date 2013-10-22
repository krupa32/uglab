#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

BSTree::BSTree()
{
	root = NULL;
}

void BSTree::add(int val)
{
	struct BSTreeNode *n, *p = root, *parent;

	n = (struct BSTreeNode *)malloc(sizeof(*n));

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

int BSTree::search(int val)
{
	struct BSTreeNode *p = root;

	while (p) {

		if (val == p->val)
			break;
		else if (val < p->val)
			p = p->left;
		else
			p = p->right;
	}

	return (p != NULL);
}


int BSTree::do_get_height(struct BSTreeNode *p)
{
	int l, r;

	if (p == NULL)
		return -1;

	l = do_get_height(p->left);
	r = do_get_height(p->right);

	return (l > r) ? (l + 1) : (r + 1);
}

int BSTree::get_balancing_factor(void)
{
	int lh, rh;

	lh = do_get_height(root->left) + 1;
	rh = do_get_height(root->right) + 1;

	return (lh - rh);
}


