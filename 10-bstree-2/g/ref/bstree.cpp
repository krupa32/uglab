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


void BSTree::do_preorder(struct BSTreeNode *p, int *arr, int *count)
{
	if (p == NULL)
		return;

	arr[*count] = p->val;
	(*count)++;

	do_preorder(p->left, arr, count);
	do_preorder(p->right, arr, count);
}

void BSTree::get_preorder(int *arr, int *count)
{
	*count = 0;
	do_preorder(root, arr, count);
}

int BSTree::do_count_non_leaf_nodes(struct BSTreeNode *p)
{
	int l, r;

	if (p == NULL)
		return 0;

	if (p->left == NULL && p->right == NULL)
		return 0;

	l = do_count_non_leaf_nodes(p->left);
	r = do_count_non_leaf_nodes(p->right);

	return l + r + 1;
}

int BSTree::count_non_leaf_nodes(void)
{
	return do_count_non_leaf_nodes(root);
}

void BSTree::remove_node(struct BSTreeNode *p, struct BSTreeNode *parent)
{
	struct BSTreeNode *min;
	int tmp;

	if (p->right == NULL) { /* no right subtree */

		if (parent == NULL) /* root */
			root = p->left;
		else if (parent->left == p)
			parent->left = p->left;
		else
			parent->right = p->left;

		return;
	}

	/* find min node in the right subtree */
	min = p->right;
	parent = p;
	while (min->left) {
		parent = min;
		min = min->left;
	}

	/* swap values of p and min */
	tmp = p->val;
	p->val = min->val;
	min->val = tmp;

	/* remove the min node now */
	remove_node(min, parent);
}

void BSTree::remove(int val)
{
	struct BSTreeNode *p = root, *parent = NULL;

	while (p) {
		if (val == p->val)
			break;
		else if (val < p->val) {
			parent = p;
			p = p->left;
		} else {
			parent = p;
			p = p->right;
		}
	}

	if (p == NULL) /* not found */
		return;

	remove_node(p, parent);
}
