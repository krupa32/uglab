#include "simplestack.h"

SimpleStack::SimpleStack()
{
	top = 0;
}

int SimpleStack::push(char c)
{
	if (top == MAX_ELEMENTS)
		return -1;

	arr[top++] = c;
}

int SimpleStack::pop(char *c)
{
	if (top == 0)
		return -1;

	--top;

	*c = arr[top];
}

int SimpleStack::empty(void)
{
	return (top == 0);
}
