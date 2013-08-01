#include "stack.h"
#include "arraystack.h"

void * stack_create(void)
{
	struct arraystack *as;

	as = (struct arraystack *)malloc(sizeof(*as));

	if (as)
		as->top = 0;

	return as;
}

void stack_free(void *stack)
{
	free(stack);
}

int stack_push(void *stack, char c)
{
	struct arraystack *as = (struct arraystack *)stack;

	if (as->top == STACK_MAX_SIZE)
		return 0;

	as->arr[as->top] = c;
	as->top++;

	return 1;
}

int stack_pop(void *stack, char *c)
{
	struct arraystack *as = (struct arraystack *)stack;

	if (as->top == 0)
		return 0;

	as->top--;
	*c = as->arr[as->top];

	return 1;
}

int stack_empty(void *stack)
{
	struct arraystack *as = (struct arraystack *)stack;

	return (as->top == 0);
}


