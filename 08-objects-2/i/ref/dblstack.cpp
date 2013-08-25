
#include "dblstack.h"

DoubleStack::DoubleStack()
{
}

int DoubleStack::push(char c)
{
	Node * n = Node::create(&c);

	list.add_head(n);

	return 1;
}

int DoubleStack::pop(char *c)
{

	if (list.empty())
		return 0;

	Node * n = list.get_node(0);

	n->get_data(c);

	list.remove(n);

	return 1;
}

int DoubleStack::empty(void)
{
	return list.empty();
}

Stack * Stack::create(void)
{
	return new DoubleStack();
}
