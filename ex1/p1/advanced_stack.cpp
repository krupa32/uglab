#include "advanced_stack.h"

int advanced_stack::size(void)
{
	return top+1;
}

int advanced_stack::equals(advanced_stack *s2)
{
	int i;

	if (top != s2->top)
		return 0;

	for (i = 0; i <= top; i++) {
		if (data[i] != s2->data[i])
			return 0;
	}

	return 1;
}

advanced_stack *advanced_stack::clone(void)
{
	int i;
	advanced_stack *c = new advanced_stack(max_siz);

	c->top = top;
	for (i = 0; i <= top; i++)
		c->data[i] = data[i];

	return c;
}

advanced_stack *advanced_stack::create_palindrome(void)
{
	int i;
	advanced_stack *p = clone();

	for (i = top; i >= 0; i--)
		p->push(p->data[i]);

	return p;
}
