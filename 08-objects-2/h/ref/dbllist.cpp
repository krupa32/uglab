#include <stdio.h>
#include "dbllist.h"

DblList::DblList()
{
	head = Node::create(NULL);
}

void DblList::add_head(Node *n)
{
	n->insert_after(head);
}

void DblList::add_tail(Node *n)
{
	n->insert_after(head->get_prev());
}

Node *DblList::get_node(int pos)
{
	int i = 0;
	Node * p = head->get_next();

	while (p != head) {
		if (i == pos)
			break;

		i++;
		p = p->get_next();
	}

	return p;
}

void DblList::remove(Node *n)
{
	n->remove();
	delete n;
}

int DblList::empty(void)
{
	return (head == head->get_next());
}
