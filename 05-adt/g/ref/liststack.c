#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "liststack.h"

void * stack_create(void)
{
	struct liststack *ls;

	ls = (struct liststack *)malloc(sizeof(*ls));

	if (ls)
		ls->head = NULL;

	return ls;
}

int stack_push(void *stack, char c)
{
	struct liststack *ls = (struct liststack *)stack;
	struct node *p;

	if ((p = malloc(sizeof(*p))) == NULL)
		return 0;

	p->c = c;
	p->next = ls->head;
	ls->head = p;

	return 1;
}

int stack_pop(void *stack, char *c)
{
	struct liststack *ls = (struct liststack *)stack;
	struct node *p;

	if (ls->head == NULL)
		return 0;

	*c = ls->head->c;

	p = ls->head;
	ls->head = ls->head->next;

	free(p);

	return 1;
}

int stack_empty(void *stack)
{
	struct liststack *ls = (struct liststack *)stack;

	return (ls->head == NULL);
}

void stack_free(void *stack)
{
	struct liststack *ls = (struct liststack *)stack;
	char c;

	while (stack_pop(ls, &c))
		;

	free(ls);
}


