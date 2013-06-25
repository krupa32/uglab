#include <stdlib.h>
#include "stack.h"

stack::stack(int max)
{
	data = (int *)malloc(max * sizeof(int));
	max_siz = max;
	top = -1;
}

stack::~stack()
{
	free(data);
}

int stack::push(int n)
{
	if ((top + 1) == max_siz)
		return -1;

	data[++top] = n;
}

int stack::pop(void)
{
	if (top == -1)
		return -1;

	return data[top--];
}


