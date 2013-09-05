
#include "dblvector.h"

DoubleVector::DoubleVector()
{
}

int DoubleVector::insert(int pos, char c)
{
	Node *n = Node::create(&c);
	Node *p = list.get_node(pos);

	n->insert_after(p->get_prev());

	return 1;
}

int DoubleVector::remove(int pos, char *c)
{

	if (list.empty())
		return 0;

	Node * n = list.get_node(pos);

	n->get_data(c);

	list.remove(n);

	return 1;
}

int DoubleVector::empty(void)
{
	return list.empty();
}

Vector * Vector::create(void)
{
	return new DoubleVector();
}
