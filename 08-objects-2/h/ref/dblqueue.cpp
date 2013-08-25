
#include "dblqueue.h"

DoubleQueue::DoubleQueue()
{
}

int DoubleQueue::insert(char c)
{
	Node * n = Node::create(&c);

	list.add_tail(n);

	return 1;
}

int DoubleQueue::remove(char *c)
{

	if (list.empty())
		return 0;

	Node * n = list.get_node(0);

	n->get_data(c);

	list.remove(n);

	return 1;
}

int DoubleQueue::empty(void)
{
	return list.empty();
}

Queue * Queue::create(void)
{
	return new DoubleQueue();
}
