#include "node.h"

Node::Node()
{
	prev = this;
	next = this;
}

Node *Node::get_prev(void)
{
	return prev;
}

Node *Node::get_next(void)
{
	return next;
}

void Node::insert_after(Node *p)
{
	Node *n = p->next;

	next = n;
	prev = p;

	p->next = this;
	n->prev = this;
}

void Node::remove(void)
{
	prev->next = next;
	next->prev = prev;
}

