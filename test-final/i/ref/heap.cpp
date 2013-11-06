#include <stdio.h>
#include "heap.h"

#define SWAP(a,b,t)	{ t=a; a=b; b=t; }
Heap::Heap()
{
	root = NULL;
}

struct Node *Heap::get_root(void)
{
	return root;
}


void get_last_node(struct Node *cur, int cur_level, struct Node **last_node, int *last_node_level)
{
	if (cur == NULL)
		return;

	if (cur->left == NULL || cur->right == NULL) { /* non-full node */
		if (cur_level < *last_node_level) {
			*last_node = cur;
			*last_node_level = cur_level;
		}
	}

	get_last_node(cur->left, cur_level+1, last_node, last_node_level);
	get_last_node(cur->right, cur_level+1, last_node, last_node_level);
}

void Heap::insert(struct Node *n)
{
	struct Node *last_node = root, *parent;
	int last_node_level = 50, tmp;

	if (root == NULL) {
		root = n;
		return;
	}

	/* insert n as the last node */
	get_last_node(root, 0, &last_node, &last_node_level);

	if (last_node->left == NULL)
		last_node->left = n;
	else
		last_node->right = n;
	n->parent = last_node;

	/* bubble up the newly inserted node */
	while (n) {
		parent = n->parent;

		if (parent && n->val < parent->val)
			SWAP(n->val, parent->val, tmp)
		else
			break;

		n = n->parent;
	}

}
