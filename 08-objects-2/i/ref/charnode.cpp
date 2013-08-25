#include "charnode.h"

CharNode::CharNode(char ch)
{
	c = ch;
}

void CharNode::get_data(void *p)
{
	*(char *)p = c;
}

Node *Node::create(void *p)
{
	CharNode *n;

	if (p)
		n = new CharNode(*(char *)p);
	else
		n = new CharNode(0);

	return n;
}
