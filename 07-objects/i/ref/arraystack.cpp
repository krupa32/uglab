#include "arraystack.h"

ArrayStack::ArrayStack()
{
	top = 0;
}

int ArrayStack::push(char c)
{
	if (top == MAX_ELEMENTS)
		return -1;

	arr[top++] = c;
}

int ArrayStack::pop(char *c)
{
	if (top == 0)
		return -1;

	--top;

	*c = arr[top];
}

int ArrayStack::empty(void)
{
	return (top == 0);
}

Stack * Stack::create(void)
{
	return new ArrayStack();
}
