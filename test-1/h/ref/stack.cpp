#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack::Stack()
{
}

void Stack::push(int val)
{
	struct Node *p;

	p = (struct Node *)malloc(sizeof(*p));
	p->val = val;
	p->next = NULL;

	list.add_head(p);
}

int Stack::pop(void)
{
	struct Node *p;

	p = list.remove_head();

	return (p) ? p->val : -1 ;
}

int Stack::empty(void)
{
	return (list.get_head() == NULL);
}

Stack *Stack::duplicate(void)
{
	Stack *s1, *s2;
	int val;

	s1 = new Stack();
	s2 = new Stack();

	while ((val = pop()) != -1) {
		s1->push(val);
	}

	while ((val = s1->pop()) != -1) {
		push(val);
		s2->push(val);
	}

	delete s1;

	return s2;
}

Stack *Stack::reverse(void)
{
	Stack *s1, *s2;
	int val;

	s1 = new Stack();
	s2 = new Stack();

	while ((val = pop()) != -1) {
		s1->push(val);
		s2->push(val);
	}

	while ((val = s1->pop()) != -1) {
		push(val);
	}

	delete s1;

	return s2;
}


