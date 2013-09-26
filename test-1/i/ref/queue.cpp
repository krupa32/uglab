#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue::Queue()
{
}

void Queue::add(int val)
{
	struct Node *n;

	n = (struct Node *)malloc(sizeof(*n));
	n->next = NULL;
	n->val = val;

	list.add_tail(n);
}

int Queue::remove(void)
{
	int val = -1;
	struct Node *p;

	p = list.remove_head();

	if (p) {
		val = p->val;
		free(p);
	}

	return val;
}

int Queue::empty(void)
{
	return (list.get_tail() == NULL);
}

Queue *Queue::duplicate(void)
{
	Queue *q1, *q2;
	int val;

	q1 = new Queue();
	q2 = new Queue();

	while ((val = remove()) != -1) {
		q1->add(val);
	}

	while ((val = q1->remove()) != -1) {
		add(val);
		q2->add(val);
	}

	delete q1;

	return q2;

}

int Queue::remove_lowest(void)
{
	Queue *q1;
	int lowest, val;

	q1 = new Queue();

	if ((lowest = remove()) != -1)
		q1->add(lowest);
	
	while ((val = remove()) != -1) {
		q1->add(val);
		if (val < lowest)
			lowest = val;
	}

	while ((val = q1->remove()) != -1) {
		if (val != lowest)
			add(val);
	}

	delete q1;

	return lowest;
}
