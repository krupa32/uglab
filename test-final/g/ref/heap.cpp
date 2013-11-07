#include <stdio.h>
#include "heap.h"

#define SWAP(a,b,t)	{ t=a; a=b; b=t; }

Heap::Heap()
{
	head = NULL;
	count = 0;
}

struct Node *Heap::get_head(void)
{
	return head;
}

struct Node *Heap::get_node_at_pos(int pos)
{
	struct Node *p = head;

	while (--pos)
		p = p->next;

	return p;
}

void Heap::insert(struct Node *n)
{
	struct Node *p = head, *parent;
	int pos, tmp;;

	if (head == NULL) {
		head = n;
		count++;
		return;
	}

	/* insert n as the last node */
	while (p->next)
		p = p->next;
	p->next = n;
	count++;

	/* bubble up the newly inserted node */
	pos = count;
	while (pos > 1) {
		parent = get_node_at_pos(pos/2);

		if (parent && n->val < parent->val)
			SWAP(n->val, parent->val, tmp)
		else
			break;

		n = parent;
		pos /= 2;
	}

}
